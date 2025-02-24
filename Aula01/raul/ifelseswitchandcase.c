#include <stdio.h>
int main()
{
    while (1)
    {
        int num;
        int sair;
        printf("1. Imprimir\n2. Salvar\n3. Abrir\n4. Sair\n");
        scanf("%d", &num);
        switch (num)
        {
        case 1:
            printf("\nDocumento Impresso com Sucesso!\n");
            return 0;
            break;
        case 2:
            printf("\nDocumento Salvo com Sucesso\n");
            return 0;
            break;
        case 3:
            printf("\nDocumento Aberto com Sucesso\n");
            return 0;
            break;
        case 4:
            printf("\nTEM CERTEZA QUE DESEJA SAIR?\n1. Sim\nOutro. Não\n");
            scanf("%d", &sair);
            if (sair == 1)
            {
                printf("\nSaindo do Documento\n");
            }
            return 0;
            break;
        default:
            printf("Insira algo válido\n");
        }
    }
    return 0;
}