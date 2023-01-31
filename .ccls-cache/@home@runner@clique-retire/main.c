#include <stdio.h>
#include <stdlib.h>

#define MAX_PRODUTOS 100

int main() {
    int opcao, continuar = 1;
    int estoque[MAX_PRODUTOS];
    int quantidade;
    int idProduto;

    // Inicializando o estoque com quantidades iniciais
    for (int i = 0; i < MAX_PRODUTOS; i++) {
        estoque[i] = 10;
    }

    while (continuar) {
        printf("Digite 1 para continuar e 0 para sair: ");
        scanf("%d", &continuar);

        if (continuar) {
            printf("Escolha uma das opções abaixo:\n");
            printf("1 - Retirar produto\n");
            printf("2 - Devolver produto\n");
            printf("3 - Ver estoque\n");
            printf("0 - Sair\n");

            scanf("%d", &opcao);

            if (opcao == 0) {
                continuar = 0;
            } else {
                switch (opcao) {
                    case 1:
                        printf("Digite o ID do produto: ");
                        scanf("%d", &idProduto);

                        printf("Digite a quantidade: ");
                        scanf("%d", &quantidade);

                        if (estoque[idProduto] < quantidade) {
                            printf("Não há estoque suficiente!\n");
                        } else {
                            estoque[idProduto] -= quantidade;
                            printf("Produto retirado com sucesso!\n");
                        }
                        break;
                    case 2:
                        printf("Digite o ID do produto: ");
                        scanf("%d", &idProduto);

                        printf("Digite a quantidade: ");
                        scanf("%d", &quantidade);

                        estoque[idProduto] += quantidade;
                        printf("Produto devolvido com sucesso!\n");
                        break;
                    case 3:
                        printf("Estoque:\n");
                        for (int i = 0; i < MAX_PRODUTOS; i++) {
                            printf("Produto %d: %d unidades\n", i, estoque[i]);
                        }
                        break;
                    default:
                        printf("Opção inválida!\n");
                        break;
                }
            }
        }
    }

    return 0;
}
