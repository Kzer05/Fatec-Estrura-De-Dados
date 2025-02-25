#include <stdio.h>

int main(){

    int num;

    printf("Digite um numero inteiro: \n");
    scanf("%d",&num);

    int i = 0;

    while(i <= num){
        printf("%d \n",i);
        i++;
    }
    
    return 0;
}