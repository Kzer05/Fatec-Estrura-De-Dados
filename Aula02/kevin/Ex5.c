#include <stdio.h>

int main()
{
    int digitado;

    do {
        printf("Informe o digitado: \n");
        scanf("%d", &digitado);
    } while (digitado != 1234);

    printf("Acertou a senha! \n");
    return 0;
}