#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


void pega_data_sistema (int *,int *,int *);

void valida_nome(char *nome)
	{
		int j=0, conf=0;
		if (nome[j]=='\n')
			conf=1;
		while (conf!=0)
		{
			system("clear");
			printf("O nome anterior foi digitado incorretamente!\n");
			printf("Digite o nome novamente: ");
			fgets(nome, 100, stdin);
			j=0;
			conf=0;
			if (nome[j]=='\n')
				conf=1;
		}
	}

	void valida_endereco(char *endereco) 
	{
		int j=0, conf=1;
		if (endereco[j]=='\n')
			conf=0;
			while (conf==0)
			{
				system("clear");
				printf("O endereço do cliente foi digitado incorretamente!\n\n");
				printf("Digite o endereço do cliente novamente: ");
				fgets(endereco, 100, stdin);
				j=0;
				conf=1;
				if (endereco[j]=='\n')
					conf=0;
			}
	}

	void valida_telefone(char *telefone)
	{
		int j=0, conf=0;
		if ((telefone[j]=='\n') || (telefone[11]!='\n') || (telefone[0]!='0'))
			conf=1;
		while ((conf==0) && (telefone[j]!='\n'))
		{
			conf=isalpha(telefone[j]);
			j++;
		}
		while (conf)
		{
			system("clear");
			printf("O telefone anterior foi digitado incorretamente!(0xxyyyyyyyy)\n");
			printf("Digite o telefone novamente: ");
			fgets(telefone, 14, stdin);
			j=0;
			conf=0;
			if ((telefone[j]=='\n') || (telefone[11]!='\n') || (telefone[0]!='0'))
				conf=1;
			while ((conf==0) && (telefone[j]!='\n'))
			{
				conf=isalpha(telefone[j]);
				j++;
			}
		}
	}

	void valida_email(char *email)
	{
		int j=0, conf=1;
		if (email[j]=='\n')
			conf=0;
		if (conf==0)
		{
			while (conf==0)
			{
				system("clear");
				printf("O e-mail do cliente foi digitado incorretamente!\n\n");
				printf("Digite o e-mail do cliente novamente: ");
				fgets(email, 30, stdin);
				j=0;
				conf=1;
				if (email[j]=='\n')
					conf=0;
			}
		}
	}

	int valida_cpf(char cpf[])
	{
		int j=0, conf=0;
		if (cpf[11]!='\n')
			conf=1;
		while ((conf==0) && (j<11))
			{
				conf=isalpha(cpf[j]);
				j++;
			}
		return conf;
	}
	
	int valida_data(int x, int y, int z)
	{
		int dia = 0, mes=0,ano=0;
		pega_data_sistema (&dia,&mes,&ano);
		if (z<ano)
			return 1;
		else {
			if (z>ano)
				return 0;
			if (y<mes)
				return 1;
			else
				if (x<dia)
					return 1;
		}
		return 0;
	}
	
	int valida_cidade(char cidade[])
	{
		int j=0, conf=1;
		while ((conf!=0) && (cidade[j]!='\n'))
			{
				conf=isalpha(cidade[j]);
				j++;
			}
		return conf;
	}
	
	int valida_hotel(char hotel[])
	{
		int j=0, conf=1;
		if (hotel[j]=='\n')
			conf=0;
		return conf;
	}
	
	int valida_quantidade(int x)
	{
		if (x<0)
		 return 1;
		return 0;
	}
