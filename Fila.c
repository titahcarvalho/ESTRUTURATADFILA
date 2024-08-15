// Created by Angelica on 14/08/2024.
#include "Fila.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

void FFVazia(TFila *Fila) {
    Fila->frente = (TCelula*)malloc(sizeof(TCelula));
    Fila->tras = Fila->frente;
    Fila->frente->prox = NULL;
    Fila->tamanho = 0;
}
int Vazia(TFila Fila) {
    return (Fila.frente == Fila.tras);
}
void Enfileirar(TProduto x, TFila *Fila) {
    Fila->tras->prox = (TCelula*)malloc(sizeof(TCelula));
    Fila->tras = Fila->tras->prox;
    Fila->tras->item = x;
    Fila->tras->prox = NULL;
    Fila->tamanho++;
}
void Desenfileirar(TFila *Fila, TProduto *Item) {
    TCelula* Aux;
    if(!Vazia(*Fila)) {  //se a fila estiver cheia, diferente de vazia
        Aux = Fila->frente->prox;  //aux irá receber o primeiro da fila
        Fila->frente->prox = Aux->prox;
        *Item = Aux->item;
        free(Aux);
        if(Fila->frente->prox == NULL) {
            Fila->tras = Fila->frente;
            Fila->tamanho--;
        }
    }
}
void LerProdutoFila(TProduto *Item) {
    printf("\n Nome do produto:");
    fflush(stdin);
    fgets(Item->nome, 100, stdin);
    printf("\n Codigo do produto:");
    scanf("%d", &Item->codigo);
    getchar();
    printf("\n Descricao do produto:");
    fgets(Item->descricao, 100, stdin);
    printf("\n Quantidade do produto:");
    scanf("%d", &Item->quantidade);
    getchar();
    printf("\n Preco do produto:");
    scanf("%f", &Item->preco);
    getchar();

}
void ImprimirProdutoFila(TProduto Item) {
    printf("\n Nome do produto:%s", Item.nome);
    printf("\n Codigo do produto:%d", Item.codigo);
    printf("\n Descricao do produto:%s", Item.descricao);
    printf("\n Quantidade do produto:%d", Item.quantidade);
    printf("\n Preco do produto:%2.f", Item.preco);
}
/*int PesquisarFila(TFila *Fila, TProduto *Item) {
    TProduto x;
    TFila Faux; FFVazia(&Faux);
    int n = Fila->tamanho;
    bool seencontrar = false;
    for(int i = 0; i < n; i++){
        Desenfileirar(Fila, &x);
        if(strcmp(x.nome, Item->nome) == 0) {
            ImprimirProdutoFila(&Faux,&x);
            *Item = x;
            Enfileirar(x,Faux);
            seencontrar = true; // return true;
        }    for(int i = 0; i > n; i++){
                Desenfileirar(&Faux, &x);
                Enfileirar(x,Fila);
        }
    }
}*/
void ImprimirFila(TFila *Fila) {
    TProduto x;
    TFila Faux; FFVazia(&Faux);
    int n = Fila->tamanho;
    for(int i = 0; i<n; i++) {
        Desenfileirar(Fila, &x);
        ImprimirProdutoFila(x); //ainda faltaq fazer essa função
        Enfileirar(x,&Faux); //& por ser fila
        while(!Vazia(Faux)) {
            Desenfileirar(&Faux, &x);
            Enfileirar(x, Fila); //não precisa de & por ser ponteiro, referencia
        }  free(Faux.frente);
    }
}
