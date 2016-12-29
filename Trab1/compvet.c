#include <stdio.h> 

	int obtem_vetor(int vet[], int tam, int num1)
	{
		int i, num, cont;
		printf("Digite seu vetor: ");
		i=0; cont=0;
		while (i<tam)
		{
			scanf("%d", &num);
			if (num!=num1)
			{
				vet[i]=num;
				cont=cont+1;
			}
			else
			{
				i=tam;
			}
			i=i+1;
		}
		return cont;
	}

	int compara_vetores(int v[], int w[], int tam)
	{
		int i, cont, j;
		i=0;
		cont=0;
		while (i<tam)
		{
			if (v[i]==w[i])
			{
				cont=cont+1;
			}
			i=i+1;
		}
		return cont;
	}

	int main()
	{
		int num, num1, tam, elem, elem1;
		tam=15;
		int v[tam];
		int w[tam];
		printf("Digite o valor para a parada de entrada de dados: ");
		scanf("%d", &num1);
		elem=obtem_vetor(v, tam, num1);
		printf("Foram lidos %d elementos\n", elem);
		elem1=obtem_vetor(w, tam, num1);
		printf("Foram lidos %d elementos\n", elem1);
		num=compara_vetores(v,w,tam);
		printf("Existe(m) %d elemento(s) igual(ais) em ambos os vetores!\n", num);
	}
