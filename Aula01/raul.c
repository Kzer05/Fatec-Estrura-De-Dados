#include <stdio.h>

int main(){
    char mundo[50];
    printf("Olá ???\n");
    scanf("%[^\n]", mundo);
    printf("Olá %s", mundo);
    return 0;
}