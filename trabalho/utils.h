#ifndef _UTILS_H_
#define _UTILS_H_

#define TAMANHO_BUFFER 50000 //O tamanho desse buffer deve ser maior que o maior padrão de virus
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
enum {
    LEITURA_PADRAO_COMPLETA,
    LEITURA_PADRAO_INCOMPLETA,
    FIM_DE_ARQUIVO_VIRUS,
    LEITURA_VIRUS_SUCESSO,
    RES_DEFAULT
};

/**
 * Lê o padrão de vírus a partir do arquivo de vírus.
 *
 * @param arquivoVirus Arquivo contendo os padrões de vírus.
 * @param padrao       Onde o padrão de vírus será armazenado.
 * @param nomeVirus    O nome do vírus correspondente ao padrão.
 * @return             Um indicador do status da leitura do padrão: sucesso ou fim de arquivo.
 */
int lerPadraoVirus(FILE *arquivoVirus, char *padrao, char *nomeVirus);

/**
 * Realiza a busca de padrões em um texto utilizando o algoritmo KMP.
 *
 * @param texto       O texto onde a busca será realizada.
 * @param lps         O vetor LPS previamente calculado para o padrão.
 * @param padrao      O padrão a ser buscado no texto.
 * @param offsetPos   A posição de deslocamento no texto.
 * @param ocorrencias Ponteiro para retornar número de ocorrências do padrão encontrado.
 * @param posicoes    Vetor para guardar as posições onde o padrão foi encontrado.
 * @param auxPosicoes O número de posições encontradas.
 * @return            Um indicador de leitura do padrão: completa ou incompleta.
 */
int buscarKMP(char *texto,int lps[], char *padrao, int *pos, int offsetPos, int *ocorrencias, int *posicoes, int *auxPosicoes);

/**
 * Calcula o vetor LPS (Longest Proper Prefix which is also Suffix) para um padrão.
 *
 * @param padrao O padrão para o qual o LPS será calculado.
 * @param m      O tamanho do padrão.
 * @param lps    Vetor para armazenar os valores de LPS.
 */
void calcularLPS(char *padrao, int m, int lps[]);

/**
 * Lê caracteres do arquivo até atingir o tamanho máximo definido para o buffer.
 * Os caracteres lidos são armazenados em um buffer e o número
 * total de caracteres lidos é retornado.
 *
 * @param buffer  Ponteiro para o buffer onde os caracteres serão armazenados.
 * @param arquivo Ponteiro para o arquivo a ser lido.
 * @return O número total de caracteres lidos.
 */
int lerProximos(char *buffer, FILE *arquivo);

/**
 * Lê caracteres do arquivo até atingir o tamanho máximo definido para o buffer.
 * Os caracteres lidos são armazenados em um buffer e o número
 * total de caracteres lidos é retornado.
 *
 * @param buffer  Ponteiro para o buffer onde os caracteres serão armazenados.
 * @param nomeDest Ponteiro para onde o nome será escrito.
 * @param pos Posicao atual de leitura do buffer
 * @param arquivoDna Ponteiro para o arquivo DNA
 * @param tamanho Ponteiro para a variável qe controla o tamanho do buffer
 * @return O número total de caracteres lidos.
 */
int copiaNome(char *buffer, char *nomeDest, int pos, FILE *arquivoDna, int *tamanho);

#endif