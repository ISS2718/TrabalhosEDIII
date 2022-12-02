#ifndef __ARVORE_B_C__
#define __ARVORE_B_C__

#include <stdlib.h>
#include "arquivoBin.h"
#include "arquivoCsv.h"
#include "mensagens.h"
#include "cabecalhoArvB.h"
#include "noArvB.h"

/**
 * Tamanho da pagina de disco do arquivo da arvore-B.
 */
#define TAM_PAGINA_DISCO_ARV_B 65

//=====================================================================

/**
 * Grava registro de cabecalho no arquivo da arvore-B.
 * 
 * @param arquivoArvB Ponteiro para arquivo da arcore-B.
 * @param cabecalho Ponteiro para cabecalho a ser 
 * escrito no aquivo da arvore-B.  
 */
void escreverCabecalhoArquivoAvrB(FILE* arquivoArvB, CabecalhoArvB* cabecalho); 

/**
 * Escreve noh no arquivo da arvore-B.
 * 
 * @param arquivoArvB Ponteiro para arquivo da arcore-B.
 * @param cabecalho Ponteiro para cabecalho a ser 
 * escrito no aquivo da arvore-B. 
 * @param no Ponteiro para no a ser 
 * escrito no arquivo da arvore-B.
 */
void escreveNoArvB(FILE* arquivoArvB,  CabecalhoArvB* cabecalho, NoArvB* no);

/**
 * Le registro de cabecalho do arquivo da arvore-B.
 * 
 * @param arquivoArvB Nome do arquivo.
 */
CabecalhoArvB* lecabecalhoArvB(FILE* arquivoArvB);

/**
 * Le registro de dados do arquivo da arvore-B por RRN.
 * 
 * @param arquivoArvB Nome do arquivo.
 * @param RRN Numero Relativo do Registro.
 * 
 * @return Retorna um ponteiro para o dado do RRN.
 */ 
NoArvB* leNoArvB_RRN(FILE* arquivoArvB, int RRN);


/**
 * Busca uma chave na arvore B.
 * 
 * @param arq_indice Arquivo de indice (Arvore B) .bin.
 * @param raiz Noh raiz da Arvore B.
 * @param chave Chave a ser buscada na Arvore B.
 * @param RRN_resultado RRN do dado encontrado no arquivo de dados.
 * 
 * @return retorna numero de paginas de disco acessadas na busca
 * sem contar o cabecalho, já contando o noh raiz. Ou retorna -1 
 * caso de erro.
 */
int buscaChaveArvoreB(FILE* arquivoArvB, NoArvB *raiz, int chave, int *RRN_resultado);

/**
 * Escreve um no da arvore B no arquivo de indice binario.
 * 
 * @param arq_indice Arquivo de indice (Arvore B) .bin.
 * @param cabecalho Cabecalho do arquivo de indice.
 * @param raiz Noh raiz da Arvore B.
 */
void escreveNoArqIndice(FILE* arqIndice,CabecalhoArvB* cabecalho ,NoArvB* no, int rrn);

/**
 * Escreve o cabecalho da arvore B no arquivo de indice binario.
 * 
 * @param arq_indice Arquivo de indice (Arvore B) .bin.
 * @param cabecalho Cabecalho do arquivo de indice.
 */
void escreveCabecalhoArqIndice(FILE* arqIndice,CabecalhoArvB* cabecalho);

/**
 * Insere um no na arvore B. Caso nao seja a situacao inicial realiza
 * a subrotina de insercao recursiva. E quando necessario tambem realiza 
 * o split da raiz. 
 * 
 * @param arq_indice Arquivo de indice (Arvore B) .bin.
 * @param Cn Chave a ser insereida.
 * @param PRn RRN do arquivo de daodos do dado que possui 
 * a chave a ser inserida.
 * @param raiz Noh raiz da Arvore B.
 * @param cabecalho Cabecalho do arquivo de indice.
 */
int insercaoArvoreB(FILE* arqIndice, int Cn, int PRn, NoArvB* raiz, CabecalhoArvB* cabecalho);

/**
 * Imprime a arvore ordenada (para debug).
 * 
 * @param arq_indice Arquivo de indice (Arvore B) .bin.
 * @param rrn RRN do noh raiz. Ou primeiro noh a ser impresso.
 */
void imprimeOrdenado(FILE * arq_indice, int rrn);

#endif