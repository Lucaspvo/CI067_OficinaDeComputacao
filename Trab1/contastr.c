#include <stdio.h>
#include <string.h>
#define max 200

	int main()
	{
		int i, tem;
		char sentenca[max];
		printf("Digite uma sentença: \n");
		gets(sentenca);
		tem=0;
		i=0;
		while (sentenca[i]!='\0')
		{
			if (tolower(sentenca[i])=='f' && tolower(sentenca[i+1])=='a' && tolower(sentenca[i+2])=='t' && tolower(sentenca[i+3])=='o')
			{
				tem=tem+1;
				i=i+4;
			}
			else
			{
				i=i+1;
			}
		}
		printf("Existem %d string(s) fato.\n", tem);
	}
			
