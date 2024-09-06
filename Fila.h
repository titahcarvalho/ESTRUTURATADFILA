// Created by Angelica on 14/08/2024.
#ifndef TESTE_FILA_H
#define TESTE_FILA_H

typedef struct item {
    int codigo;
    char nome[100];
    char descricao[100];
    float preco;
    int quantidade;
    char binario[32];
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
void LiberarFila(TFila *Fila);
int CompararFila(TFila *F1, TFila *F2);
void DiferencaFila(TFila F1, TFila F2, TFila F3);
void IntersecaoFila(TFila F1, TFila F2, TFila F3);
void GerarBinarios(TFila *Fila, int n);


#endif //TESTE_FILA_H
