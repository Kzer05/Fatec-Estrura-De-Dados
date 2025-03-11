#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QTDE_MAX_ALUNO 3


typedef struct {
    char nome[50];
    int matricula;
    float nota;
} Aluno;


Aluno lerAluno();
void cadastrarAlunos(FILE *arquivo);
void lerAlunos();
void imprimirAluno(Aluno a);
void gravarAlunoArquivo(Aluno a, FILE *arquivo);

int main() {
    int opcao;

    
    FILE *arquivo = fopen("alunos.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    do {
        
        printf("\n1 - Digitar um aluno\n");
        printf("2 - Ler Alunos\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarAlunos(arquivo);
                break;
            case 2:
                fclose(arquivo); 
                lerAlunos(); 
                
                arquivo = fopen("alunos.txt", "a");
                if (arquivo == NULL) {
                    printf("Erro ao abrir o arquivo para append.\n");
                    return 1;
                }
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    fclose(arquivo);  
    return 0;
}

Aluno lerAluno() {
    Aluno novoAluno;
    
    
    printf("\nDigite o nome do aluno: ");
    getchar();  
    fgets(novoAluno.nome, sizeof(novoAluno.nome), stdin);
    novoAluno.nome[strcspn(novoAluno.nome, "\n")] = 0;  
    
    printf("Digite o numero da matricula do aluno: ");
    scanf("%d", &novoAluno.matricula);
    
    printf("Digite a nota do aluno: ");
    scanf("%f", &novoAluno.nota);
    
    return novoAluno;
}

void cadastrarAlunos(FILE *arquivo) {
    int verificaQtdeAlunos = 0;
    int qtdeAlunos = 0;

    
    while (qtdeAlunos == 0) {
        printf("\nDigite a quantidade de alunos que deseja cadastrar (1 a 3): ");
        scanf("%d", &verificaQtdeAlunos);
        if (verificaQtdeAlunos < 1 || verificaQtdeAlunos > QTDE_MAX_ALUNO) {
            printf("\nQuantidade inválida, por favor digite um número entre 1 e 3.\n");
            continue;
        }
        qtdeAlunos = verificaQtdeAlunos;
    }

    
    for (int i = 0; i < qtdeAlunos; i++) {
        Aluno novoAluno = lerAluno();
        gravarAlunoArquivo(novoAluno, arquivo);
    }
}

void lerAlunos() {
    FILE *arquivo = fopen("alunos.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    Aluno aluno;
    while (fscanf(arquivo, "%49[^\n]\n%d\n%f\n", aluno.nome, &aluno.matricula, &aluno.nota) != EOF) {
        imprimirAluno(aluno);
    }
    
    fclose(arquivo);
}

void imprimirAluno(Aluno a) {
    printf("\nNome: %s\n", a.nome);
    printf("Matricula: %d\n", a.matricula);
    printf("Nota: %.2f\n", a.nota);
}

void gravarAlunoArquivo(Aluno a, FILE *arquivo) {
    fprintf(arquivo, "%s\n%d\n%.2f\n", a.nome, a.matricula, a.nota);
}
