#include <stdio.h>
#include <string.h>

	struct info
	{
		char nome[40];
		char endereco[120];
		char fone[11];
		char email[20];
		char cidade[10];
		char cep[8];
		char estado[2];
	}agenda;

	void acha_pessoa(char pessoa[], struct info agenda[])
	{
		int i, achei;
		for (i=0;i<20;i++)
		{
			achei = strcmp (agenda[i].nome,pessoa);
			if (achei==0)
			{
				puts(agenda[i].endereco);
				printf("\n");
				puts(agenda[i].email);
				printf("\n");
				return;
			}
			if (achei)
			{
				printf("O nome não se encontra no registro!!\n");
				return;
			}
		}
	}

	int main()
	{
		struct info agenda[20];
		int cont, i;
		char pessoa[40];
		int l, a, cond, nao_tem;
		cont=0;
		i=0;
		while (cont==0 && i<=20)
		{
			printf("\n");
			printf("Registro %d: \n", i+1);
			printf("Digite o nome: ");
			gets(agenda[i].nome);
			if (agenda[i].nome[0] != '\0')
			{
				printf("Digite o endereço: ");
				gets(agenda[i].endereco);
				printf("Digite o telefone: ");
				gets(agenda[i].fone);
				printf("Digite o email: ");
				gets(agenda[i].email);
				printf("Digite a cidade: ");
				gets(agenda[i].cidade);
				printf("Digite o CEP: ");
				gets(agenda[i].cep);
				printf("Digite o estado: ");
				gets(agenda[i].estado);
				cont=0;
			}
			else 
			{
				cont=1;
			}
			printf("\n");
			i=i+1;
		}
		printf("Digite o nome da pessoa desejada: ");
		gets(pessoa);
		printf("\n");
		acha_pessoa(pessoa,agenda);
	}
