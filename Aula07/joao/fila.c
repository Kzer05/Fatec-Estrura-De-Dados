#include <stdio.h>
#include <stdlib.h>

// Estrutura da Pessoa
struct Pessoa {
    int valor;
    struct Pessoa *proxima;
};

// Insere uma nova pessoa na fila
void enqueue (struct Pessoa **inicio, struct Pessoa **fim, int numero) {
    struct Pessoa *novaPessoa = (struct Pessoa*) malloc(sizeof(struct Pessoa));

    novaPessoa->valor = numero;
    novaPessoa->proxima = NULL;

    if (*fim == NULL) {
        // Fila esta vazia
        *inicio = novaPessoa;
        *fim = novaPessoa;
    } else {
        (*fim)->proxima = novaPessoa;
        *fim = novaPessoa;
    }
}

// Tira uma pessoa da fila
void dequeue (struct Pessoa **inicio, struct Pessoa **fim) {
    if (*inicio == NULL) {
        printf ("Fila esta vazia");
        return;
    }

    struct Pessoa *temp = *inicio;
    printf("Removendo pessoa...%d \n", temp->valor);
    *inicio = temp->proxima;

    if (*inicio == NULL) {
        *fim = NULL;
    }

    free(temp);
}

// Mostra as pessoas da fila
void mostraFila(struct Pessoa *inicio) {
    if (inicio == NULL) {
        printf("Fila esta vazia!");
        return;
    }

    printf("Fila atual: ");
    while(inicio != NULL) {
        printf("%d ", inicio->valor);
        inicio = inicio->proxima;
    }

    printf("\n");
}

int main() {
    struct Pessoa *inicio = NULL;
    struct Pessoa *fim = NULL;

    enqueue(&inicio, &fim, 10);
    enqueue(&inicio, &fim, 20);
    enqueue(&inicio, &fim, 30);

    mostraFila(inicio);

    dequeue(&inicio, &fim);

    mostraFila(inicio);

    return 0;
}