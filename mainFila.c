// Created by Angelica on 14/08/2024.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Fila.h"

int main() {
    int escolha = 0;
    TProduto x,y;
    TFila F1;
    FFVazia(&F1);

       while(escolha != 4 ){
            printf("\n|| MENU ||\n");
            printf("|1| Enfileirar produtos:\n");
            printf("|2| Pesquisar um produto.\n");
            printf("|3| Imprimir produtos.\n");
            printf("|4| Sair.\n");
            printf("Escolha uma das acoes:");
            scanf("%d", &escolha);

            switch (escolha) {
                case 1:
                        LerProdutoFila(&x);
                        Enfileirar(x, &F1);
                    break;

                case 2:
                   /* printf("\nDigite o codigo para pesquisar um produto especifico:");
                    scanf("%d", &y.codigo);
                    PesquisarFila(F1, y);

                    if (x != NULL) {
                        printf("\nProduto %d encontrado!", x->prox->item.codigo);
                        printf("\nNome: %s", x->prox->item.nome);
                        printf("\nDescricao: %s", x->prox->item.descricao);
                        printf("\nQuantidade: %d", x->prox->item.quantidade);
                        printf("\nValor: $%.2f", x->prox->item.preco);
                    } else {
                        printf("Produto %d nao encontrado.", y.codigo);
                    }*/
                    break;

                case 3:
                    printf("\n----------------------- Produtos em Fila:-----------------------");
                    ImprimirFila(&F1);
                    break;
                case 4:

                    printf("\nEncerrando...aperta no enter para fechar a Tela");
                    break;

                default:
                    printf("\nOpcao invalida. Tente novamente.");
                    break;
        }
    }

    return 0;
}

