// Created by Angelica on 14/08/2024.
#include "Fila.h"
#include "FilaPrioridade.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>


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
        if(!strcmp(x.nome, Item->nome)==0){
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
//QUESTÃO 1 ---------------------------------------------------------------------------------------------------------
void LiberarFila(TFila *Fila)  {
        TProduto x;
        while(!Vazia(*Fila)){
            Desenfileirar(Fila, &Fila->frente->prox->item);
        }
        free(Fila->frente);
        Fila->frente = NULL;
}
//QUESTÃO 2 ---------------------------------------------------------------------------------------------------------
/*int CompararFila(TFila *F1, TFila *F2) {
    int flag = 1;
    TFila *Aux1, *Aux2;
    TProduto tempAux1, tempAux2; //criação das variaveis temporárias
    Aux1 = F1->frente->prox;
    Aux2 = F2->frente->prox;
    if((F1->tamanho - F2->tamanho)!= 0){ //aqui compara se o tamanho das duas filas são iguais, se for retorna 0
        printf("A duas filas possuem o mesmo tamanho.");
    return 0;
    }
    while(Aux1 != NULL && Aux2 != NULL) {
        Desenfileirar(&F1, &tempAux1);//analisar essa aprte, DEVE Ser armazenado em variáveis temporarias
        Desenfileirar(&F2, &tempAux2);//analisar essa aprte
        while(strcmp(tempAux1.nome, tempAux2.nome)== 0){
            if(tempAux1.nome == tempAux1.nome) {
                printf("A duas filas possuem os mesmo elementos.");
            } else {
                printf("As filas não possuem os mesmos elementos.");
            }
            flag = 0;
        }
        Aux1 = Aux1->prox;
        Aux2 = Aux2->prox;

    }
    return flag;
}

//ANTES
/* int CompararFila(TFila F1, TFila F2) {
int flag = 1;
TFila *Aux1, *Aux2;
TFila tempAux1, tempAux2;
Aux1 = F1.frente->prox;
Aux2 = F2.frente->prox;
if((F1.tamanho - F2.tamanho)!= 0){ //aqui compara se o tamanho das duas filas são iguais, se for retorna 0
return 0;
}
while(Aux1 != NULL) {
Desenfileirar(Aux2, &tempAux1);//analisar essa aprte, DEVE Ser armazenado em variáveis temporarias
Desenfileirar(Aux1, &tempAux2);//analisar essa aprte
while(strcmp(tempAux1->item.nome, tempAux2->item.nome)== 0){
flag = 0;
}
free(F1->frente);
F1->frente = NULL;
}
return flag;
}*/

//QUESTÃO 3 ---------------------------------------------------------------------------------------------------------
/*void IntersecaoFila(TFila F1, TFila F2, TFila F3) {
    TFila tempFila2;
    TProduto Aux1, Aux2; //é isso mesmo?j
    FFVazia(&F3);

    while(!Vazia(F1)) {
        Desenfileirar(&F1, &Aux1);
        tempFila2 = F2;

        while(!Vazia(tempFila2)) {
            Desenfileirar(&tempFila2,&Aux2);

            if(Aux1.codigo == Aux2.codigo) {
                Enfileirar(&F3, &Aux1);
                return;
            }
        }
    }

}*/
//QUESTÃO 5 ---------------------------------------------------------------------------------------------------------
void EnfileirarPrioridade(FilaPrioridade *fila, TItem x) {
    TProduto produto;
    produto.codigo = x.codigo;
    strcpy(produto.nome, x.nome);
    strcpy(produto.descricao, x.descricao);
    produto.preco = x.preco;
    produto.quantidade = x.quantidade;

    if(x.prioridade == 3) {
        Enfileirar(produto, fila->alta);
    } else if (x.prioridade == 2) {
        Enfileirar(produto, fila->media);
    } else if (x.prioridade == 1){
        Enfileirar(produto, fila->baixa);
    }
}
void DesenfileirarPrioridade(FilaPrioridade *fila, TItem x) {
        if(!Vazia(*(fila->alta))) {
            Desenfileirar(&fila->alta, &x);
        } else if(!Vazia(*(fila->media))) {
            Desenfileirar(&fila->media, &x);
        } else if (!Vazia(*(fila->baixa))) {
            Desenfileirar(&fila->baixa, &x);
        } else {
            printf("Todas as filas estão vazias");
        }
    }
void FilaUnica(FilaPrioridade Fila, TFila *Unica) {
    TFila Aux1, Aux2, Aux3;
    TProduto x;
    while(!Vazia(Fila->alta)) {
        Desenfileirar(Fila->alta, &x);
        Enfileirar(x, Unica);
        Enfileirar(x, &Aux1);
    }
    while(!Vazia(Fila->media)) {
        Desenfileirar(Fila->media, &x);
        Enfileirar(x, Unica);
        Enfileirar(x, &Aux2);
    }
    while(!Vazia(Fila->baixa)) {
        Desenfileirar( Fila->baixa, &x);
        Enfileirar(x, Unica);
        Enfileirar(x, &Aux3);
    }
    while(!Vazia(Aux1)) {
        Desenfileirar(&Aux1, &x);
        Enfileirar(x, Fila->alta);
    }
    while(!Vazia(Aux2)) {
        Desenfileirar(&Aux2, &x);
        Enfileirar(x, Fila->media);
    }
    while(!Vazia(Aux3)) {
        Desenfileirar(&Aux3, &x);
        Enfileirar(x, Fila->baixa);
    }
    free(Aux1);
    free(Aux2);
    free(Aux3);

}
//QUESTÃO 6 ---------------------------------------------------------------------------------------------------------
void GerarBinarios(TFila *Fila, int n) {
    char binario[50];
    char binario2[50];

    if (Vazia(*Fila)) {
        Enfileirar(1, Fila);
    }

    for(int i = 0; i < n ;i++) {
        Desenfileirar(Fila, binario);

        strcpy(binario2, binario); //binario2 = binario;
        strcat(binario,"0");
        printf("%s\n", binario);

        strcpy(binario, binario2); //binario = binario2;
        strcat(binario, "1");
        printf("%s\n", binario);

        Enfileirar(binario2, Fila);
    }
}



