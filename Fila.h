// Created by Angelica on 14/08/2024.
#ifndef TESTE_FILA_H
#define TESTE_FILA_H

typedef struct item {
    int codigo;
    char nome[100];
    char descricao[100];
    float preco;
    int quantidade;
}TProduto;

typedef struct celula {
    TProduto item;
    struct celula* prox;
}TCelula;

typedef struct fila {
    TCelula* frente;
    TCelula* tras;
    int tamanho;
}TFila;

void FFVazia(TFila *Fila);
int Vazia(TFila Fila);
void Enfileirar(TProduto x, TFila *Fila);
void Desenfileirar(TFila *Fila, TProduto *Item);
int PesquisarFila(TFila *Fila, TProduto *Item);
void LerProdutoFila(TProduto *Item);
void ImprimirProdutoFila(TProduto Item);
void ImprimirFila(TFila *Fila);


#endif //TESTE_FILA_H
