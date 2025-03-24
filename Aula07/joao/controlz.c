#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char palavra[100];
    struct No *proximo;
} No;

// Colocar uma palavra na pilha (push)
void push(No **topo, const char *novaPalavra) {
    No *novo = (No*) malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro de memoria\n");
        return;
    }

    strcpy(novo->palavra, novaPalavra);
    novo->proximo = *topo;
    *topo = novo;

    printf("Palavra %s colocada no texto.\n", novaPalavra);
}

// Retirar uma palavra da pilha (pop)
void pop(No **topo) {
    if (*topo == NULL) {
        printf("Texto Vazio\n");
        return;
    }

    No *temp = *topo;
    printf("Palavra %s retirada do texto\n", temp->palavra);

    *topo = temp->proximo;
    free(temp);
}

// Mostrar todas as palavras da pilha
void mostrarPilha(No *topo) {
    if (topo == NULL) {
        printf("Texto vazio\n");
        return;
    }

    printf("Palavras no texto:\n");
    while (topo != NULL) {
        printf("%s\n", topo->palavra);
        topo = topo->proximo;
    }
}

int main() {
    No *topo = NULL;
    char palavra[100];
    int opcao;

    do {
        printf("\n1) Insira uma palavra no texto\n");
        printf("2) Retire a ultima palavra do texto\n");
        printf("3) Mostrar o texto\n");
        printf("0) Sair do programa\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                printf("Digite a palavra: ");
                fgets(palavra, sizeof(palavra), stdin);
                palavra[strcspn(palavra, "\n")] = 0;
                push(&topo, palavra);
                break;
            case 2:
                pop(&topo);
                break;
            case 3:
                mostrarPilha(topo);
                break;
            case 0:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Digite um número válido\n");
                break;
        }
    } while (opcao != 0);

    while (topo != NULL) {
        pop(&topo);
    }

    return 0;
}
