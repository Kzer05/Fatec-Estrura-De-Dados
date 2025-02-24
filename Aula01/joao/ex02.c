#include <stdio.h>

int main(){

    int num1;
    int num2;


    printf("Digite um numero inteiro \n");
    scanf("%d", &num1);
    printf("Digite outro numero inteiro \n");
    scanf("%d", &num2); 

    printf("%d + %d = %d \n", num1 , num2, num1 + num2);
    printf("%d - %d = %d \n", num1 , num2, num1 - num2);
    printf("%d * %d = %d \n", num1 , num2, num1 * num2);
    printf("%d / %d = %f \n", num1 , num2, (float)num1 / num2);
    printf("%d // %d = %d \n", num1 , num2, num1 % num2);

    return 0;
}