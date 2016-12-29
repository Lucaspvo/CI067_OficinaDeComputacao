#include <stdio.h>
#include <string.h>
#define tam 200

	int main()
	{
		int i, espaco;
		char nome[tam];
		printf("Digite seu nome completo: ");
		gets(nome);
		i=0;
		while (nome[i]!='\0')
		{
			if (nome[i]==' ')
			{
				espaco=i;
			}
			i=i+1;
		}
		i=espaco;
		while (nome[i]!='\0')
		{
			printf("%c", toupper(nome[i+1]));
			i=i+1;
		}
			if (nome[i]=='\0')
			{
				printf(", ");
			}
		i=0;
		while (i<espaco)
		{
			printf("%c", nome[i]);
			i=i+1;
		}
		printf("\n");
	}
