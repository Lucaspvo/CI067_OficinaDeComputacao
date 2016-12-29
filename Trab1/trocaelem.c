#include <stdio.h>
#define lin 10
#define col 10

	void ler_matriz(int mat[][col])
	{
		int i, j;
		for (i=0; i<lin; i++)
		{
			for (j=0; j<col; j++)
			{
				scanf("%d", &mat[i][j]);
			}
		}
	}

	void troca_elemento(int mat[][col])
	{
		int i, j, num_a, x, y, aux;
		i=0;
		while (i<lin)
		{
			j=0;
			num_a=0;
			x=0;
			y=0;
			while (j<col)
			{
				if (mat[i][j]>num_a)
				{
					num_a=mat[i][j];
					x=i;
					y=j;
				}
				if (j==col-1)
				{
					aux=mat[i][i];
					mat[i][i]=num_a;
					mat[x][y]=aux;
				}
				j=j+1;
			}
			i=i+1;
		}
	}

	void print_matriz_trocada(int mat[][col])
	{
		int i, j;
		for (i=0; i<lin; i++)
		{
			for (j=0; j<col; j++)
			{
				printf("%d ", mat[i][j]);
				if (j==col-1)
				{
					printf("\n");
				}
			}
		}
	}

	int main()
	{
		int m[lin][col];
		printf("Digite sua matriz quadrada de dimensão %dx%d: \n", lin, col);
		ler_matriz(m);
		printf("\n");
		troca_elemento(m);
		printf("A matriz trocada será: \n");
		print_matriz_trocada(m);
	}
