#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "structs.h"
#include "prototipos.h"

	void inclui_hotel(TipoListaHotel *hotel)
	{
		char nome_h[100];
		int aux=0, tem=1,num,id_ant;
		TipoApontadorHotel h;
		system ("clear");
		printf("Digite o nome: ");
		fgets(nome_h, 52, stdin);
		valida_nome(nome_h);
		h=Busca_nome(nome_h, hotel);
		while (aux==0)
		{
						if (h==NULL)
						{
							if (hotel->Frente->Prox==NULL)
								tem=0;
							else
								id_ant=hotel->Tras->Hotel.id_h;
							hotel->Tras->Prox = (TipoApontadorHotel) malloc (sizeof(TipoCelulaHotel));
							hotel->Tras=hotel->Tras->Prox;
							hotel->Tras->Prox=NULL;
							if (tem==0)
								hotel->Tras->Hotel.id_h=1;
							else
								hotel->Tras->Hotel.id_h=id_ant+1;
							strcpy(hotel->Tras->Hotel.nome_h, nome_h);
							printf("Digite o endereço: ");
							fgets(hotel->Tras->Hotel.end_h, 102, stdin);
							valida_endereco(hotel->Tras->Hotel.end_h);
							printf("Digite a cidade: ");
							fgets(hotel->Tras->Hotel.cidade_h, 22, stdin);
							valida_cidade(hotel->Tras->Hotel.cidade_h);
							printf("Digite o valor das diárias (sem utilizar centavos): ");
							scanf("%d", &hotel->Tras->Hotel.valor_h);
							getchar();
							printf("Digite a quantidade de quartos disponíveis: ");
							scanf("%d", &hotel->Tras->Hotel.qtdd_qtos_disp);
							getchar();
							aux=1;
							return;
						}
						else
						{
							printf("O hotel já encontra-se cadastrado!\n");
							printf("Deseja sair do modo inclui hotel? 1.y|2.n  ");
							scanf("%d", &num);
							getchar();
							if (num==2)
							{
								printf("Digite o nome: ");
								fgets(nome_h, 100, stdin);
								valida_nome(nome_h);
								h=Busca_nome(nome_h, hotel);
							}
							else								
								aux=1;
						}
		}
	}

	void altera_dado_hotel(TipoListaHotel *hotel)
	{
		int num_e, aux=0, num, diaria,quartos;
		char nome[20];
		TipoApontadorHotel h;
		system("clear");
		printf("Digite o o nome do hotel que deseja alterar os dados: ");
		fgets(nome, 20, stdin);
		while (aux==0)
		{
			if (nome[0]!='\n')
			{		
				h=Busca_hotel(nome,hotel);
				if (h!=NULL)
				{
					system("clear");
					printf("Qual dado deseja alterar?\n\n1.Nome\n2.Endereço\n3.Cidade\n4.Valor das diáriias\n5.Quantidade de quartos disponíveis\n\n6.Digite sua opção: ");
					scanf("%d", &num_e);
					getchar();
					while (aux==0 && num_e<6)
					{
						if (num_e==1)
						{
							system("clear");
							printf("Nome\n");
							printf("Digite o novo Nome: ");
							fgets(h->Prox->Hotel.nome_h, 20, stdin);
						}
						if (num_e==2)
						{
							system("clear");
							printf("Endereço\n");
							printf("Digite o novo endereço: ");
							fgets(h->Prox->Hotel.end_h, 102, stdin);
							valida_endereco(h->Prox->Hotel.end_h);
						}
						if (num_e==3)
						{
							system("clear");
							printf("Cidade\n");
							printf("Digite a nova cidade: ");
							fgets(h->Prox->Hotel.cidade_h, 102, stdin);
							valida_endereco(h->Prox->Hotel.cidade_h);
						}
						if (num_e==4)
						{
							system("clear");
							printf("Valor das diárias\n");
							printf("Digite o novo valor das diárias: ");
							scanf("%d", &diaria);
							getchar();
							valida_quantidade(diaria);
							h->Prox->Hotel.valor_h=diaria;
						}
						if (num_e==5)
						{
							system("clear");
							printf("Quantidade de quartos disponíveis\n");
							printf("Digite a nova quantidade de quartos: ");
							scanf("%d", &quartos);
							getchar();
							valida_quantidade(quartos);
							h->Prox->Hotel.qtdd_qtos_disp=quartos;
						}
						system("clear");
						printf("Deseja alterar mais algum dado?\n\n1.Nome\n2.Endereço\n3.Cidade\n4.Valor das diáriias\n5.Quantidade de quartos disponíveis\n6. Voltar\n\nDigite sua opção: ");
						scanf("%d", &num_e);
						getchar();
					}
					aux=1;
					system("clear");
					printf("Os dados do hotel foram alterados!\n\n");
					printf("Pressione enter para voltar!\n");
					getchar();
				}
				else
				{
					if (h==NULL)
					{
						system("clear");
						printf("O Nome digitado não esta cadastrado!");
						printf("Deseja sair do modo altera dado hotel?(Digite o número)  1.y | 2.n  \n");
						scanf("%d", &num);
						getchar();
						if (num==2)
						{
							system("clear");
							printf("Digite o Nome novamente: ");
							fgets(nome, 20, stdin);
						}
						else
							aux=1;
					}
					else
					{
						system("clear");
						printf("Nome de hotel não válido!\n\n");
						printf("Digite o nome novamente: ");
						fgets(nome, 20, stdin);
					}
				}
			}
			else
			{
				printf("Deseja sair do modo altera dados? 1.y | 2.n");
				scanf("%d",&num);
				getchar();
				if (num==2)
				{
					system("clear");
					printf("Digite o nome novamente: ");
					fgets(nome, 20, stdin);
				}
				else
					aux=1;
			}
		}
	}
	
	void exclui_hotel(TipoListaHotel *hotel)
	{
		int valido;
		char coisa[102];
		TipoCelulaHotel *item;
		TipoApontadorHotel q;
		system("clear");
		printf("Digite o nome do hotel que deseja excluir: ");
		fgets(coisa, 52, stdin);
		valido = valida_hotel (coisa);
		if (valido != 0) {
			item = Busca_hotel (coisa,hotel);
			if (item != NULL) {
				q=item->Prox;
				item->Prox = item->Prox->Prox;
				free (q);
				printf ("Hotel excluido com sucesso!");
				getchar ();
				return;
			}
			else {
				printf ("Hotel nao encontrado!\n");
				getchar ();
				return;
			}
		}
		else {
			printf ("Nome invalido!\n");
			getchar ();
			return;
		}
	}
