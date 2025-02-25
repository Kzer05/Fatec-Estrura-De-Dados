#include <stdio.h>

int main() {

    int num;
    scanf("%d", &num);
    if(num%2==0) {
        printf("Nao tem resto (par)");
    } else {
        printf("Tem resto (impar)");
    }

}