#include <stdio.h>
#include <string.h>
#define max 256

	int main()
	{
		char texto[max];
		int i, cont;
		gets(texto);
		i=0;
		cont=0;
		while (texto[i]!='\0')
		{
			if(tolower(texto[i]) =='a' || tolower(texto[i])=='e' || tolower(texto[i])=='i' || tolower(texto[i])=='o' || tolower(texto[i])=='u')
			{
				cont=cont+1;
			}
			i=i+1;
		}
		printf("Existem %d vogal(ais) na sentença!\n", cont);
	}
		
