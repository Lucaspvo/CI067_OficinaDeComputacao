#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"
#include "prototipos.h"


int main () {
	TipoFila *Fila_pop = NULL;
	TipoFila *Fila_vip = NULL;
	TipoFila *Fila_normal = NULL;
	TipoListaCliente *Cliente = NULL;
	TipoListaHotel *Hotel = NULL;
	TipoListaVoo *Voo = NULL;
	TipoPilhaPasseio *Passeio = NULL;
	TipoListaPacote *Pacote = NULL;
	Fila_pop = (TipoFila *) malloc (sizeof(TipoFila));
	Fila_vip = (TipoFila *) malloc (sizeof(TipoFila));
	Fila_normal = (TipoFila *) malloc (sizeof(TipoFila));
	Cliente = (TipoListaCliente *) malloc (sizeof(TipoCelulaCliente));
	Hotel = (TipoListaHotel *) malloc (sizeof(TipoCelulaHotel));
	Voo = (TipoListaVoo *) malloc (sizeof(TipoCelulaVoo));
	Passeio = (TipoPilhaPasseio *) malloc (sizeof(TipoCelulaPasseio));
	Pacote = (TipoListaPacote *) malloc (sizeof(TipoCelulaPacote));
	int opcao=0,tipo=0,i=0,j=0,validou, num;
	char cpf[13];
	TipoApontadorCliente q;
	
	FFVazia (Fila_pop); 
	FFVazia (Fila_vip);
	FFVazia (Fila_normal);

	FLVazia_H (Hotel);
	FLVazia_C (Cliente);
	FLVazia_V (Voo);
	FPVazia_P (Passeio);
	FLVazia_P (Pacote);
	
	Carrega_Fila (Fila_pop,Fila_vip,Fila_normal);
	Carrega_Cliente (Cliente);
	Carrega_Hotel (Hotel);
	Carrega_Voo (Voo);
	Carrega_Passeio (Passeio);
	Carrega_Pacote (Pacote);
	
	do {
		system ("clear");
		printf ("1. Registrar chegada do cliente\n2. Atender cliente\n3. Gerenciamento de hotéis\n4. Gerenciamento de passagens\n5. Gerenciamento de passeios\n6. Terminar Programa\n\nOpção: ");
		scanf ("%d",&opcao);
		getchar ();
		switch (opcao) {
			case 1:
				printf ("Digite o CPF: ");
				fgets (cpf,13,stdin);
				validou = valida_cpf (cpf);
				if (validou)
					do {
						validou = valida_cpf (cpf);
						printf ("invalido\n");
						printf ("Digite o CPF: ");
						fgets (cpf,13,stdin);
					}while(!validou);
					q=Busca_cpf(cpf,Cliente);
					if (q!=NULL) {
						q=q->Prox;
						if (q->Cliente.status_c == 0)
							Enfileira (cpf,Fila_normal);
						else if (q->Cliente.status_c == 1)
							Enfileira (cpf,Fila_vip);
						else if (q->Cliente.status_c == 2)
							Enfileira (cpf,Fila_pop);
						printf ("Cliente adicionado na fila de acordo com o cadastro\n");
						getchar ();
						break;
					}
				printf ("Digite o tipo do cliente:\n\n0. Normal\n1. VIP\n2. Especial\nTipo: ");
				scanf ("%d",&tipo);
				getchar ();
				while ((tipo>=3)&&(tipo<0)) {
					printf ("Tipo invalido!\n");
					printf ("Digite o tipo do cliente:\n\n0. Normal\n1. VIP\n2. Especial\nTipo: ");
					scanf ("%d",&tipo);
					getchar ();
				}
				if (tipo == 0)
					Enfileira (cpf,Fila_normal); //adiciona cliente na fila
				else if (tipo == 1)
					Enfileira (cpf,Fila_vip);
				else
					Enfileira (cpf,Fila_pop);
				break;
			case 2:	
				if ((Vazia (Fila_pop)==1)&&(Vazia (Fila_vip)==1)&&(Vazia (Fila_normal)==1)) {
					printf ("Nao tem ninguem na fila!\n");
					getchar ();
					break;
				}
				if ((Vazia (Fila_pop)==0)&&(i < 3)) {
					Desenfileira (2,Fila_pop,Cliente,Hotel,Voo,Passeio,Pacote); //atende cliente
					i++;
					break;
				}
				else if ((Vazia (Fila_vip)==0)&&(j < 2)) {
					Desenfileira (1,Fila_vip,Cliente,Hotel,Voo,Passeio,Pacote); //atende cliente
					j++;
					break;
				}
				else if (Vazia (Fila_normal)==0) {
					Desenfileira (0,Fila_normal,Cliente,Hotel,Voo,Passeio,Pacote); //atende cliente
					i=j=0;
					break;
				}
				i=j=0;
				break;
			case 3:
				system("clear");
				printf("QUAL OPERAÇÃO DESEJA REALIZAR?\n\n");
				printf("1.Inclui Hotel\n2.Altera Dado Hotel\n3.Exclui Hotel\n4.Voltar\n\nDIGITE SUA OPÇÃO: ");
				scanf("%d", &num);
				getchar();
				while (num!=4)
				{
					if (num==1)
						inclui_hotel(Hotel);
					if (num==2)
						altera_dado_hotel(Hotel);
					if (num==3)
						exclui_hotel(Hotel);
					system("clear");
					printf("QUAL OPERAÇÃO DESEJA REALIZAR?\n\n");
					printf("1.Inclui Hotel\n2.Altera Dado Hotel\n3.Exclui Hotel\n4.Voltar\n\nDIGITE SUA OPÇÃO: ");
					scanf("%d", &num);
					getchar();
				}
				break;
			case 4:
				system("clear");
				printf("QUAL OPERAÇÃO DESEJA REALIZAR?\n\n");
				printf("1.Inclui Voo\n2.Altera Dado Voo\n3.Exclui Voo\n4.Voltar\n\nDIGITE SUA OPÇÃO: ");
				scanf("%d", &num);
				getchar();
				while (num!=4)
				{
					if (num==1)
						inclui_voo(Voo);
					if (num==2)
						altera_dado_voo(Voo);
					if (num==3)
						exclui_voo(Voo);
					system("clear");
					printf("QUAL OPERAÇÃO DESEJA REALIZAR?\n\n");
					printf("1.Inclui Voo\n2.Altera Dado Voo\n3.Exclui Voo\n4.Voltar\n\nDIGITE SUA OPÇÃO: ");
					scanf("%d", &num);
					getchar();
				}
				break;
			case 5:
				system("clear");
				printf("QUAL OPERAÇÃO DESEJA REALIZAR?\n\n");
				printf("1.Inclui Passeio\n2.Altera Dado Passeio\n3.Exclui Passeio\n4.Voltar\n\nDIGITE SUA OPÇÃO: ");
				scanf("%d", &num);
				getchar();
				while (num!=4)
				{
					if (num==1)
						inclui_passeio(Passeio);
					if (num==2)
						altera_dado_passeio(Passeio);
					if (num==3)
						exclui_passeio(Passeio);
					system("clear");
					printf("QUAL OPERAÇÃO DESEJA REALIZAR?\n\n");
					printf("1.Inclui Passeio\n2.Altera Dado Passeio\n3.Exclui Passeio\n4.Voltar\n\nDIGITE SUA OPÇÃO: ");
					scanf("%d", &num);
					getchar();
				}
				break;
			case 6:
				save (Fila_pop,Fila_vip,Fila_normal); //salva se ainda tiver gente na fila
				save_tudo (Cliente,Hotel,Pacote,Voo,Passeio);
				break;
			default:
				printf ("Opcao invalida.\n");
				getchar ();
				break;
		}
	}while (opcao != 6);
		system("clear");
		return 0;
}
