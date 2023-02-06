#include "Transposicao.h"

int main()
{
	int opcao;
	No *ptrLista=Inicia(ptrLista);
	do
	{
		printf("0-Sair\n1-Inserir ordenado\n2-Transposicao\n3-Imprimir\n");
		scanf("%d",&opcao);
		fflush(stdin);
		switch(opcao)
		{
			case 1:
			{
				ptrLista=Insere_Ordenado(ptrLista);
				break;
			}
			case 2:
			{
				ptrLista=Transposicao(ptrLista);
				break;
			}
			case 3:
			{
				Imprime_Lista(ptrLista);
				break;
			}
			default:
			{
				if(opcao!=0)
				{
					printf("Opcao invalida!\n");
				}
			}
		}	
	}while(opcao!=0);
	desalocarNo(ptrLista);
	ptrLista=NULL;
	return 0;
}
