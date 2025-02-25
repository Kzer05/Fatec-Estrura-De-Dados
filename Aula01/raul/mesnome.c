#include <stdio.h>

int main() {
    int IndexMes;
    char meses[12][25] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
    printf("Insira o Mês que deseja imprimir o nome\n> ");
    scanf("%d", &IndexMes);
    printf("%s", meses[IndexMes-1]);
}