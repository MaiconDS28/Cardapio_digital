#include <stdio.h>

int main() {
    int op, categoria, quant;
    float total = 0;
    float preco;
    float desc = 0;
    char continuar;

    do {
        printf("\n=== CARDÁPIO DIGITAL ===\n");
        printf("1 - Pratos\n");
        printf("2 - Bebidas\n");
        printf("3 - Sobremesas\n");
        printf("4 - Finalizar pedido\n");
        printf("Escolha uma categoria: ");
        scanf("%d", &categoria);

        switch (categoria) {
            case 1:
                printf("\n--- Pratos ---\n");
                printf("1 - Feijoada (R$25.00)\n");
                printf("2 - Lasanha (R$22.00)\n");
                printf("Escolha uma opção: ");
                scanf("%d", &op);

                if (op == 1) preco = 25.00;
                else if (op == 2) preco = 22.00;
                else {
                    printf("Opcao invalida!\n");
                    break;
                }
                printf("Quantidade: ");
                scanf("%d", &quant);
                total += preco * quant;
                break;

            case 2:
                printf("\n--- Bebidas ---\n");
                printf("1 - Suco (R$6.00)\n");
                printf("2 - Refrigerante (R$5.00)\n");
                printf("Escolha uma opção: ");
                scanf("%d", &op);

                if (op == 1) preco = 6.00;
                else if (op == 2) preco = 5.00;
                else {
                    printf("Opção invalida!\n");
                    break;
                }
                printf("Quantidade: ");
                scanf("%d", &quant);
                total += preco * quant;
                break;

            case 3:
                printf("\n--- Sobremesas ---\n");
                printf("1 - Pudim (R$8.00)\n");
                printf("2 - Sorvete (R$10.00)\n");
                printf("Escolha uma opção: ");
                scanf("%d", &op);

                if (op == 1) preco = 8.00;
                else if (op == 2) preco = 10.00;
                else {
                    printf("Opção invalida!\n");
                    break;
                }
                printf("Quantidade: ");
                scanf("%d", &quant);
                total += preco * quant;
                break;

            case 4:
                printf("\nFinalizando pedido...\n");
                break;

            default:
                printf("Categoria invalida!\n");
        }

        if (categoria != 4) {
            printf("Deseja adicionar mais itens? (s/n): ");
            scanf(" %c", &continuar);
        } else {
            continuar = 'n';
        }

    } while (continuar == 's');

    // Aplica desconto se for maior que R$50
    if (total >= 50) {
        desc = total * 0.1;
        total -= desc;
        printf("\nDesconto aplicado: R$%.2f\n", desc);
    }

    printf("\n=== RESUMO DO PEDIDO ===\n");
    printf("Total a pagar: R$%.2f\n", total);
    printf("Obrigado pela preferência!\n");

    return 0;
}
