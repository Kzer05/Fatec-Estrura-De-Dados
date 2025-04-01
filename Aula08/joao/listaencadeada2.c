#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Estrutura do nó da lista
typedef struct No {
    char palavra[100];
    struct No *proximo;
} No;

void inserirNoFinal(No **inicio, const char* palavra) {
    No *novo = (No*) malloc(sizeof(No));
    
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        return;
    }
    strcpy(novo->palavra, palavra);
    novo->proximo = NULL;

    if(*inicio == NULL){
        *inicio = novo;
    }else{
        No *temp = *inicio;

        while (temp->proximo != NULL){
            temp = temp->proximo;
        }
        temp->proximo = novo;
    }
    printf("palavra '%s' inserida no final da lista.\n", palavra);
}

// Função para exibir a lista
void exibirLista(No *inicio) {
    if (inicio == NULL) {
        printf("Lista vazia.\n");
        return;
    }

    printf("Lista: ");
    while (inicio != NULL) {
        printf("%s -> ", inicio->palavra);
        inicio = inicio->proximo;
    }
    printf("NULL\n");
}

int main() {
    No *lista = NULL;
    char palavra[100];
    int opcao;

    do {
        printf("\n1) Inserir uma palavra\n");
        printf("2) Mostrar a lista\n");
        printf("0) Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); 

        switch (opcao) {
            case 1:
                printf("Digite a palavra: ");
                fgets(palavra, sizeof(palavra), stdin);
                palavra[strcspn(palavra, "\n")] = 0;  
                inserirNoFinal(&lista, palavra);

                break;
            case 2:
                exibirLista(lista);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    return 0;
}
