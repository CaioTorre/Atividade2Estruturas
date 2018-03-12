//Atividade 3
//Bruno Guilherme Marini Spirlandeli    - RA 17037607
//Caio Lima e Souza Della Torre Sanches - RA 17225285
//Gabriela Nelsina Vicente              - RA 17757089
//Marcos Aurélio Tavares de Sousa Filho - RA 17042284

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct taluno aluno;
struct taluno {
	int ra;
	char nome[50];
	float nota;
	struct taluno *prox;
};

int cadastro(aluno **);
int buscaRA(aluno *);
int buscaNome(aluno *);
void imprimirTodos(aluno *);
void strlwr(char *);

int main() {
	int op;
	aluno *start = NULL;
	
	do {
		printf("\t\tMenu do sistema\n1.Cadastrar aluno\n2.Buscar aluno por RA\n3.Buscar aluno por nome\n4.Exibir dados de todos os alunos\n5.Sair\n\n>");
	        scanf("%d", &op);
        	switch(op)
        	{
        	case 1:
        		cadastro(&start);
        	        break;
            	case 2:
			buscaRA(start);
                	break;
            	case 3:
			buscaNome(start);
                	break;
            	case 4:
			imprimirTodos(start);
                	break;
		case 5: 
			printf("Encerrando...\n\n");
			break;
		default: printf("Opcao invalida\n");
            	}
	}while(op != 5);
	return 0;
}

int cadastro(aluno **prev){
	aluno *aux;
	aux = malloc(sizeof(aluno));
	if (!aux) {printf("Memoria insuficiente!\n"); return (-1);}
	printf("----Cadastro de Aluno----\nInsira o nome: ");
	getchar();
	scanf("%[^\n]s", aux->nome);
	printf("Insira o RA: ");
	scanf("%d", &aux->ra);
	printf("Insira a nota: ");
	scanf("%f", &aux->nota);

	aux->prox = (*prev);
	(*prev) = aux;

	return 1;
}

void imprimirTodos(aluno *ini) {
	if (ini) {
		if (!(ini->prox)) {
			printf("\tRA: %d - %s;\t Nota: %.2f\n", ini->ra, ini->nome, ini->nota);
		} else {
			imprimirTodos(ini->prox);
			printf("\tRA: %d - %s;\t Nota: %.2f\n", ini->ra, ini->nome, ini->nota);
		}
	}
}

int buscaRA(aluno *ini){
	if (!ini) {printf("Lista vazia!"); return (-1);}
	int ra, f = 0;
	printf("Digite o RA a ser buscado: ");
	getchar();
	scanf("%d", &ra);
	printf("----Iniciando busca----\n\n");
	while (ini) {
		if (ini->ra == ra) {
			printf("Encontrado aluno %s com RA %d; Nota: %.2lf\n\n", ini->nome, ra, ini->nota);
			f++;
		}
		ini = ini->prox;
	}
	printf("----Busca encerrada----\n\n");
	if (f == 0) {
		printf("Nao foi encontrado nenhum aluno com RA %d\n\n", ra);
		return 0;
	} else {
		if (f > 1) {
			printf("%d alunos encontrados com RA %d!\n\n", f, ra);
			return 2;
		}
	}
	return 1;
}

int buscaNome(aluno *ini){
	if (!ini) {printf("Lista vazia!"); return (-1);}
	int f = 0;
	char nome[50], atual[50];
	printf("Digite o nome a ser buscado: ");
	getchar();
	scanf("%[^\n]s", &nome);
	strlwr(nome);
	printf("----Iniciando busca----\n\n");
	while (ini) {
		strcpy(atual, ini->nome);
		strlwr(atual);
		if (!strcmp(nome, atual)) {
			printf("Encontrado aluno %s (RA %d; Nota: %.2lf)\n\n", ini->nome, ini->ra, ini->nota);
			f++;
		}
		ini = ini->prox;
	}
	printf("----Busca encerrada----\n\n");
	if (f == 0) {
		printf("Nao foi encontrado nenhum aluno com nome %s\n\n", nome);
		return 0;
	} else {
		if (f > 1) {
			printf("%d alunos encontrados com nome %s!\n\n", f, nome);
			return 2;
		}
	}
	return 1;
}

void strlwr(char *str){
	char *p;
	p = str;
	while (*p) {
		*p = tolower(*p);
		p++;
	}
}
