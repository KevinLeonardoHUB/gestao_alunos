#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "funcoes.h"

struct Professor professores[MAX_PROFESSORES];
int numProfessores = 0;

void bemvindo()
{
    printf("|------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("| #######   #####     ####    #####   ####       ###             ##   ##   ######  ######    # ##### ##   ##    ###    ####    |\n");
    printf("|  ##   #  ##   ##   ##  ##  ### ###   ##       ## ##            ##   ##     ##     ##  ##  ## ## ## ##   ##   ## ##    ##     |\n");
    printf("|  ##      ##       ##       ##   ##   ##      ##   ##           ##   ##     ##     ##  ##     ##    ##   ##  ##   ##   ##     |\n");
    printf("|  ####     #####   ##       ##   ##   ##      ##   ##            ## ##      ##     #####      ##    ##   ##  ##   ##   ##     |\n");
    printf("|  ##           ##  ##       ##   ##   ##      #######            ## ##      ##     ## ##      ##    ##   ##  #######   ##     |\n");
    printf("|  ##   #  ##   ##   ##  ##  ### ###   ##  ##  ##   ##             ###       ##     ## ##      ##    ##   ##  ##   ##   ##  ## |\n");
    printf("| #######   #####     ####    #####   #######  ##   ##             ###     ######  #### ##    ####    #####   ##   ##  ####### |\n");
    printf("|------------------------------------------------------------------------------------------------------------------------------|\n\n\n");
}

void carregarDados()
{
    FILE *fptr = fopen(FICHEIRO, "r");
    if (fptr == NULL)
    {
        numProfessores = 0;
        return;
    }

    fscanf(fptr, "%d", &numProfessores);
    for (int i = 0; i < numProfessores; i++)
    {
        fscanf(fptr, " %[^\n]", professores[i].nome);
        fscanf(fptr, " %[^\n]", professores[i].materia);
        fscanf(fptr, " %[^\n]", professores[i].senha);
        fscanf(fptr, "%d", &professores[i].numAlunos);
        for (int j = 0; j < professores[i].numAlunos; j++)
        {
            fscanf(fptr, " %[^\n]", professores[i].alunos[j].nome);
            fscanf(fptr, "%d", &professores[i].alunos[j].numNotas);
            for (int k = 0; k < professores[i].alunos[j].numNotas; k++)
            {
                fscanf(fptr, "%f", &professores[i].alunos[j].notas[k]);
            }
        }
    }

    fclose(fptr);
}

void salvarDados()
{
    FILE *fptr = fopen(FICHEIRO, "w");
    if (fptr == NULL)
    {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }
    fprintf(fptr, "%d\n", numProfessores);
    for (int i = 0; i < numProfessores; i++)
    {
        fprintf(fptr, "%s\n", professores[i].nome);
        fprintf(fptr, "%s\n", professores[i].materia);
        fprintf(fptr, "%s\n", professores[i].senha);
        fprintf(fptr, "%d\n\n", professores[i].numAlunos);
        for (int j = 0; j < professores[i].numAlunos; j++)
        {
            fprintf(fptr, "%s\n", professores[i].alunos[j].nome);
            fprintf(fptr, "%d\n", professores[i].alunos[j].numNotas);
            for (int k = 0; k < professores[i].alunos[j].numNotas; k++)
            {
                fprintf(fptr, "%.1f\n", professores[i].alunos[j].notas[k]);
            }
        }
    }

    fclose(fptr);
}

bool alunoJaRegistrado(int indiceProfessor, char *nomeAluno)
{
    for (int i = 0; i < professores[indiceProfessor].numAlunos; i++)
    {
        if (strcmp(professores[indiceProfessor].alunos[i].nome, nomeAluno) == 0)
        {
            return true;
        }
    }
    return false;
}

int verificarMateria(char *materia)
{
    char *materiasExistentes[] = {"portugues", "matematica", "historia", "edf"};
    for (int i = 0; i < 4; i++)
    {
        if (strcmp(materia, materiasExistentes[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int registrarProfessor()
{
    if (numProfessores >= MAX_PROFESSORES)
    {
        printf("Número máximo de professores atingido.\n");
        return -1;
    }

    struct Professor p;
    printf("Nome:\n> ");
    scanf(" %[^\n]", p.nome);

    for (int i = 0; i < numProfessores; i++)
    {
        if (strcmp(professores[i].nome, p.nome) == 0)
        {
            printf("Professor já existe, faça login por favor!\n");
            return -1;
        }
    }

    printf("Senha:\n> ");
    scanf(" %[^\n]", p.senha);
    printf("Digite a sua senha novamente:\n> ");
    scanf(" %[^\n]", p.senha2);

    if (strcmp(p.senha2, p.senha) != 0)
    {
        printf("Senhas não coincidem, registo mal sucedido!\n");
        return -1;
    }
    else
    {
        printf("Registo bem-sucedido!\n\n");
    }

    printf("Escreva sua matéria, matérias disponíveis são: portugues, matematica, historia e edf (educação física):\n> ");
    scanf(" %[^\n]", p.materia);
    while (verificarMateria(p.materia) == 0)
    {
        printf("Matéria inválida, digite uma válida:\n> ");
        scanf(" %[^\n]", p.materia);
    }
    printf("Matéria adicionada com sucesso!\n");

    p.numAlunos = 0;
    professores[numProfessores] = p;
    numProfessores++;
    return numProfessores - 1;
}

int loginProfessor(char *nome, char *senha)
{
    for (int i = 0; i < numProfessores; i++)
    {
        if (strcmp(professores[i].nome, nome) == 0 && strcmp(professores[i].senha, senha) == 0)
        {
            printf("Login bem-sucedido, bem-vindo %s!\n\n", nome);
            return i;
        }
    }
    printf("Login mal-sucedido, credenciais incorretas!\n");
    return -1;
}

void adicionarAluno(int indiceProfessor)
{
    if (indiceProfessor == -1)
    {
        printf("É preciso estar logado para adicionar alunos!\n");
        return;
    }

    if (professores[indiceProfessor].numAlunos >= MAX_ALUNOS)
    {
        printf("Número máximo de alunos atingido.\n");
        return;
    }

    struct Aluno a;
    printf("Nome do Aluno:\n> ");
    scanf(" %[^\n]", a.nome);

    if (alunoJaRegistrado(indiceProfessor, a.nome))
    {
        printf("Aluno já registrado!\n");
        return;
    }

    a.numNotas = 0;
    professores[indiceProfessor].alunos[professores[indiceProfessor].numAlunos] = a;
    professores[indiceProfessor].numAlunos++;
    printf("Aluno %s registrado com sucesso!\n", a.nome);
}

void adicionarNota(int indiceProfessor)
{
    if (indiceProfessor == -1)
    {
        printf("É necessário estar logado para adicionar notas!\n");
        return;
    }

    char nomeAluno[MAX_NOME];
    printf("Nome do Aluno:\n> ");
    scanf(" %[^\n]", nomeAluno);

    for (int i = 0; i < professores[indiceProfessor].numAlunos; i++)
    {
        if (strcmp(professores[indiceProfessor].alunos[i].nome, nomeAluno) == 0)
        {
            if (professores[indiceProfessor].alunos[i].numNotas >= MAX_NOTAS)
            {
                printf("Número máximo de notas atingido.\n");
                return;
            }

            float nota;
            printf("Nota:\n> ");
            scanf("%f", &nota);
            professores[indiceProfessor].alunos[i].notas[professores[indiceProfessor].alunos[i].numNotas] = nota;
            professores[indiceProfessor].alunos[i].numNotas++;
            printf("Nota adicionada com sucesso!\n");
            return;
        }
    }
    printf("Aluno não encontrado.\n");
}

void modificarNota(int indiceProfessor)
{
    if (indiceProfessor == -1)
    {
        printf("É necessário estar logado para modificar notas!\n");
        return;
    }

    char nomeAluno[MAX_NOME];
    printf("Nome do Aluno:\n> ");
    scanf(" %[^\n]", nomeAluno);

    for (int i = 0; i < professores[indiceProfessor].numAlunos; i++)
    {
        if (strcmp(professores[indiceProfessor].alunos[i].nome, nomeAluno) == 0)
        {
            printf("Notas do aluno %s:\n", nomeAluno);
            for (int j = 0; j < professores[indiceProfessor].alunos[i].numNotas; j++)
            {
                printf("Nota %d: %.1f\n", j + 1, professores[indiceProfessor].alunos[i].notas[j]);
            }

            int indiceNota;
            printf("Número da nota a modificar:\n> ");
            scanf("%d", &indiceNota);
            if (indiceNota < 1 || indiceNota > professores[indiceProfessor].alunos[i].numNotas)
            {
                printf("Índice de nota inválido.\n");
                return;
            }

            float novaNota;
            printf("Nova nota:\n> ");
            scanf("%f", &novaNota);
            professores[indiceProfessor].alunos[i].notas[indiceNota - 1] = novaNota;
            printf("Nota modificada com sucesso!\n");
            return;
        }
    }
    printf("Aluno não encontrado.\n");
}

void calcularMedia(int indiceProfessor)
{
    if (indiceProfessor == -1)
    {
        printf("É necessário estar logado para calcular a média!\n");
        return;
    }

    char nomeAluno[MAX_NOME];
    printf("Nome do Aluno:\n> ");
    scanf(" %[^\n]", nomeAluno);

    for (int i = 0; i < professores[indiceProfessor].numAlunos; i++)
    {
        if (strcmp(professores[indiceProfessor].alunos[i].nome, nomeAluno) == 0)
        {
            if (professores[indiceProfessor].alunos[i].numNotas == 0)
            {
                printf("Aluno não tem notas.\n");
                return;
            }

            float soma = 0;
            for (int j = 0; j < professores[indiceProfessor].alunos[i].numNotas; j++)
            {
                soma += professores[indiceProfessor].alunos[i].notas[j];
            }
            float media = soma / professores[indiceProfessor].alunos[i].numNotas;
            printf("A média do aluno %s é %.1f\n", nomeAluno, media);
            return;
        }
    }
    printf("Aluno não encontrado.\n");
}
