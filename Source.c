#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h> //biblioteca para o sleep no Linux
#include <ctype.h> //biblioteca para o tolower(char*)

struct alunoS {
	int ra;
	char nome[50];
	double nota;
};
typedef struct alunoS aluno;

void cadastro(aluno *, int *, int);
void buscaRA(aluno *, int);
void buscaNome(aluno *, int);
void imprimirTodos(aluno *, int);

void strlwr(char*);

int main() {
	int maxalunos;
	int op, alunoscadastrados = 0;
	printf("Quantos alunos deseja configurar para o maximo? ");
	scanf("%d", &maxalunos);

	aluno *listaAlunos;
	
	listaAlunos = (aluno *) malloc(maxalunos * sizeof(aluno));

	do{
	        printf("\t\tMenu do sistema\n1.Cadastrar aluno\n2.Remover cadastro\n3.Buscar aluno por RA\n4.Buscar aluno por nome\n5.Exibir dados de todos os alunos\n6.Sair\n\n>");
	        scanf("%d", &op);

	        //if(op > 0 && op < 6)
	        //{
	        	switch(op)
	        	{
	        	case 1:
	        		cadastro(listaAlunos, &alunoscadastrados, maxalunos);
	        	        break;
	        	case 2:
	        	        break;
	            	case 3:
				buscaRA(listaAlunos, alunoscadastrados);
	                	break;
	            	case 4:
				buscaNome(listaAlunos, alunoscadastrados);
	                	break;
	            	case 5:
				imprimirTodos(listaAlunos, alunoscadastrados);
	                	break;
			case 6: 
				printf("Encerrando...\n\n");
				break;
			default: printf("Opcao invalida\n");
	            	}
	        //}
	        //else
	        //    printf("Opcao invalida");
	}while(op != 6);

	free(listaAlunos);
	return 0;
}

void cadastro(aluno *cadEstud, int *pos, int m){
	if (*pos < m) {
		int i;
		i = *pos;
    		printf("----Cadastro de Aluno----\nInsira o nome: ");
    		getchar();
    		scanf("%[^\n]s", cadEstud[i].nome);
    		printf("Insira o RA: ");
    		scanf("%d", &cadEstud[i].ra);
    		printf("Insira a nota: ");
    		scanf("%lf", &cadEstud[i].nota);
	
		*pos = *pos + 1;
    		printf("Cadastro realizado com sucesso!\n\n");
	} else {
		printf("Maximo de alunos atingido!\n\n");
	}
    //printf("%d\n%s\n%.2lf", cadEstud->ra, cadEstud->nome, cadEstud->nota);
    //sleep(2);
    //system("cls");
}

void buscaRA(aluno *lista, int tam){
	int ra, i, f = 0;
	printf("Digite o RA a ser buscado: ");
	scanf("%d", &ra);
	printf("----Iniciando busca----\n\n");
	for (i = 0; i < tam; i++) {
		if (lista[i].ra == ra) {
			printf("Encontrado aluno %s com RA %d; Nota: %.2lf\n\n", lista[i].nome, ra, lista[i].nota);
			f++;
		}
	}
	printf("----Busca encerrada----\n\n");
	if (f == 0) {
		printf("Nao foi encontrado nenhum aluno com RA %d\n\n", ra);
	} else {
		if (f > 1) {
			printf("%d alunos encontrados com RA %d!\n\n", f, ra);
		}
	}
}

void buscaNome(aluno *lista, int tam){
	int i, f = 0;
	char nome[50], atual[50];
	printf("Digite o nome a ser buscado: ");
	getchar();
	scanf("%[^\n]s", nome);
	strlwr(nome);
	printf("----Iniciando busca----\n\n");
	for (i = 0; i < tam; i++) {
		strcpy(atual, lista[i].nome);
		strlwr(atual);
		if (strcmp(nome, atual) == 0) {
			printf("Encontrado aluno %s (RA %d - Nota: %.2lf)\n\n", lista[i].nome, lista[i].ra, lista[i].nota);
			f++;
		}
	}
	printf("----Busca encerrada----\n\n");
	if (f == 0) {
		printf("Nao foi encontrado nenhum aluno com nome %s\n\n", nome);
	} else {
		if (f > 1) {
			printf("%d alunos encontrados com nome %s!\n\n", f, nome);
		}
	}
}

void imprimirTodos(aluno *cadEstud, int pos){
	printf("----Exibindo dados de todos os alunos----\n\n");
	int i;
	for (i = 0; i < pos; i++) {
		printf("\tRA: %d - %s;\t Nota: %.2lf\n", cadEstud[i].ra, cadEstud[i].nome, cadEstud[i].nota);
	}
	printf("\n----Exibicao concluida----\n\n");
}

void strlwr(char *str){
	char *p;
	p = str;
	while (*p) {
		*p = tolower(*p);
		p++;
	}
}
