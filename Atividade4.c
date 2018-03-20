/*
 * Estrutura e Recuperação de Dados A
 * Atividade 4 (Lista Ligada)
 * 
 * Para compilar com o DEBUG ativado:
 * $ gcc -DDEBUG -g Atividade4.c -o Atividade4
 * 
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdio_ext.h>

typedef struct no No;
struct no {
    int chave;
    No *prox;
};
 
// Questao 1
void insereInicio (No **pLista, int n) {
	No *aux = (No*)malloc(sizeof(No));
	aux->chave = n;
	aux->prox = *pLista;
	*pLista = aux;
}

// Questao 2
void insereFim (No **pLista, int n) {
	No *aux = *pLista;	
	while (aux->prox) aux = aux->prox;
	No *aux2 = (No*)malloc(sizeof(No));
	aux->prox = aux2;
	aux2->chave = n;
}

// Questao 3
void insereK (No **pLista, int n, int k) {
	int i;
	No *aux = *pLista;
	for (i = 0; i < k - 1; i++) if (aux->prox) aux = aux->prox;
	No *aux2 = (No*)malloc(sizeof(No));
	No *aux3 = aux->prox;
	aux->prox = aux2;
	aux2->prox = aux3;
	aux2->chave = n;
}

// Questao 4
void exibePrimeiro (No *Lista) {
	printf("O primeiro elemento tem chave %i\n", Lista->chave);
}

// Questao 5
void exibeUltimo (No *Lista){
	No *aux = Lista;	
	while (aux->prox) aux = aux->prox;
	printf("O ultimo elemento tem chave %i\n", aux->chave);
}

// Questao 6
void exibeK (No *Lista, int k) {
	int i;
	No *aux = Lista;
	for (i = 0; i < k; i++) aux = aux->prox;
	printf("O %i-esimo elemento tem chave %i\n", k, aux->chave);
}

// Questao 7
int procuraN (No *Lista, int n) {
	if (Lista->chave == n) return 1;
	No *aux = Lista;	
	while (aux) {
		if (aux->chave == n) return 1;
		aux = aux->prox;
	}
	return 0;
}

// Questao 8
int quantidade (No *Lista) {
	int i = 0;
	//if (Lista) i = 1;
	No *aux = Lista;	
	while (aux) {i++; aux = aux->prox;}
	return i;
}

// Questao 9
int soma (No *Lista) {
	float i = 0;
	No *aux = Lista;
	while (aux) {i = i + aux->chave; aux = aux->prox;}
	return i;
}

// Questao 10
float media (No *Lista) {
	int i = 0, s = 0;
	No *aux = Lista;
	while (aux) {s = s + aux->chave; i++; aux = aux->prox;}
	return (s/i);
}

// Questao 11
void excluiPrimeiro (No **pLista) {
	No *aux = *pLista;
	*pLista = (*pLista)->prox;
	free(aux);
}

// Questao 12
void excluiUltimo (No **pLista) {
	No *aux = *pLista;
	No *aux2 = aux;
	while (aux->prox) {
		aux2 = aux;
		aux = aux->prox;
	}
	aux2->prox = NULL;
	free(aux);
}

// Questao 13
void excluiK (No **pLista, int k) {
	int i, f = 0;
	No *aux = *pLista;
	if (k == 0) {
		*pLista = (*pLista)->prox;
		free(aux);
	} else {
		No *aux2 = *pLista;
		for (i = 0; i < k; i++) {
			if (!aux) f = 1;
			if (!f) {
				aux2 = aux; aux = aux->prox;
			}
		}
		if (!f) {
			aux2->prox = aux->prox;	
			free(aux);
		}
	}
}

// Questao 14
void excluiN (No **pLista, int n) {
	No *aux = *pLista;
	No *aux2 = *pLista;
	if (aux->chave == n) {*pLista = (*pLista)->prox; free(aux);} else {
		if (aux->prox) {
			aux = aux->prox;
			while (aux) {
				if (aux->chave == n) {
					aux2->prox = aux->prox;
					free(aux);
				}
				aux2 = aux2->prox;
				aux = aux->prox;
			}
		}
	}
}

// Cria uma lista vazia
void criaVazia (No **pLista) {
  *pLista = NULL;
}

// DEBUG: Exibe todos os elementos de uma Lista
void exibe (No *Lista) {
    while (Lista!=NULL) {
      printf("%d ",Lista->chave);
      Lista = Lista->prox;
    }
}

int main() {
    int opcao = -1, n, k;
    No *Lista;
    criaVazia(&Lista);
    while (opcao != 0) {
        do {
            printf("\n");
            printf("(0) Finalizar o programa\n");
            printf("(1) Inserir elemento no inicio da lista (Q-1)\n");
            printf("(2) Inserir elemento no final da lista (Q-2)\n");
            printf("(3) Inserir elemento na k-esima posicao da lista (Q-3)\n");
            printf("(4) Exibir o primeiro elemento da lista (Q-4)\n");
            printf("(5) Exibir o ultimo elemento da lista (Q-5)\n");
            printf("(6) Exibir o k-esimo elemento da lista (Q-6)\n");
            printf("(7) Procurar um elemento da lista (Q-7)\n");
            printf("(8) Exibir a quantidade de elementos da lista (Q-8)\n");
            printf("(9) Exibir a soma dos valores da lista (Q-9)\n");
            printf("(10) Exibir a media dos valores da lista (Q-10)\n");
            printf("(11) Excluir o primeiro elemento da lista (Q-11)\n");
            printf("(12) Excluir o ultimo elemento da lista (Q-12)\n");
            printf("(13) Excluir o k-esimo elemento da lista (Q-13)\n");
            printf("(14) Excluir um elemento procurado da lista (Q-14)\n");
            printf("Opcao: ");
            scanf("%d", &opcao);
            printf("\n");
            if ((opcao<0) || (opcao>14))
                printf("Opcao invalida!\n");
        } while ((opcao<0) || (opcao>14));
        switch (opcao) {
	    case 0:
		printf("Finalizando o programa.\n");
                return 0;
            case 1:
                // Insere um elemento no inicio da lista
                printf("Q-1 Insere um elemento no inicio\n");
                printf("Chave: ");
                __fpurge(stdin);
                scanf("%d",&n);
                insereInicio(&Lista,n);
                break;
            case 2:
                // Insere um elemento no fim da lista
                printf("Q-2 Insere um elemento no fim\n");
                printf("Chave: ");
                __fpurge(stdin);
                scanf("%d",&n);
                insereFim(&Lista,n);
                break;
            case 3:
                // Insere um elemento na k-esima posicao da lista
                printf("Q-3 Insere um elemento na k-esima posicao\n");
                printf("Chave: ");
                __fpurge(stdin);
                scanf("%d",&n);
                printf("k: ");
                __fpurge(stdin);
                scanf("%d",&k);
                insereK(&Lista,n,k);
                break;
            case 4:
		// Exibe o primeiro elemento da lista
                printf("Q-4 Exibe o primeiro elemento\n");
                printf("Chave: ");
                exibePrimeiro(Lista);
                printf("\n");
                break;
            case 5:
		// Exibe o ultimo elemento da lista
                printf("Q-5 Exibe o ultimo elemento\n");
                printf("Chave: ");
                exibeUltimo(Lista);
                printf("\n");
                break;
	    case 6:
		// Exibe o k-esimo elemento da lista
                printf("Q-6 Exibe o k-esimo elemento\n");
                printf("k: ");
                __fpurge(stdin);
                scanf("%d",&k);
                printf("Chave: ");
                exibeK(Lista,k);
		printf("\n");
		break;
	    case 7:
		// Procura por um elemento da lista
                printf("Q-7 Procura por um elemento\n");
                printf("Chave: ");
                __fpurge(stdin);
                scanf("%d",&n);
                if (procuraN(Lista,n))
                    printf("Elemento %d encontrado.\n", n);
                else
                    printf("Elemento %d não encontrado.\n", n);
		break;
	    case 8:
		// Exibe a quantidade de elementos da lista
                printf("Q-8 Exibe a quantidade de elementos\n");
                printf("Quantidade de elementos: %d\n", quantidade(Lista));
		break;
	    case 9:
		// Exibe a soma dos elementos da lista
                printf("Q-9 Exibe a soma dos elementos\n");
                printf("Soma: %d\n", soma(Lista));
		break;
	    case 10:
		// Exibe a media dos elementos da lista
                printf("Q-10 Exibe a media dos elementos\n");
                printf("Media: %f\n", media(Lista));
		break;
	    case 11:
		// Exclui o primeiro elemento da lista
                printf("Q-11 Exclui o primeiro elemento\n");
                excluiPrimeiro(&Lista);
		break;
	    case 12:
		// Exclui o ultimo elemento da lista
                printf("Q-12 Exclui o ultimo elemento\n");
                excluiUltimo(&Lista);
		break;
	    case 13:
		// Exclui o k-esimo elemento da lista
                printf("Q-13 Exclui o k-esimo elemento\n");	      
                printf("k: ");
                __fpurge(stdin);
                scanf("%d",&k);
                excluiK(&Lista,k);
		break;
	    case 14:
		// Exclui um elemento procurado da lista
                printf("Q-14 Exclui um elemento procurado\n");	      
                printf("Chave: ");
                __fpurge(stdin);
                scanf("%d",&n);
                excluiN(&Lista,n);
		break;            
	    default:
                break;
        }
#ifdef DEBUG
	printf("\n[DEBUG] Lista: ");
	exibe(Lista);
	printf("\n");
#endif
    }
}
