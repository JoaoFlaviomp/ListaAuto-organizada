#include<stdio.h>
#include<stdlib.h>

typedef struct sContatos
{
	int numero,id;
	char nome[30];
}Contatos;

typedef struct sNo
{
	Contatos dados;
	struct sNo *prox;
}No;

No *Inicia(No *lista)
{
	lista=NULL;
	return lista;
}

No *alocarNo()
{
	return (No*)malloc(sizeof(No));
}

void desalocarNo(No *lista)
{
	free(lista);
}

int Lista_Vazia(No *lista)
{
	if(lista==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

Contatos Ler_Dados()
{
	Contatos dados;
	printf("Digite o nome do contato:\n");
	gets(dados.nome);
	printf("Digite o id do contato:\n");
	scanf("%d",&dados.id);
	printf("Digite o numero do contato:\n");
	scanf("%d",&dados.numero);
	return dados;
}

void Imprime_Dados(Contatos dados)
{
	printf("Nome do contato:%s\n",dados.nome);
	printf("ID do contato:%d\n",dados.id);
	printf("Numero do contato:%d\n",dados.numero);
	printf("\n");
}

No *Insere_Ordenado(No *lista)
{
	No *anterior;
	No *aux;
	No *novo=alocarNo();
	if(novo!=NULL)
	{
		novo->dados=Ler_Dados();
		novo->prox=NULL;
		aux=lista;
		while(aux!=NULL && aux->dados.id<novo->dados.id)
		{
			anterior=aux;
			aux=aux->prox;
		}
		if(aux==lista)
		{
			novo->prox=lista;
			lista=novo;
			return lista;
		}
		else
		{
			anterior->prox=novo;
			novo->prox=aux;
			return lista;
		}
	}
	else
	{
		return NULL;
	}
}

No *Pesquisar(No *lista,int id)
{
	No *aux;
	if(Lista_Vazia(lista))
	{
		return NULL;
	}
	else
	{
		aux=lista;
		while(aux!=NULL)
		{
			if(aux->dados.id==id)
			{
				return aux;
			}
			else
			{
				aux=aux->prox;
			}
		}
	}
}

No *Remover_Inicio(No *lista)
{
	No *aux;
	if(Lista_Vazia(lista))
	{
		printf("Lista vazia!\n");
		return NULL;
	}
	else
	{
		aux=lista;
		lista=aux->prox;
		desalocarNo(aux);
		return lista;
	}
}

No *Remover_Valor(No *lista)
{
	No *aux;
	No *elem;
	int id;
	printf("Digite o id do contato:\n");
	scanf("%d",&id);
	if((elem=Pesquisar(lista,id))!=NULL)
	{
		aux=lista;
		if(aux==elem)
		{
			Remover_Inicio(lista);
		}
		else
		{
			while(aux->prox!=elem)
			{
				aux=aux->prox;
			}
			aux->prox=elem->prox;
			desalocarNo(elem);
			return lista;
		}
	}
	else
	{
		return NULL;
	}
}

No *Mover_Frente(No *lista)
{
	No *aux;
	No *anterior=NULL;
	No *elem;
	int id;
	printf("Digite o id do contato:\n");
	scanf("%d",&id);
	if((elem=Pesquisar(lista,id))!=NULL)
	{
		aux=lista;
		if(aux==elem)
		{
			return lista;
		}
		else
		{
			while(aux->prox!=NULL)
			{
				anterior=aux;
				aux=aux->prox;
			}
			anterior->prox=aux->prox;
			aux->prox=lista;
			lista=aux;
			return lista;
		}
	}
	else
	{
		return NULL;
	}
}

No *Transposicao(No *lista)
{
	int num;
	printf("Digite o id do contato:\n");
	scanf("%d",&num);
	No *anterior;
	No *anterior2;
	No *elem;
	if((elem=Pesquisar(lista,num))!=NULL)
	{
		anterior=lista;
		if(anterior==elem)
		{
			return lista;
		}
		else
		{
			while(anterior->prox!=elem)
			{
				anterior=anterior->prox;
			}
			anterior2=lista;
			if(anterior2==anterior)
			{
				anterior->prox=elem->prox;
				elem->prox=anterior;
				lista=elem;
				return lista;
			}
			else
			{
				while(anterior2->prox!=anterior)
				{
					anterior2=anterior2->prox;
				}
				anterior->prox=elem->prox;
				elem->prox=anterior;
				anterior2->prox=elem;
				return lista;
			}
		}
	}
	else
	{
		return NULL;
	}
}

void Imprime_Lista(No *lista)
{
	while(lista!=NULL)
	{
		Imprime_Dados(lista->dados);
		lista=lista->prox;
	}
	printf("\n");
}
