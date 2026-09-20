# Gestão de Alunos

Mini projeto em linguagem **C** para gestão simples de professores, alunos e notas.

O programa funciona no terminal e permite que um professor faça registo/login, adicione alunos, registe notas, modifique notas e calcule a média de um aluno.

## Funcionalidades

- Registo de professores
- Login de professores
- Associação de professor a uma matéria
- Adição de alunos à turma do professor
- Registo de notas dos alunos
- Modificação de notas
- Cálculo da média do aluno
- Guardar dados em ficheiro local

## Tecnologias usadas

- Linguagem C
- Ficheiros `.c` e `.h`
- Manipulação de ficheiros em C
- Estruturas `struct`
- Arrays
- Funções

## Estrutura do projeto

```txt
gestao-alunos/
├── main.c
├── funcoes.c
├── funcoes.h
├── README.md
└── .gitignore
```

## Como compilar

Com GCC instalado, usa o comando:

```bash
gcc main.c funcoes.c -o gestao_alunos
```

## Como executar

No Windows:

```bash
gestao_alunos.exe
```

No Linux ou macOS:

```bash
./gestao_alunos
```

## Observação

O ficheiro `dados_projeto.txt` é criado automaticamente quando o programa guarda os dados.

Esse ficheiro não foi incluído no GitHub porque pode conter nomes, senhas e dados de alunos.

## Autor

Quévin Tavares
