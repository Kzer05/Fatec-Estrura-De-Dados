#include <stdio.h>

int main(){
    
    int idade;
    
    printf("Digite sua idade: \n");
    scanf("%d", &idade);

    if(idade >= 18){
        printf("Maior de idade");
    }else{
        printf("Menor de idade");
    }

    return 0;
}