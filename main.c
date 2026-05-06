#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#define LIMPAR_TELA() system("cls")
#define AGUARDAR_MS(ms) Sleep(ms)
#else
#include <unistd.h>
#define LIMPAR_TELA() system("clear")
#define AGUARDAR_MS(ms) usleep((ms) * 1000)
#endif

#include "funcoes.h"

int main()
{
    #ifdef _WIN32
    system("chcp 65001");
    #endif
    LIMPAR_TELA();

    int opcao, indiceProfessor = -1;
    char nomeProfessor[MAX_NOME], senha[MAX_NOME];
    bool sair = false;

    bemvindo();
    printf("Bem-vindo ao portal da turma 4ºH\n\nPor favor, faça o seu registro/login:\n\n");
    carregarDados();

    while (indiceProfessor == -1)
    {
        printf("1. Registro\n");
        printf("2. Login\n\n");
        printf("Escolha uma opção:\n> ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            indiceProfessor = registrarProfessor();
            if (indiceProfessor == -1)
            {
                printf("Erro ao registrar professor. Por favor, tente novamente!\n\n");
            }

            printf("A criar credenciais");
            for (int i = 0; i < 3; i++)
            {
                printf(".");
                fflush(stdout);
                AGUARDAR_MS(700);
            }
            printf("\n");
            LIMPAR_TELA();
            salvarDados();
            break;
        case 2:
            printf("Nome do Professor:\n> ");
            scanf(" %[^\n]", nomeProfessor);
            printf("Senha:\n> ");
            scanf(" %[^\n]", senha);
            indiceProfessor = loginProfessor(nomeProfessor, senha);

            if (indiceProfessor == -1)
            {
                printf("Login mal sucedido, tente novamente!\n\n");
            }
            break;
        default:
            printf("Opção inválida, einicie o programa!\n\n");
            return 0;
            break;
        }
    }
    getchar();

    LIMPAR_TELA();
    bemvindo();
    do
    {
        printf("\n1. Adicionar Aluno à sua turma\n");
        printf("2. Adicionar Nota do aluno\n");
        printf("3. Modificar Nota do aluno\n");
        printf("4. Calcular Média do aluno\n");
        printf("5. Sair do portal\n\n");
        printf("Escolha uma opção:\n> ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            LIMPAR_TELA();
            bemvindo();
            adicionarAluno(indiceProfessor);
            salvarDados();
            break;
        case 2:
            LIMPAR_TELA();
            bemvindo();
            adicionarNota(indiceProfessor);
            salvarDados();
            break;
        case 3:
            LIMPAR_TELA();
            bemvindo();
            modificarNota(indiceProfessor);
            salvarDados();
            break;
        case 4:
            LIMPAR_TELA();
            bemvindo();
            calcularMedia(indiceProfessor);
            salvarDados();
            break;
        case 5:
            salvarDados();
            sair = true;
            break;
        default:
            printf("Opção inválida.\n");
            break;
        }
    } while (!sair);

    return 0;
}
