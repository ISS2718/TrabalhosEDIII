#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/arvoreB.h"
#include "../headers/arquivoBin.h"
#include "../headers/funcionalidades.h"
#include "../headers/funcoesFornecidas.h"

int main(int argC, char *argV[]){
    int opcao;
    char * nome_arquivo = malloc(sizeof(char)*20);
    
    scanf("%d %s", &opcao, nome_arquivo);
    
    //Create table (1) - Isaac e Nicholas
    //le do csv
    if(opcao == 1) {
        funcionalidade1CreateTable(nome_arquivo);
    }
    
    //Select (2) - Nicholas
    // mostra tudo (so le do binario)
    if(opcao == 2){
        funcionalidade2Select(nome_arquivo);
    }    

    //Select where (3) - Isaac
    //le comando da tela
    if(opcao == 3){
        funcionalidade3SelectWhere(nome_arquivo);
    }

    //Remocao logica (4) - Isaac
    //le comando da tela
    if(opcao == 4){
        funcionalidade4Remove(nome_arquivo);
    }

    //Insercao (5) - Nicholas
    //insere no binario
    //le da tela
    if(opcao == 5) {
        funcionalidade5Insert(nome_arquivo);
    }

    //Compactacao (6) - Nicholas
    //cria outro binario
    if(opcao == 6){
        funcionalidade6Compactacao(nome_arquivo);
    }

    if(opcao == 7){
        FILE *arquivoArvB = abrirEscrita_ArvB(nome_arquivo);

        cabecalhoArvB *cabecalho;
        alocaCabecalhoArvB(&cabecalho);

        noArvB *no;
        alocaNoArvB(&no, 1);

        
        insereChaveOrdenadaNoArvB(no, 1, 2);
        escreveNoArvB(arquivoArvB, no);

        *(cabecalho->RRNproxNo) = *(cabecalho->RRNproxNo) + 1;
        *(no->RRNdoNo) = *(cabecalho->RRNproxNo);
        insereChaveOrdenadaNoArvB(no, 4, 0);
        escreveNoArvB(arquivoArvB, no);

        *(cabecalho->RRNproxNo) = *(cabecalho->RRNproxNo) + 1;
        *(no->RRNdoNo) = *(cabecalho->RRNproxNo);
        insereChaveOrdenadaNoArvB(no, 0, 5);
        escreveNoArvB(arquivoArvB, no);

        escreverCabecalhoArquivoAvrB(arquivoArvB, cabecalho);

        desalocaCabecalhoArvB(cabecalho);
        desalocaNoArvB(&no, 1);
        fecharArquivo_ArvB(arquivoArvB);
    }

    free(nome_arquivo);

    return 0;
}   

