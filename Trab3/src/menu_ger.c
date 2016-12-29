#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "structs.h"
#include "prototipos.h"



void menu_geral (int status, char *cpf, TipoListaCliente *cliente,TipoListaHotel *hotel,TipoListaVoo *voo,TipoPilhaPasseio *passeio,TipoListaPacote *pacote) {
	int num;
	system ("clear");
	printf("1. Cria Pacote\n2. Gerencia Cliente\n3. Voltar\n\nDIGITE SUA OPÇÃO: ");
	scanf("%d", &num);
	getchar();
	while (num!=3)
	{
		if (num==1)
			cria_pacote_turistico(voo, pacote, hotel, passeio);
		if (num==2)
			menu_cliente(status, cpf, cliente,hotel,voo,passeio);
		system ("clear");
		printf("1. Cria Pacote\n2. Gerencia Cliente\n3. Voltar\n\nDIGITE SUA OPÇÃO: ");
		scanf("%d", &num);
		getchar();
	}
}

void menu_cliente (int status, char cpf[], TipoListaCliente *cliente,TipoListaHotel *hotel,TipoListaVoo *voo,TipoPilhaPasseio *passeio)
{
	int numero;
	system ("clear");
	printf("1.Incluir Cliente\n2.Alterar dados Cliente\n3.Exclui Cliente\n4.Voltar\n\nDIGITE SUA OPÇÃO: ");
	scanf("%d", &numero);
	getchar();
	do {
		switch(numero) {
			case 1:
				inclui_cliente(status,cpf,cliente);
				break;
			case 2:
				altera_dado_cliente(cpf,cliente);
				break;
			case 3:
				exclui_cliente(cpf,cliente);
				break;
			case 4:
				return;
				break;
			default:
				printf ("Opcao invalida!\n");
				getchar ();
				break;
		}
		system ("clear");
		printf("1.Incluir Cliente\n2.Alterar dados Cliente\n3.Exclui Cliente\n4.Voltar\n\nDIGITE SUA OPÇÃO: ");
		scanf("%d", &numero);
		getchar();
	}while (numero != 4);
}
