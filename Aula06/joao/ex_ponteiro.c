#include <stdio.h>

int main() {
    int num1 = 42;
    int *p;

    p = &num1;
    
    
    printf("Valor do enderoco de memoria de num1 %p \n",p);
    printf("Valor da varivael num1 antes: %d \n",num1);
    *p = 99;
    printf("Valor da varivael num1 depois: %d \n",num1);
    
}