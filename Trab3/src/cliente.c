#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "structs.h"
#include "prototipos.h"

	void inclui_cliente(int status,char cpf[], TipoListaCliente *lista)
	{
		system ("clear");
		TipoApontadorCliente cadastro;
		cadastro = Busca_cpf (cpf, lista);
				if (cadastro == NULL)
				{
						lista->Tras->Prox = (TipoApontadorCliente) malloc (sizeof(TipoCelulaCliente));
						lista->Tras=lista->Tras->Prox;
						strcpy(lista->Tras->Cliente.cpf, cpf);
						printf("Digite o nome: ");
						fgets(lista->Tras->Cliente.nome_c, 100, stdin);
						printf("Digite o endereço: ");
						fgets(lista->Tras->Cliente.end_c, 100, stdin);
						printf("Digite o telefone: ");
						fgets(lista->Tras->Cliente.telefone_c, 14, stdin);
						valida_telefone(lista->Tras->Cliente.telefone_c);
						printf("Digite o e-mail: ");
						fgets(lista->Tras->Cliente.email_c, 30, stdin);
						lista->Tras->Cliente.status_c=status;
						printf ("Cliente adicionado com sucesso!");
						getchar ();
						return;
				}
				else
				{
					printf("O cliente já está cadastrado!");
				}
	}

	void altera_dado_cliente(char cpf[],TipoListaCliente *lista) //ver
	{
		int opcao;
		char coisa[102];
		TipoCelulaCliente *item;
		system("clear");
			item = Busca_cpf (cpf,lista); //>>>>>>>>ATENCAO RETORNA POSICAO ANTERIOR DO QUE A QUE EU PEDI<<<<<<<<<<
			if ((item!=NULL)||(item->Prox!=NULL)) {
				printf ("Cliente encontrado!");
				do {
					printf ("\nO que deseja alterar?\n\n1. Nome\n2. Endereco\n3. Telefone\n4. Email\n5. Voltar\nOpcao: ");
					scanf ("%d",&opcao);
					getchar ();
					switch (opcao) {
						case 1:
							printf ("Digite o novo nome: ");
							fgets (coisa,102,stdin);
							strcpy (item->Prox->Cliente.nome_c,coisa);
							printf ("Nome alterado com sucesso!\n");
							getchar ();
							break;
						case 2:
							printf ("Digite o novo endereco: ");
							fgets (coisa,102,stdin);
							strcpy (item->Prox->Cliente.end_c,coisa);
							printf ("Nome alterado com sucesso!\n");
							getchar ();
							break;
						case 3:
							printf ("Digite o novo telefone: ");
							fgets (coisa,15,stdin);
							strcpy (item->Prox->Cliente.telefone_c,coisa);
							printf ("Telefone alterado com sucesso!\n");
							getchar ();
							break;
						case 4:
							printf ("Digite o novo email: ");
							fgets (coisa,32,stdin);
							strcpy (item->Prox->Cliente.email_c,coisa);
							printf ("Email alterado com sucesso!\n");
							getchar ();
							break;
						case 5:
							return;
							break;
						default:
							printf ("Opcao invalida!\n");
							getchar ();
							break;
					}
				}while (opcao != 5);
			}
			else {
				printf ("Cliente nao encontrado!");
				getchar ();
				return;
			}
	}
	
	
void exclui_cliente(char *cpf,TipoListaCliente *lista) {
	char coisa[102];
	TipoCelulaCliente *item;
	TipoApontadorCliente q;
	system("clear");
		item = Busca_cpf (coisa,lista);
		if (item != NULL) {
			q=item->Prox;
			item->Prox = item->Prox->Prox;
			free (q);
			printf ("Cliente excluido com sucesso!");
			getchar ();
			return;
		}
		else {
			printf ("Cliente nao encontrado!\n");
			getchar ();
			return;
		}
}
