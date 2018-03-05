#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct aluno;

struct aluno {
	int ra;
	char nome[50];
	double nota;
}

int main() {
	int maxalunos;
	printf("Quantos alunos deseja configurar para o máximo? ");
	scanf("%d", &maxalunos);
	
	aluno *listaAlunos = (aluno *) malloc(maxalunos * sizeOf(aluno));
	return 0;
}