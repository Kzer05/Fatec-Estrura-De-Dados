#include <stdio.h>
#include <string.h>

typedef struct Texto {
    char palavras[50];
} Texto;

Texto () {
    Texto novaPalavra;

    printf("\nDigite o nome do aluno: ");
    scanf(" %[^\n]", novaPalavra.palavras);
    return novaPalavra;
}

void imprimirAluno(Aluno a) {
    printf("\nNome: %s", a.nome);
    printf("\nMatricula: %d", a.matricula);
    printf("\nNota: %.2f\n", a.nota);
}

void gravarAlunoArquivo(Aluno a, FILE *arquivo) {
    fprintf(arquivo, "Nome: %s\nMatricula: %d\nNota: %.2f\n\n", a.nome, a.matricula, a.nota);
}

void lerAlunosArquivo() {
    FILE *arquivo;
    arquivo = fopen("alunos.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        return;
    }

    Aluno tempAluno;
    while (fscanf(arquivo, " Nome: %[^\n]\nMatricula: %d\nNota: %f\n", tempAluno.nome, &tempAluno.matricula, &tempAluno.nota) != EOF) {
        imprimirAluno(tempAluno);
    }

    fclose(arquivo);
}

int main() {
    int qtdAlunos = 0;
    int opcao = 0; 
    FILE *arquivo;

    do {
        printf("\n1) Digitar aluno: \n");
        printf("2) Ver alunos: \n");
        printf("0) Sair \n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Informe a quantidade de alunos que deseja cadastrar (1 a 3): ");
                scanf("%d", &qtdAlunos);
                if (qtdAlunos <= 0 || qtdAlunos > 3) {
                    printf("Numero nao suportado. A quantidade deve ser entre 1 e 3.\n");
                    break;
                }

                arquivo = fopen("alunos.txt", "a");
                if (arquivo == NULL) {
                    printf("Erro ao abrir o arquivo para escrita!\n");
                    break;
                }

                for (int i = 0; i < qtdAlunos; i++) {
                    printf("\nCadastrando aluno %d:\n", i + 1);
                    Aluno novoAluno = lerAluno();
                    gravarAlunoArquivo(novoAluno, arquivo);
                }

                fclose(arquivo);
                break;

            case 2:
                lerAlunosArquivo();
                break;

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}