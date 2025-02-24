#include <stdio.h>

int main(){
    int opcao;

    printf("############### \n"
        "1) Imprimir \n"
        "2) Salvar \n"
        "3) Abrir \n"
        "4) Sair \n"
    "################# \n");
    scanf("%d",&opcao);
    
// 
    switch (opcao)
    {
    case 1:
        printf("Imprimindo....");
        break;
    
    case 2:
        printf("Salvando....");
        break;
    
    case 3:
        printf("Abrindo....");
        break;
    
    case 4:
        printf("Saindo....");
        break;
    default:
        printf("Aaaaa nenhuma opcao \n");
        break;
    }

    return 0;
}