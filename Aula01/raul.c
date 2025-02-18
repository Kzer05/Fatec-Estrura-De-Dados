#include <stdio.h>
#include <string.h>

int main(){
    char mundo[50];
    int numerointeirointeressante;
    float numerorealaindamaisinteressante;
    double numerorealaindamaisexpecificoeinteressante;

    printf("Olá ???\n");
    scanf("%[^\n]", mundo);
    getchar();
    printf("O número ??? é o mais interessante");
    scanf("%numerointeirointeressante", &numerointeirointeressante);
    printf("Seguido do número real ???");
    scanf("%numerorealaindamaisinteressante", &numerorealaindamaisinteressante);
    printf("E do número ???, que é mais expecifico ainda");
    scanf("%numerorealaindamaisexpecificoeinteressante", &numerorealaindamaisexpecificoeinteressante);
    printf("Usuário %s\t|NI %d\t| NRI %f\t| NAMIR %f\t", mundo, numerointeirointeressante, numerorealaindamaisinteressante, numerorealaindamaisexpecificoeinteressante);
    return 0;
}