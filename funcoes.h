#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdbool.h>

#define MAX_PROFESSORES 5
#define MAX_ALUNOS 10
#define MAX_NOTAS 5
#define MAX_NOME 100
#define FICHEIRO "dados_projeto.txt"

struct Aluno
{
    char nome[MAX_NOME];
    float notas[MAX_NOTAS];
    int numNotas;
};

struct Professor
{
    char nome[MAX_NOME];
    char materia[MAX_NOME];
    char senha[MAX_NOME];
    char senha2[MAX_NOME];
    struct Aluno alunos[MAX_ALUNOS];
    int numAlunos;
};

extern struct Professor professores[MAX_PROFESSORES];
extern int numProfessores;

void bemvindo();
void carregarDados();
void salvarDados();
bool alunoJaRegistrado(int indiceProfessor, char *nomeAluno);
int verificarMateria(char *materia);
int registrarProfessor();
int loginProfessor(char *nome, char *senha);
void adicionarAluno(int indiceProfessor);
void adicionarNota(int indiceProfessor);
void modificarNota(int indiceProfessor);
void calcularMedia(int indiceProfessor);

#endif
