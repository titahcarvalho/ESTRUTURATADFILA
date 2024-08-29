// Created by Angélica on 26/08/2024.
#ifndef FILAPRIORIDADE_H
#define FILAPRIORIDADE_H
#include "Fila.h"

typedef struct {
    int prioridade;
    int codigo;
    char nome[100];
    char descricao[100];
    float preco;
    int quantidade;
}TItem;

typedef struct{
    TItem ordem;
    struct celula* prox;
}TPrioridade;

typedef struct {
    TFila* alta;
    TFila* media;
    TFila* baixa;

}FilaPrioridade;

void EnfileirarPrioridade(FilaPrioridade *fila, TItem x);
void DesenfileirarPrioridade(FilaPrioridade *fila, TItem x);
void FilaUnica(FilaPrioridade Fila, TFila *Unica);

#endif //FILAPRIORIDADE_H
