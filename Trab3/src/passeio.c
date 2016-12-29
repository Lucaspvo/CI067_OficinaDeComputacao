#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "structs.h"
#include "prototipos.h"

	void inclui_passeio(TipoPilhaPasseio *passeio)
	{
		int id_ant, tem;
		if (passeio->Frente->Prox==NULL)
			tem=0;
		else
			id_ant=passeio->Tras->Passeio.id_p;
		passeio->Tras->Prox = (TipoApontadorPilha) malloc (sizeof(TipoCelulaPasseio));
		passeio->Tras=passeio->Tras->Prox;
		passeio->Tras->Prox=NULL;
		if (tem==0)
			passeio->Tras->Passeio.id_p=1;
		else
			passeio->Tras->Passeio.id_p=id_ant+1;
		system("clear");
		printf("Digite o nome da agencia: ");
		fgets(passeio->Tras->Passeio.ag_turismo, 22, stdin);
		valida_nome(passeio->Tras->Passeio.ag_turismo);
		printf("Digite o nome do passeio: ");
		fgets(passeio->Tras->Passeio.nome_p, 102, stdin);
		valida_nome(passeio->Tras->Passeio.nome_p);
		printf("Digite a cidade: ");
		fgets(passeio->Tras->Passeio.cidade, 22, stdin);
		valida_cidade(passeio->Tras->Passeio.cidade);
		printf("Digite a data (dia mes ano): ");
		scanf ("%d %d %d",&passeio->Tras->Passeio.dt_ida_dia_p,&passeio->Tras->Passeio.dt_ida_mes_p,&passeio->Tras->Passeio.dt_ida_ano_p);
		getchar ();
		valida_data(passeio->Tras->Passeio.dt_ida_dia_p,passeio->Tras->Passeio.dt_ida_mes_p,passeio->Tras->Passeio.dt_ida_ano_p);
		printf("Digite o horario de ida: ");
		fgets(passeio->Tras->Passeio.hr_ida, 8, stdin);
		printf("Digite o horario de volta: ");
		fgets(passeio->Tras->Passeio.hr_chegada, 8, stdin);
		printf("Digite o valor: ");
		scanf ("%d",&passeio->Tras->Passeio.valor_p);
		getchar ();
		printf("Digite o numero de lugares disponiveis: ");
		scanf ("%d",&passeio->Tras->Passeio.qtdd_lugar_disp_p);
		getchar ();
	}

	void altera_dado_passeio(TipoPilhaPasseio *passeio) //ver
	{
		int opcao;
		char coisa[102];
		TipoCelulaPasseio *item;
		system("clear");
		printf("Digite o nome do passeio que deseja alterar os dados: ");
		fgets(coisa, 102, stdin);
			item = Busca_passeio (coisa,passeio); //>>>>>>>>ATENCAO RETORNA POSICAO ANTERIOR DO QUE A QUE EU PEDI<<<<<<<<<<
			if (item != NULL) {
				printf ("Passeio encontrado!");
				do {
					system ("clear");
					printf ("\nO que deseja alterar?\n\n1. Nome da agencia\n2. Nome do passeio\n3. Cidade\n4. Data\n5. Horario de ida\n6. Horario de chegada\n7. Valor\n8. Numero de lugares disponiveis\n9. Voltar\nOpcao: ");
					scanf ("%d",&opcao);
					getchar ();
					switch (opcao) {
						case 1:
							printf ("Digite o novo nome da agencia: ");
							fgets(item->Prox->Passeio.ag_turismo, 22, stdin);
							printf ("Nome alterado com sucesso!\n");
							getchar ();
							break;
						case 2:
							printf ("Digite o nome do passeio: ");
							fgets(item->Prox->Passeio.nome_p, 102, stdin);
							printf ("Nome alterado com sucesso!\n");
							getchar ();
							break;
						case 3:
							printf ("Digite a nova cidade: ");
							fgets(item->Prox->Passeio.cidade, 22, stdin);
							printf ("Cidade alterada com sucesso!\n");
							getchar ();
							break;
						case 4:
							printf("Digite a nova data (dia mes ano): ");
							scanf ("%d %d %d",&item->Prox->Passeio.dt_ida_dia_p,&item->Prox->Passeio.dt_ida_mes_p,&item->Prox->Passeio.dt_ida_ano_p);
							getchar ();
							printf ("Data alterada com sucesso!\n");
							getchar ();
							break;
						case 5:
							printf("Digite o novo horario de ida: ");
							fgets(item->Prox->Passeio.hr_ida, 6, stdin);
							printf ("Horario alterado com sucesso!\n");
							getchar ();
							break;
						case 6:
							printf("Digite o novo horario de volta: ");
							fgets(item->Prox->Passeio.hr_chegada, 6, stdin);
							printf ("Horario alterado com sucesso!\n");
							getchar ();
							break;
						case 7:
							printf("Digite o novo valor: ");
							scanf ("%d",&item->Prox->Passeio.valor_p);
							printf ("Valor alterado com sucesso!\n");
							getchar ();
							break;
						case 8:
							printf("Digite o novo numero de lugares disponiveis: ");
							scanf ("%d",&item->Prox->Passeio.qtdd_lugar_disp_p);
							getchar ();
							printf ("Numero de lugares alterado com sucesso!\n");
							getchar ();
							break;
						case 9:
							return;
							break;
						default:
							printf ("Opcao invalida!\n");
							getchar ();
							break;
					}
				}while (opcao != 9);
			}
			else {
				printf ("Passeio nao encontrado!");
				getchar ();
				return;
			}
	}
	
	
void exclui_passeio(TipoPilhaPasseio *passeio) {
	char coisa[102];
	TipoCelulaPasseio *item;
	TipoApontadorPilha q;
	system("clear");
	printf("Digite o ID do passeio que deseja alterar os dados: ");
		fgets(coisa, 102, stdin);
		item = Busca_passeio (coisa,passeio);
		if (item != NULL) {
			q=item->Prox;
			item->Prox = item->Prox->Prox;
			free (q);
			printf ("Passeio excluido com sucesso!");
			getchar ();
			return;
		}
		else {
			printf ("Passeio nao encontrado!\n");
			getchar ();
			return;
		}
	}
