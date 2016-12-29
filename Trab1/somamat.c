#include <stdio.h>
#define lin 10
#define col 10

	void ler_matriz(int mat[][col], int x, int y)
	{
		int i, j;
		for (i=0; i<x; i++)
		{
			for (j=0; j<y; j++)
			{
				scanf("%d", &mat[i][j]);
			}
		}
	}
		
	void soma_matrizes(int matx[][col], int maty[][col], int matz[][col], int x, int y)
	{
		int i, j;
		for (i=0; i<x; i++)
		{
			for (j=0; j<y; j++)
			{
				matz[i][j]=matx[i][j]+maty[i][j];
			}
		}
	}

	void print_matriz_r(int matz[][col], int x, int y)
	{
		int i, j;
		for (i=0; i<x; i++)
		{
			for (j=0; j<y; j++)
			{
				printf("%d ", matz[i][j]);
				if (j==y-1)
				{
					printf("\n");
				}
			}
		}
	} 

	int main()
	{
		int matx[lin][col];
		int maty[lin][col];
		int matz[lin][col];
		int linha, coluna;
		printf("Digite um valor para linha: ");
		scanf("%d", &linha);
		if (linha>=lin)
		{
			while(linha>=lin)
			{
			printf("Digite um valor valido(ate 10): ");
			scanf("%d", &linha);
			}
		}
		printf("Digite um valor para coluna: ");
		scanf("%d", &coluna);
		if (coluna>=col)
		{
			while (coluna>=col)
			{
			printf("Digite um valor valido(ate 10): ");
			scanf("%d", &coluna);
			}
		}
		ler_matriz(matx,linha,coluna);
		printf("\n");
		ler_matriz(maty,linha,coluna);
		printf("\n");
		soma_matrizes(matx,maty,matz, linha, coluna);
		print_matriz_r(matz, linha, coluna);
	}
