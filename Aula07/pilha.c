#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

typedef struct Word {
    char word[MAX_WORD_LENGTH];
    struct Word *next;
} Word;

Word *push(Word *top, const char *word) {
    Word *newWord = (Word*) malloc(sizeof(Word));

    strcpy(newWord->word, word);
    newWord->next = top;
    return newWord;
}

Word *pop(Word *top) {
    if (!top) {
        printf("Nada para desfazer!\n");
        return NULL;
    }

    printf("Desfazendo: %s\n", top->word);
    
    Word *temp = top;
    top = top->next;

    free(temp);
    return top;
}

int main() {
    Word *log = NULL;
    char input[MAX_WORD_LENGTH];

    while (1) {
        printf("Digite uma palavra ou 'undo' para desfazer ('exit' para sair): ");
        scanf("%s", input);
        getchar();
        
        if (strcmp(input, "exit") == 0) {
            break;
        } else if (strcmp(input, "undo") == 0) {
            log = pop(log);
        } else {
            log = push(log, input);
        }
    }
    
    return 0;
}
