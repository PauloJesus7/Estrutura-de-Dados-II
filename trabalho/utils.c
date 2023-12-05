/*
Grupo 1
    Lucas Raniere Neves Silva
    Matheus Marcarini Couto
    Paulo Roberto de Jesus Gonçalves
*/

#include "utils.h"


void calcularLPS(char *padrao, int m, int lps[]) {
    int len = 0; // Comprimento do prefixo atual
    int i = 1;

    lps[0] = 0; // O primeiro caractere sempre tem LPS igual a zero

    while (i < m) {
        if (padrao[i] == padrao[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

int buscarKMP(char *texto,int lps[], char *padrao, int *pos, int offsetPos, int *ocorrencias, int *posicoes, int *auxPosicoes) {

    int m = strlen(padrao);
    int n = strlen(texto);


    int posinicial = *pos;
    int i = *pos; // Índice para o texto
    int j = 0; // Índice para o padrão
    int deslocamento = 0;
    while (i < n) {
        if(texto[i] == '\n') {
            i++;
        }
        if (texto[i] == '>') {
            //Retorna a posicao em que acabou um padrão para que a próxima leitura
            //do arquivo parta dessa posicao
            *pos = i;
            return LEITURA_PADRAO_COMPLETA;
        }

        if (padrao[j] == texto[i]) {
            i++;
            j++;
        }
        
        if (j == m) {
            (*ocorrencias)+=1;
            deslocamento = i-posinicial;
            posicoes[*auxPosicoes] = deslocamento - j + offsetPos - (deslocamento - j + offsetPos)/69;
            (*auxPosicoes)+=1;
            j = lps[j - 1];
            
        } else if (i < n && padrao[j] != texto[i] && texto[i] != '\n') {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
        
        
        
    }
    *pos = i;
    return LEITURA_PADRAO_INCOMPLETA;
}

int lerPadraoVirus(FILE *arquivoVirus, char *padrao, char *nomeVirus) {
    fseek(arquivoVirus, 1, SEEK_CUR);
    fgets(nomeVirus, sizeof(char) * 35, arquivoVirus);
    if (strcmp(nomeVirus, "EOF") == 0) {
        return FIM_DE_ARQUIVO_VIRUS;
    }
    fgets(padrao, sizeof(char) * 75, arquivoVirus);
    padrao[strlen(padrao)-1] = '\0';
    return LEITURA_VIRUS_SUCESSO;
}
  

int lerProximos(char *buffer, FILE *arquivo) {
    int lido = fread(buffer, sizeof(char), TAMANHO_BUFFER-1, arquivo);
    
    buffer[lido] = '\0';
    return lido;
}   

int copiaNome(char *buffer, char *nomeDest, int pos, FILE *arquivoDna, int *tamanho) {
    int contadorDest = 0;

    if (buffer[pos] == '\0') {
        *tamanho = lerProximos(buffer, arquivoDna);
        pos = 0;
    }

    while (buffer[pos] != '\n') {
        nomeDest[contadorDest] = buffer[pos];
        pos++;
        contadorDest++;
        nomeDest[contadorDest] = '\0';
        if (buffer[pos] == '\0') {
            if (strcmp(nomeDest, "EOF") == 0) {
                return pos;
            }
            *tamanho = lerProximos(buffer, arquivoDna);
            pos = 0;
        }
    }
    nomeDest[contadorDest] = '\0';
    pos++;
    return pos;
}