#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "structs.h"
#include "prototipos.h"

	void inclui_voo(TipoListaVoo *voo)
	{
		TipoApontadorVoo q;
		int aux=0,tem=1,dia,mes,ano,tem2,tem3,num, id_ant;
		system("clear");
		if (voo->Frente->Prox==NULL)
			tem=0;
		else
			id_ant=voo->Tras->Voo.id_v;
		voo->Tras->Prox = (TipoApontadorVoo) malloc (sizeof(TipoCelulaVoo));
		voo->Tras=voo->Tras->Prox;
		if (tem==0)
			voo->Tras->Voo.id_v=1;
		else
			voo->Tras->Voo.id_v=id_ant+1;
		while (aux==0)
		{
				printf("Digite companhia aérea: ");
				fgets(voo->Tras->Voo.cia_aerea, 50, stdin);
				printf("Digite a cidade de destino: ");
				fgets(voo->Tras->Voo.destino, 100, stdin);
				valida_nome(voo->Tras->Voo.destino);
				printf("Digite a cidade de origem: ");
				fgets(voo->Tras->Voo.origem, 22, stdin);
				valida_cidade(voo->Tras->Voo.origem);
				printf("Digite o horário de partida do voo: ");
				fgets(voo->Tras->Voo.hr_ida, 50, stdin);
				printf("Digite o horário de chegada do voo: ");
				fgets(voo->Tras->Voo.hr_chegada, 50, stdin);
				printf("Digite a data de ida (dia mes ano): ");
				scanf("%d %d %d", &dia, &mes, &ano);
				valida_quantidade(dia);
				valida_quantidade(mes);
				valida_quantidade(ano);
				while (valida_data(dia, mes, ano)==1)
				{
					printf("Data incorreta, digite novamente: ");
					scanf("%d %d %d", &dia, &mes, &ano);
					getchar();
					valida_quantidade(dia);
					valida_quantidade(mes);
					valida_quantidade(ano);
				}
				voo->Tras->Voo.dt_ida_dia=dia;
				voo->Tras->Voo.dt_ida_mes=mes;
				voo->Tras->Voo.dt_ida_ano=ano;
				printf("Digite a data de volta: ");
				scanf("%d %d %d", &dia, &mes, &ano);
				valida_quantidade(dia);
				valida_quantidade(mes);
				valida_quantidade(ano);
				while (valida_data(dia, mes, ano)==1)
				{
					printf("Data incorreta, digite novamente: ");
					scanf("%d %d %d", &dia, &mes, &ano);
					getchar();
					valida_quantidade(dia);
					valida_quantidade(mes);
					valida_quantidade(ano);
				}
				voo->Tras->Voo.dt_chegada_dia=dia;
				voo->Tras->Voo.dt_chegada_mes=mes;
				voo->Tras->Voo.dt_chegada_ano=ano;
				q=voo->Frente;
				while (q->Prox!=NULL)
				{
					tem=strcmp(voo->Tras->Voo.cia_aerea,q->Voo.cia_aerea);
					if (voo->Tras->Voo.dt_chegada_dia==q->Voo.dt_chegada_dia && voo->Tras->Voo.dt_chegada_mes==q->Voo.dt_chegada_mes && voo->Tras->Voo.dt_chegada_ano==q->Voo.dt_chegada_ano)
					{
						tem2=strcmp(voo->Tras->Voo.hr_ida, q->Voo.hr_ida);
						tem3=strcmp(voo->Tras->Voo.hr_chegada, q->Voo.hr_chegada);
					}
					q=q->Prox;
				}
				if (tem==0 && tem2==0 && tem3==0)
					aux=0;
				else
					aux=1;
			if (aux==0)
			{
				printf("O voo já esta cadastrado!\n");
				printf("Deseja continuar no modo inclui voo? 1.y|2.n  ");
				scanf("%d", &num);
				getchar();
				if (num==2)
				{
					q=voo->Tras;
					voo->Tras=voo->Tras->Prox;
					voo->Tras->Prox=NULL;
					free(q);
					aux=2;
				}
			}
			if (aux==1)
			{
				printf("Digite o valor das passagens: ");
				scanf("%d", &voo->Tras->Voo.valor_v);
				getchar();
				printf("Digite a quantidade de lugares: ");
				scanf("%d", &voo->Tras->Voo.qtdd_lugar_disp_v);
				getchar();
			}
		}
	}

void altera_dado_voo(TipoListaVoo *voo) //ver
	{
		int valido=0,opcao;
		char coisa[102];
		TipoCelulaVoo *item;
		system("clear");
		printf("Digite a companhia do voo que deseja alterar os dados: ");
		fgets(coisa, 52, stdin);
		if (valido == 0) {
			item = Busca_companhia (coisa,voo); //>>>>>>>>ATENCAO RETORNA POSICAO ANTERIOR DO QUE A QUE EU PEDI<<<<<<<<<<
			if (item != NULL) {
				printf ("Companhia encontrada!");
				do {
					printf ("\nO que deseja alterar?\n\n1. Companhia aérea\n2. Destino\n3. Origem\n4. Data ida\n5. Data volta\n6. Valor da passagem\n7. Quantidade de lugares\n8. Voltar\nOpcao: ");
					scanf ("%d",&opcao);
					getchar ();
					switch (opcao) {
						case 1:
							printf ("Digite o novo nome da cia: ");
							fgets (coisa,52,stdin);
							strcpy (item->Prox->Voo.cia_aerea,coisa);
							printf ("Nome da cia alterado com sucesso!\n");
							getchar ();
							break;
						case 2:
							printf ("Digite o novo destino: ");
							fgets (coisa,22,stdin);
							strcpy (item->Prox->Voo.destino,coisa);
							printf ("Destino alterado com sucesso!\n");
							getchar ();
							break;
						case 3:
							printf ("Digite a nova origem: ");
							fgets (coisa,22,stdin);
							strcpy (item->Prox->Voo.origem,coisa);
							printf ("Origem alterada com sucesso!\n");
							getchar ();
							break;
						case 4:
							printf ("Digite a nova data de ida (dia mes ano): ");
							scanf ("%d %d %d",&item->Prox->Voo.dt_ida_dia,&item->Prox->Voo.dt_ida_mes,&item->Prox->Voo.dt_ida_ano);
							getchar ();
							printf ("Data de ida alterada com sucesso!\n");
							getchar ();
							break;
						case 5:
							printf ("Digite a nova data de volta(dia mes ano): ");
							scanf ("%d %d %d",&item->Prox->Voo.dt_chegada_dia,&item->Prox->Voo.dt_chegada_mes,&item->Prox->Voo.dt_chegada_ano);
							getchar ();
							printf ("Data de volta alterada com sucesso!\n");
							getchar ();
							break;
						case 6:
							printf ("Digite o novo valor da passagem: ");
							scanf ("%d",&item->Prox->Voo.valor_v);
							printf ("Valor alterado com sucesso!\n");
							getchar ();
							break;
						case 7:
							printf ("Digite o novo numero de lugares: ");
							scanf ("%d",&item->Prox->Voo.qtdd_lugar_disp_v);
							printf ("Numero de lugares alterado com sucesso!\n");
							getchar ();
							break;
						case 8:
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
				printf ("Companhia nao encontrado!");
				getchar ();
				return;
			}
		}
		else {
			printf ("Companhia invalido!\n");
			getchar ();
		}
	}
	
	void exclui_voo(TipoListaVoo *voo) { 
	TipoApontadorVoo q,q_prox, p;
	int tem=1,tem5=1;
	char cia[50],hr_ida[50];
	system("clear");
	printf("Digite a companhia do voo que deseja excluir: ");
	fgets(cia, 50, stdin);
	printf("Digite a hora do voo que deseja excluir: ");
	fgets(hr_ida, 50, stdin);
		q_prox=voo->Frente;
		while ((q_prox!=NULL)&&((tem!=0)||(tem5!=0)))	
		{
			q=q_prox;
			q_prox=q_prox->Prox;
			tem=strcmp(q_prox->Voo.cia_aerea, cia);
			tem5=strcmp(q_prox->Voo.hr_ida, hr_ida);
		}
		if ((tem==0)&&(tem5==0)) {
			p=q->Prox;
			q->Prox = q->Prox->Prox;
			free (p);
			printf ("Voo excluido com sucesso!");
			getchar ();
			return;
		}
		else {
			printf ("Voo nao encontrado!\n");
			getchar ();
			return;
		}
}
