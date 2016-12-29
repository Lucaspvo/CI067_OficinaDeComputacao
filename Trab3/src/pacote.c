#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "structs.h"
#include "prototipos.h"

int confere_passagem(int , int , int , int , int , int , int , int , char *, char *, TipoListaVoo *, TipoListaPacote *);

	void cria_pacote_turistico(TipoListaVoo *voo, TipoListaPacote *pacote, TipoListaHotel *hotel, TipoPilhaPasseio *passeio)
	{
		TipoApontadorHotel q;
		TipoApontadorVoo p;
		TipoApontadorPilha pa;
		int pasg;
		int hot;
		int pas;
		int dia, mes, ano, diaf, mesf, anof, dias, pessoas, num, conf,j;
		char l_origem[22], l_destino[22];
		system ("clear");
		printf("Digite o período que deseja viajar!");
		printf("\nData inicial (dia mes ano): ");
		scanf("%d %d %d", &dia, &mes, &ano);
		getchar();
		valida_quantidade(dia);
		valida_quantidade(mes);
		valida_quantidade(ano);
		while (valida_data(dia, mes, ano)==1)
		{
			printf("Data incorreta, digite novamente (dia mes ano): ");
			scanf("%d %d %d", &dia, &mes, &ano);
			getchar();
			valida_quantidade(dia);
			valida_quantidade(mes);
			valida_quantidade(ano);
		}
		printf("Data final (dia mes ano): ");
		scanf("%d %d %d", &diaf, &mesf, &anof);
		getchar();
		valida_quantidade(diaf);
		valida_quantidade(mesf);
		valida_quantidade(anof);
		while (valida_data(diaf, mesf, anof)==1)
		{
			printf("Data incorreta, digite novamente (dia mes ano): ");
			scanf("%d %d %d", &diaf, &mesf, &anof);
			getchar();
			valida_quantidade(diaf);
			valida_quantidade(mesf);
			valida_quantidade(anof);
		}
		printf("Digite a quantidade de dias que deseja viajar: ");
		scanf("%d", &dias);
		getchar();
		valida_quantidade(dias);
		printf("Digite a quantidade de pessoas que vão viajar (incluindo o cliente): ");
		scanf("%d", &pessoas);
		getchar();
		valida_quantidade(pessoas);
		printf("Digite o local de origem: ");
		fgets(l_origem, 22, stdin);
		conf=valida_cidade(l_origem);
			while (conf==0)
			{
				system("clear");
				printf("O nome da cidade foi digitado incorretamente!");
				printf("Digite o nome da cidade novamente: ");
				fgets(l_origem, 22, stdin);
				j=0;
				conf=1;
				while ((conf!=0) && (l_origem[j]!='\n'))
				{
					conf=isalpha(l_origem[j]);
					j++;
				}
			}
		printf("Digite o local de destino: ");
		fgets(l_destino, 22, stdin);
		conf=valida_cidade(l_destino);
			while (conf==0)
			{
				system("clear");
				printf("O nome da cidade foi digitado incorretamente!");
				printf("Digite o nome da cidade novamente: ");
				fgets(l_destino, 22, stdin);
				j=0;
				conf=1;
				while ((conf!=0) && (l_destino[j]!='\n'))
				{
					conf=isalpha(l_destino[j]);
					j++;
				}
			}
		pasg=confere_passagem(dia, mes, ano, diaf, mesf, anof, dias, pessoas, l_origem, l_destino, voo, pacote);
		if (pasg!=0)
		{
			hot=confere_hotel(hotel, l_destino, pessoas, pacote);
			if (hot!=0)
			{
				q=hotel->Frente;
				p=voo->Frente;
				conf=1;
				while(q!=NULL && conf!=0 && p!=NULL)
				{
					if (pacote->Tras->Pacote.id_h!=q->Hotel.id_h) 
						q=q->Prox;
					if  (pacote->Tras->Pacote.id_v!=p->Voo.id_v)
						p=p->Prox;
					if ((pacote->Tras->Pacote.id_h==q->Hotel.id_h)&&(pacote->Tras->Pacote.id_v==p->Voo.id_v))
						conf=0;
				}
				if (conf==0)
				{
					system("clear");
					printf("Data ida (dia mes ano): %d %d %d\n", p->Voo.dt_ida_dia, p->Voo.dt_ida_mes, p->Voo.dt_ida_ano);
					printf("Data volta (dia mes ano): %d %d %d\n", p->Voo.dt_chegada_dia, p->Voo.dt_chegada_mes, p->Voo.dt_chegada_ano);
					printf("Valor Total: R$%d,00\n", (((q->Hotel.valor_h*dias)+p->Voo.valor_v)*pessoas));
					printf("Informações Voo:\n");
					printf("Lugar de destino: %s\n", p->Voo.destino);
					printf("Hora ida: %s\nHora chegada: %s\n", p->Voo.hr_ida, p->Voo.hr_chegada);
					printf("Informações Hotel:\n");
					printf("Nome do Hotel: %s\n", q->Hotel.nome_h);
					printf("Endereço do Hotel: %s\n", q->Hotel.end_h);
					printf("Quartos disponiveis: %d\n", q->Hotel.qtdd_qtos_disp);
					printf("Deseja adicionar passeios? 1.y|2.n  ");
					scanf("%d", &num);
					getchar();
				}
				if (num==1) 
				{
					pas=confere_passeio(passeio, l_destino, dia, mes, ano, diaf, mesf, anof, pessoas,pacote); //TipoPilhaPasseio *passeio, char cidade[], int dia, int mes, int ano, int diaf, int mesf, int anof, int pessoas
					if (pas!=0)
					{
							pa=passeio->Frente;
							conf=1;
							while(pa->Prox!=NULL && conf!=0)
							{
								pa=pa->Prox;
								if (pacote->Tras->Pacote.id_p==pa->Passeio.id_p)
									conf=0;
							}
							system("clear");
							printf("Passeio: %s\n", pa->Passeio.nome_p);
							printf("Data do passeio (dia mes ano): %d %d %d\n", pa->Passeio.dt_ida_dia_p, pa->Passeio.dt_ida_mes_p, pa->Passeio.dt_ida_ano_p);
							printf("Horário de ida: %s\n", pa->Passeio.hr_ida);
							printf("Horário de volta: %s\n", pa->Passeio.hr_chegada);
							printf("Valor do passeio (por pessoa): R$%d,00\n", pa->Passeio.valor_p);
							printf("Deseja adicionar este passeio? 1.y|2.n  ");
							scanf("%d", &num);
							getchar();
							system("clear");
							printf("Valor Total: R$%d,00\n", (((q->Hotel.valor_h*dias)+p->Voo.valor_v+pa->Passeio.valor_p)*pessoas));
							printf("Deseja efetuar a compra deste pacote? 1.y|2.n  ");
							scanf("%d", &num);
							getchar();
							if (num==1)
							{
								p->Voo.qtdd_lugar_disp_v = p->Voo.qtdd_lugar_disp_v - pessoas;
								q->Hotel.qtdd_qtos_disp = q->Hotel.qtdd_qtos_disp - pessoas;
								pa->Passeio.qtdd_lugar_disp_p = pa->Passeio.qtdd_lugar_disp_p-pessoas;
							}
					}
					else
					{
						printf("Não existe passeio disponível!\n");
						printf("Pressione enter para continuar!");
						getchar();
					}
				}
				else
				{
					printf("Deseja comprar o pacote sem passeio? 1.y\n2.n  ");
					scanf("%d", &num);
					getchar();
					if (num==1)
					{
								p->Voo.qtdd_lugar_disp_v = p->Voo.qtdd_lugar_disp_v - pessoas;
								q->Hotel.qtdd_qtos_disp = q->Hotel.qtdd_qtos_disp - pessoas;
					}
				}
			}
			else
			{
				printf("Não existem Hotéis disponíveis no período desejado!");
				printf("Pressione enter para continuar!");
				getchar();
			}
		}
		else
		{
			printf("Não existem Voos disponíveis no período desejado!\n");
			printf("Pressione enter para continuar!");
			getchar();
		}
	}
							
			
