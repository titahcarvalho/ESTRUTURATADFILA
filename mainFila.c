// Created by Angelica on 14/08/2024.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fila.h"
#include "FilaPrioridade.h"

int main() {
    int escolha = 0;
    TProduto x,y;
    TFila F1;
    FFVazia(&F1);

    while(escolha != 5 ){
        printf("\n|| MENU ||\n");
        printf("|1| Enfileirar produtos:\n");
        printf("|2| Pesquisar um produto:\n");
        printf("|3| Imprimir produtos.\n");
        printf("|4| Solicitar atendimento.\n");
        printf("|5| Sair.\n");
        printf("Escolha uma das acoes:");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                LerProdutoFila(&x);
                Enfileirar(x, &F1);
            break;

            case 2:
                printf("\nDigite o codigo para pesquisar um produto especifico:");
                scanf("%d", &y.codigo);
            int p = PesquisarFila(&F1, &y);

            if (p) {
                printf("\nProduto %d encontrado!", y.codigo);
                printf("\nNome: %s", y.nome);
                printf("\nDescricao: %s", y.descricao);
                printf("\nQuantidade: %d", y.quantidade);
                printf("\nValor: $%.2f", y.preco);
            }
            printf("Produto %d nao encontrado.", y.codigo);

            break;

            case 3:
                printf("\n----------------------- Produtos em Fila:-----------------------");
                ImprimirFila(&F1);
            break;
            case 4:
                TFila F2;
                char z;
                TItem item;//não esqueça desse detalhe aqui
                printf("Atendimento solicitado");
                printf("\n");
                printf(" DIGITE CONFORME A PRIORIDADE.\n A - BAIXA \n B/C - MEDIA \n D - MEDIA: ");
                scanf(" %c",&z);
                if(z == 'A') {
                    item.prioridade = 1;
                } else if (z == 'B' || p == 'C') {
                    item.prioridade = 3;
                } else if (z == 'D') {
                    item.prioridade = 2;
                } else {
                    printf("Prioridade Invalida.");
                }
                    EnfileirarPrioridade(&F2,item);
            break;
            case 5:

                printf("\nEncerrando...aperta no enter para fechar a Tela");
            LiberarFila(&F1);
            break;

            default:
                printf("\nOpcao invalida. Tente novamente.");
            break;
        }
    }

    return 0;
}

