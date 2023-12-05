
#include "utils.h"
#include <unistd.h>






int main() {
    // Nome do arquivo a ser lido
    char nomeArquivoVirus[] = "PadroesVirus.txt";
    char nomeArquivoDNAs[] = "BaseDadosDNA.txt";
    // Abra o arquivo para leitura
    FILE *arquivoVirus = fopen(nomeArquivoVirus, "r");
    FILE *arquivoDNAs = fopen(nomeArquivoDNAs, "r");
    
    // Verifique se o arquivo foi aberto com sucesso
    
    if (arquivoVirus == NULL || arquivoDNAs == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

 
    char buffer[TAMANHO_BUFFER];
    char nomeDna[35];

    char padrao[75];
    char nomeVirus[35];

    int offset = 0;
    int ocorrencias = 0;
    int posicoes[100];
    int auxPosicoes = 0;
    int pos = 0;
    //tamanho do Buffer lido
    int tamanho = lerProximos(buffer, arquivoDNAs);
    int res;
    int cont = 0;
    int lps[70];
    while(lerPadraoVirus(arquivoVirus, padrao, nomeVirus) != FIM_DE_ARQUIVO_VIRUS) {
        //Copia o nome do padrão que esta lendo atualmente
        pos++;
        pos = copiaNome(buffer, nomeDna, pos, arquivoDNAs, &tamanho);
        //o tamanho é usado para o offset da busca então deve ser o tamanho do buffer desde o inicio
        //do padrão
        tamanho=tamanho-pos;
        calcularLPS(padrao, strlen(padrao), lps);
        printf("%s", nomeVirus);
        while (strcmp(nomeDna, "EOF") != 0) {
            
            res = buscarKMP(buffer,lps, padrao, &pos, offset, &ocorrencias, posicoes, &auxPosicoes);

            if (res == LEITURA_PADRAO_COMPLETA) {
                
                //tira o \n do nome
                if (ocorrencias != 0) {
                    printf("[%s] no. de ocorrencias: %d posicoes: ", nomeDna, ocorrencias);
                    for (int i = 0; i < auxPosicoes; i++) {
                        printf("%d ", posicoes[i]);
                    }
                    printf("\n");
                }
                
                auxPosicoes = 0;
                ocorrencias = 0;
                
                pos++;
                
                pos = copiaNome(buffer, nomeDna, pos, arquivoDNAs, &tamanho);

                offset = 0;
                tamanho = tamanho-pos;
            
            } else if (res == LEITURA_PADRAO_INCOMPLETA) {
               
                int deslocamento = (strlen(padrao))*-1 +1 ;
              
                offset += deslocamento + tamanho;
                
                fseek(arquivoDNAs, deslocamento, SEEK_CUR);
                
                tamanho = lerProximos(buffer, arquivoDNAs);
                
                pos = 0;
            } 

        }
        
        fseek(arquivoDNAs, 0, SEEK_SET);
        tamanho = lerProximos(buffer, arquivoDNAs);
        pos = 0;    
        printf("\n");
    }

    fclose(arquivoDNAs);
    fclose(arquivoVirus);
    return 0;
}
