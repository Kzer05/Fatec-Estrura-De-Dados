#include <stdio.h>
#include <stdlib.h>

// Criar o "prato"

struct No{
    int valor;
    struct No *proximo;
};
// Colocar o prato na pilha (push)
void push(struct No **topo, int numero){
    // Cria um prato novo
    struct No *novo = (struct No*) malloc(sizeof(struct No));

    if (novo == NULL){
        printf("Erro de mémoria");
        return;
    }


    // Guarda o valor no novo prato
    novo->valor = numero;

    // O novo prato aponta para o antigo topo
    novo->proximo = *topo;

    // O novo prato esta no topo

    *topo = novo;

    printf("Valor %d colocado na pilha. \n", numero);
}

// Retirar prato da filha
void pop(struct No **topo){
    if (*topo == NULL){
        printf("Pilha Vazia");
        return;
    }

    // Pega o prato de cima
    struct No *temp = *topo;
    printf("Valor %d retirando da pilha\n", temp->valor);

    // O prato de vaixo vira o do topo
    *topo = temp->proximo;

    // Joga fora o prato de cima
    free(temp);
}

// Mostrar todos os pratos da pilha
void mostrarPilha(struct No *topo){
    if (topo == NULL){
        printf("Pilha esta vazia");
        return;
    }

    printf("Valores dos pratos da pilha: \n");

    // enquanto houver pratos na pilhas
    while (topo != NULL){
        printf("%d \n", topo->valor);

        // Vai para o próximo prato
        topo = topo->proximo;
    }
}

int main(){
    // Pilha de pretos comeca vazia
    struct No *topo = NULL;
    int num;
    int opcao;
    do
    {
        printf("1) Inserir prato na pilha \n");
        printf("2) Retirar prato da pilha \n");
        printf("3) Mostrar pilha de pratos \n");
        printf("0) Sair do programa \n");
        scanf("%d",&opcao);

        switch (opcao)
        {
        case 1:
            printf("Digite o numero do prato: \n");
            scanf("%d", &num);
            push(&topo,num);
            break;
        case 2:
            pop(&topo);
            break;
        case 3:
            mostrarPilha(topo);
            break;
        case 0:
            printf("Saindo do programa...");
            break;
        default:
            printf("Digite um numero valido \n");
            break;
        }
    } while (opcao != 0);

}