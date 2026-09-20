# Student Management

A small **C** project for managing teachers, students and grades.

The program runs in the terminal and allows a teacher to register and sign in, add students, record or update grades, and calculate a student's average grade.

## Features

- Teacher registration
- Teacher sign-in
- Association between a teacher and a subject
- Adding students to a teacher's class
- Recording student grades
- Updating grades
- Calculating a student's average grade
- Saving data to a local file

## Technologies

- C
- `.c` and `.h` files
- File handling in C
- `struct` data structures
- Arrays
- Functions

## Project structure

```text
gestao-alunos/
├── main.c
├── funcoes.c
├── funcoes.h
├── README.md
└── .gitignore
```

## Build

With GCC installed, run:

```bash
gcc main.c funcoes.c -o gestao_alunos
```

## Run

On Windows:

```bash
gestao_alunos.exe
```

On Linux or macOS:

```bash
./gestao_alunos
```

## Data and privacy

The application creates `dados_projeto.txt` automatically when it saves data.

This file is not included in the repository because it may contain names, passwords and student information.

## Author

**Quévin Tavares**
