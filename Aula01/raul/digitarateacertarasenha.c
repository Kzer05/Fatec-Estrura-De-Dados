#include <stdio.h>
int main() {
    int i = 1;
    int senha = 9999;
    int tentativa = -1;
    do {
        printf("Insira uma senha\n");
        scanf("%d",&tentativa);
    } while(tentativa != senha);
    printf("Acertoouuuuu!");
}