#include <stdio.h>  // Biblioteca padrão de entrada e saída (printf, scanf)

int main() {
    int op, categoria, quant;  // Variáveis para opção escolhida, categoria e quantidade
    float total = 0;           // Variável acumuladora do valor total do pedido
    float preco;               // Armazena o preço do item escolhido
    float desc = 0;            // Variável para armazenar valor do desconto (se houver)
    char continuar;            // Controla se o usuário deseja continuar pedindo

    do {
        // Menu principal do cardápio
        printf("\n=== CARDÁPIO DIGITAL ===\n");
        printf("1 - Pratos\n");
        printf("2 - Bebidas\n");
        printf("3 - Sobremesas\n");
        printf("4 - Finalizar pedido\n");
        printf("Escolha uma categoria: ");
        scanf("%d", &categoria);

        // Estrutura switch para tratar cada categoria
        switch (categoria) {
            case 1: // Categoria de pratos
                printf("\n--- Pratos ---\n");
                printf("1 - Feijoada (R$25.00)\n");
                printf("2 - Lasanha (R$22.00)\n");
                printf("Escolha uma opção: ");
                scanf("%d", &op);

                // Define preço conforme a opção escolhida
                if (op == 1) preco = 25.00;
                else if (op == 2) preco = 22.00;
                else {
                    printf("Opcao invalida!\n");
                    break;  // Sai do switch se a opção for inválida
                }

                // Pede a quantidade e acumula no total
                printf("Quantidade: ");
                scanf("%d", &quant);
                total += preco * quant;
                break;

            case 2: // Categoria de bebidas
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

            case 3: // Categoria de sobremesas
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

            case 4: // Finaliza o pedido
                printf("\nFinalizando pedido...\n");
                break;

            default: // Caso categoria inválida
                printf("Categoria invalida!\n");
        }

        // Pergunta se o usuário quer continuar pedindo (somente se não finalizou)
        if (categoria != 4) {
            printf("Deseja adicionar mais itens? (s/n): ");
            scanf(" %c", &continuar);  // Espaço antes de %c evita bug de leitura
        } else {
            continuar = 'n';  // Se finalizou, força saída do loop
        }

    } while (continuar == 's');  // Repete enquanto o usuário responder "s"

    // Aplica desconto de 10% caso o valor seja igual ou maior que R$50
    if (total >= 50) {
        desc = total * 0.1;  // Calcula 10% de desconto
        total -= desc;       // Atualiza o total com desconto
        printf("\nDesconto aplicado: R$%.2f\n", desc);
    }

    // Exibe resumo final do pedido
    printf("\n=== RESUMO DO PEDIDO ===\n");
    printf("Total a pagar: R$%.2f\n", total);
    printf("Obrigado pela preferência!\n");

    return 0; // Encerra o programa
}