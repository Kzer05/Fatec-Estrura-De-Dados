#include <stdio.h>

int main() {
    int nro = 10;
    int *p;

    p = &nro;

    printf("Valor de NRO: %d \n" ,nro);
    printf("Endereço de NRO: %p \n" ,&nro);
    printf("Endereço guardado em p : %p \n" ,p);
    printf("Valor que p aponta : %d \n", *p);

}