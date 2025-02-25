#include <stdio.h>

int main()
{
    int horas;
    float preco = 5;

    printf("Informe quantas horas ficara no estacionamento: \n");
    scanf("%d", &horas);

    if (horas <= 0 ) {
        printf("Informe um valor maior que zero: \n");
        return 0;
    }

    for (int i = 1; i < horas; i++) {
        preco += 3;
    }

    if (horas > 10) {
        preco = preco * 0.9;
    }

    printf("\nPreco: R$ %.2f\n", preco);
    return 0;
}