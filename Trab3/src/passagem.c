#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "structs.h"
#include "prototipos.h"



	int confere_passagem (int dia, int mes, int ano, int diaf, int mesf, int anof, int dias, int pessoas, char *l_o, char *l_d, TipoListaVoo *voo, TipoListaPacote *pacote)
	{
		int aux=0, tem=1, j=0, valor_ant=900000,conf=0;
		int data,dataf,data2,data2f;
		TipoApontadorVoo q;
		q=voo->Frente;
		data=transforma_data(dia,mes,ano); 
		dataf=transforma_data(diaf,mesf,anof); 
		pacote->Tras->Prox = (TipoApontadorPacote) malloc (sizeof(TipoCelulaPacote));
		pacote->Tras = pacote->Tras->Prox;
		pacote->Tras->Prox = NULL;
		//printf (">>>%s\n",q->Prox->Voo.cia_aerea);
		if (q->Prox==NULL)
			return 0;
		while (aux==0)
		{
			while (tem!=0 && q!=NULL)
			{
				q=q->Prox;
				tem=strcmp(q->Voo.origem,l_o);
			}
						if ((tem==0)&&(strcmp(q->Voo.destino,l_d)==0))
						{
							tem=1;
							data2=transforma_data(q->Voo.dt_ida_dia,q->Voo.dt_ida_mes,q->Voo.dt_ida_ano);
							data2f=transforma_data(q->Voo.dt_chegada_dia,q->Voo.dt_chegada_mes,q->Voo.dt_chegada_ano);
							if ((data2>=data) && (data2<=dataf-(dias-1)) && (data2f>=data+(dias-1)) && (data2f<=dataf))
							{
								if (q->Voo.qtdd_lugar_disp_v>=pessoas)
								{
									if (q->Voo.valor_v<valor_ant)
									{
										pacote->Tras->Pacote.id_v=q->Voo.id_v;
										valor_ant=q->Voo.valor_v;
										conf=1;
									}
									if (conf==0)
									{
										printf("Não há como viajar no período de tempo proposto pelo cliente!");
										aux=1;
									}
								}
							}
						}
						else 
						{ 
							if (tem)
							{
								printf("Não foi encontrada passagens a partir da cidade em questão!");
								aux=1;
							}
							else
							{
								if (j==dias)
								{
									printf("Não foi encontrada passagens para a cidade destino em questão!");
									aux=1;
								}
							}
						j++;
					}
				if (conf==1)
					return q->Voo.id_v;
				else
					return 0;
			}
			return 0;
		}
			
			int confere_hotel (TipoListaHotel *hotel, char cidade[], int pessoas, TipoListaPacote *pacote)
			{
				int tem=1,conf=0;
				TipoApontadorHotel q;
				int valor_ant=900000;
				q=hotel->Frente;
				if (q->Prox==NULL)
					return 0;
				while (q->Prox!=NULL)
				{
					while (q->Prox!=NULL && tem!=0)
					{
						q=q->Prox;
						tem=strcmp(q->Hotel.cidade_h, cidade);
					}
					if (tem==0 && q->Hotel.qtdd_qtos_disp>=pessoas) 
					{
						tem=1;
							if (q->Hotel.valor_h<valor_ant) 
							{
								pacote->Tras->Pacote.id_h=q->Hotel.id_h;
								valor_ant=q->Hotel.valor_h;
								conf=1;
							}
					}
				}
				if (conf==1)
					return q->Hotel.id_h;
				else {
					printf("Não foi possível encotrar hotéis disponíveis na cidade desejada!");
					printf("\nPressione enter para continuar!");
					getchar();
					return 0;
				}
			}
			
			int confere_passeio(TipoPilhaPasseio *passeio, char cidade[], int dia, int mes, int ano, int diaf, int mesf, int anof, int pessoas,TipoListaPacote *pacote)
			{
				int tem,data,dataf,data2,conf=0,num;
				TipoApontadorPilha q;
				q=passeio->Frente;
				data=transforma_data(dia, mes, ano);
				dataf=transforma_data(diaf,mesf,anof);
				if (q->Prox==NULL)
					return 0;
				while (q->Prox!=NULL) {
					while(q->Prox!=NULL && tem!=0)
					{
						q=q->Prox;
						tem=strcmp(q->Passeio.cidade, cidade);
					}
					if (tem==0 && q->Passeio.qtdd_lugar_disp_p>=pessoas)
					{
						data2=transforma_data(q->Passeio.dt_ida_dia_p,q->Passeio.dt_ida_mes_p,q->Passeio.dt_ida_ano_p);
						if (data2>=data && data2<=dataf) 
						{
								printf("A agência de turismo é %s", q->Passeio.ag_turismo);
								printf("O nome do passeio é %s", q->Passeio.nome_p);
								printf("A data do passeio é %d %d %d\n", q->Passeio.dt_ida_dia_p, q->Passeio.dt_ida_mes_p, q->Passeio.dt_ida_ano_p);
								printf("O horário do passeio é %s", q->Passeio.hr_ida);
								printf("O valor do passeio é %d\n", q->Passeio.valor_p);
								printf("Deseja comprar este passeio? 1.y|2.n   ");
								scanf("%d", &num);
								getchar();
								if (num==1)
								{
									pacote->Tras->Pacote.id_p=q->Passeio.id_p;
									return q->Passeio.id_p;
								}
						}
					}
				}
				if (conf==1)
					return q->Passeio.id_p;
				else
					return 0;
			}
						
								
