#include <stdio.h>
#define max 5
	void ler_vetor(int vet[])
	{
		int i;
		printf("Digite seu vetor: ");
		for (i=0; i<max; i++)
		{
			scanf("%d", &vet[i]);
		}
	}

	int verifica(int vetx[], int vety[])
	{
		int cont, a, i, j;
		cont=0;
		a=0;
		j=0;
		while (a<max)
		{
			i=0;
			while (i<max)
			{
				if (vetx[i]==vety[j])
				{
					j=j+1;
					i=max;
					cont=cont+1;
				}
				if (vetx[i]!=vety[j])
				{
					i=i+1;
				}
			}
			a=a+1;
		}
		if (cont==max)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	int checa(int vetx[], int vety[])
	{
		int i, cont;
		i=0;
		cont=0;
		while (i<max)
		{
			if (vetx[i]==vety[i])
			{
				cont=cont+1;
			}
			i=i+1;
		}
		if (cont==max)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}


	int main()
	{
		int vetv[max];
		int vetw[max];
		ler_vetor(vetv);
		ler_vetor(vetw);
		if (verifica(vetv, vetw)==1)
		{
			if (checa(vetv, vetw)==0)
			{
				printf("É permutação!!\n");
			}
			else
			{
				printf("Não é permutação!\n");
			}
		}
		else
		{
		printf("Não é permutação!!\n");
		}
	}
