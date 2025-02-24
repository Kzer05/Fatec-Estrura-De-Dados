#include <stdio.h>

int main()
{
    int opcao;

    printf("1. Imprimir");
    printf("2. Salvar");
    printf("3. Abrir");
    printf("4. Sair");

    scanf("%d", &opcao);

    switch (opcao)
    {
    case 1:
        printf("Imprimindo...");
        break;
    
    case 2:
        printf("Salvando...");
        break;
    
    case 3:
        printf("Abrindo...");
        break;
    
    case 4:
        printf("Saindo...");
        break;
    default:
        printf("Aaaaa nenhuma opcao \n");
    }

    return 0;
}