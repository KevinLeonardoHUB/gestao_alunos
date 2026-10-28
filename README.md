# Student Management

A C terminal application for teachers to register, sign in, manage a class, record or update grades and calculate student averages. Data is saved between runs in a local text file.

## What it looks like

The Portuguese menu after signing in:

```text
1. Adicionar Aluno à sua turma
2. Adicionar Nota do aluno
3. Modificar Nota do aluno
4. Calcular Média do aluno
5. Sair do portal
```

## Build and run

Install GCC, then run from this repository's root:

```bash
gcc main.c funcoes.c -o gestao_alunos
./gestao_alunos
```

On Windows with GCC/MinGW, build and run in PowerShell:

```powershell
gcc main.c funcoes.c -o gestao_alunos.exe
.\gestao_alunos.exe
```

## Try it

1. Choose **1. Registro**, enter a teacher name, a password and its confirmation.
2. Choose a subject using one of the accepted values: `portugues`, `matematica`, `historia` or `edf`.
3. Add a student, then add grades using the student's name.
4. Choose **Calcular Média** to see the average, or **Modificar Nota** to correct a grade.
5. Exit with option **5**. On the next run, choose **2. Login** with the same teacher credentials.

## Relevant details

- Uses C structs, arrays and file I/O; no external libraries are required.
- Limits in `funcoes.h`: 5 teachers, 10 students per teacher and 5 grades per student.
- `dados_projeto.txt` is created in the current working directory. Run from the same directory to reuse your data.
- Passwords are stored as plain text. Use fictitious data and a test password; this is a learning project, not a production student-record system. Keep the generated data file out of version control.

Created by **Quévin Tavares**.
