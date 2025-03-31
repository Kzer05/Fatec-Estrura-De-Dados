#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Cliente {
    char nome[100];         
    struct Cliente *proxima;  
};


void enqueue(struct Cliente **inicio, struct Cliente **fim, const char *nome) {
    struct Cliente *novoCliente = (struct Cliente*) malloc(sizeof(struct Cliente));

 
    if (novoCliente == NULL) {
        printf("Erro na alocação de memória.\n");
        return;
    }

  
    strncpy(novoCliente->nome, nome, 99);
    novoCliente->nome[99] = '\0';  
    novoCliente->proxima = NULL;

    if (*fim == NULL) {
      
        *inicio = novoCliente;
        *fim = novoCliente;
    } else {
       
        (*fim)->proxima = novoCliente;
        *fim = novoCliente;
    }
}


void dequeue(struct Cliente **inicio, struct Cliente **fim) {
    if (*inicio == NULL) {
        printf("Fila está vazia! Nenhum cliente para atender.\n");
        return;
    }

    struct Cliente *temp = *inicio;
    printf("Atendendo cliente: %s\n", temp->nome);
    *inicio = temp->proxima;

    if (*inicio == NULL) {
       
        *fim = NULL;
    }

    free(temp); 
}


void mostraFila(struct Cliente *inicio) {
    if (inicio == NULL) {
        printf("Fila está vazia!\n");
        return;
    }

    printf("Fila de espera: ");
    while (inicio != NULL) {
        printf("%s ", inicio->nome);
        inicio = inicio->proxima;
    }
    printf("\n");
}


int main() {
    struct Cliente *inicio = NULL;
    struct Cliente *fim = NULL;
    int opcao;
    char nome[100];

    do {
        printf("\n--- Sistema de Atendimento Bancário ---\n");
        printf("1. Inserir cliente na fila\n");
        printf("2. Atender cliente\n");
        printf("3. Exibir fila de espera\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();  

        switch(opcao) {
            case 1:
                printf("Digite o nome do cliente: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0'; 
                enqueue(&inicio, &fim, nome);
                break;
            case 2:
                dequeue(&inicio, &fim);
                break;
            case 3:
                mostraFila(inicio);
                break;
            case 4:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while(opcao != 4);

    struct Cliente *temp;
    while (inicio != NULL) {
        temp = inicio;
        inicio = inicio->proxima;
        free(temp);
    }

    return 0;
}
