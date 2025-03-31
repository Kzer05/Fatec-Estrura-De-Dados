#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    int id;
    struct No *next;
} No;

void enqueue(No **front, No **back, int id ) {
    No *newNo = (No*) malloc(sizeof(No));
    if (!newNo) {
        printf("Erro de alocação de memória!\n");
        return;
    }

    newNo->id = id;
    newNo->next = NULL;

    if (!*back) {
        *front = newNo;
        *back = newNo;
        return;
    }

    (*back)->next = newNo;
    *back = newNo;
}

void dequeue(No **front, No **back) {
    if (!*front) {
        printf("Nada para remover!\n");
        return;
    }

    No *temp = *front;
    *front = (*front)->next;
    if (!*front) {
        *back = NULL;
    }
    free(temp);
}

void printQueue(No *front) {
    if (!front) {
        printf("\nA fila esta vazia.\n");
        return;
    }

    printf("Fila: ");
    No *current = front;
    while (current) {
        printf("%d ", current->id);
        current = current->next;
    }
    printf("\n");
}

int main() {
    No *front = NULL;
    No *last = NULL;

    /* Criar um programa que simule uma fila, onde você irá inserir 3 itens, 
    exibir a fila, remover 1 item, exibir a fila, inserir mais 2 itens e exibir a fila. Utilize como nome da estrutura "No". */

    enqueue(&front, &last, 10);
    enqueue(&front, &last, 20);
    enqueue(&front, &last, 30);
    printQueue(front);
    dequeue(&front, &last);
    enqueue(&front, &last, 40);
    enqueue(&front, &last, 50);
    printQueue(front);

    scanf("%d", NULL); // só pra não fechar
    return 0;
}