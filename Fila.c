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
int PesquisarFila(TFila *Fila, TProduto *Item) {
    TFila FAux;
    FFVazia(&FAux);
    TProduto x;
    int flag = 0;
    while(!Vazia(*Fila)){
        Desenfileirar(Fila, &x);
        if(!strcmp(x.nome, Item->nome)){
        flag = 1;
        *Item = x;
        }
        Enfileirar(x,&FAux);
    }
    while(!Vazia(FAux)){
        Desenfileirar(&FAux, &x);
        Enfileirar(x,Fila);
    }
        if(flag == 0){
        Item->codigo = -1;
    }
        return flag;
}

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
void LiberarFila(TFila *Fila)  {
        TProduto x;
        while(!Vazia(*Fila)){
            Desenfileirar(Fila, &Fila->frente->prox->item);
        }
        free(Fila->frente);
        Fila->frente = NULL;
}
int CompararFila(TFila x, TFila y) {
    int flag = 1;
    TFila *Aux1, *Aux2;
    Aux1 = x.frente->prox;
    Aux2 = y.frente->prox;
    if((x.tamanho - y.tamanho)!= 0){ //aqui compara se o tamanho das duas filas são iguais, se for retorna 0
    return 0;
    }
    while(Aux1 != NULL) {
        if(strcmp(Aux1->item.nome, Aux2->item.nome) == 0) {
            Aux1 = Aux1->prox;
            Aux2 = Aux2->prox;

        } else {
            Aux1 = Aux1->prox;
            Aux2 = Aux2->prox;
            flag = 0;
        }
    }
    return flag;
}

