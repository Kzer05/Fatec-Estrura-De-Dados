#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Person {
    int id;
    struct Person *next;
} Person;

Person *enqueue(Person *back, int id) {
    Person *newPerson = (Person*) malloc(sizeof(Person));
    if (!newPerson) {
        printf("Erro de alocação de memória!\n");
        return back;
    }

    newPerson->id = id;
    newPerson->next = NULL;
    
    if (!back) {
        return newPerson;
    }
    
    back->next = newPerson;
    return newPerson;
}

Person *dequeue(Person *front) {
    if (!front) {
        printf("Nada para remover!\n");
        return NULL;
    }
    printf("Removendo: %d\n", front->id);
    Person *temp = front;
    front = front->next;
    free(temp);
    return front;
}

void printQueue(Person *front) {
    if (!front) {
        printf("\n A fila está vazia.\n");
        return;
    }

    printf("Fila: ");
    Person *current = front;
    while (current) {
        printf("%d ", current->id);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Person *front = NULL;
    Person *last = NULL;
    
    int input, option;

    while (1) {
        printf("\nEscolha uma opcao:\n");
        printf("1 - Adicionar numero da pesspa\n");
        printf("2 - Remover numero da pessoa\n");
        printf("3 - Ver fila\n");
        printf("4 - Sair\n");
        printf("Digite o numero da opcao: ");

        scanf("%d", &option);

        switch (option) {
            case 1:  
                printf("Digite o numero para adicionar: ");
                scanf("%d", &input);
                last = enqueue(last, input);
                if (!front) front = last;
                break;
            case 2:  
                front = dequeue(front);
                if (!front) last = NULL;
                break;
            case 3: 
                printQueue(front);
                break;
            case 4:  
                return 0;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    }

    return 0;
}
