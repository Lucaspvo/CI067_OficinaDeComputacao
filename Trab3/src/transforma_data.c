#include <stdio.h>

int bissexto (int ano)
{
	if (((ano % 4) == 0) && ((ano % 100 != 0) || (ano % 400 == 0)))
		return 1;
	return 0;
}

int transforma_data (int dia, int mes, int ano)
{
	int resp = dia, bix;
	bix = bissexto (ano);
	if (mes > 1)
		resp = resp + 31;
	if (mes > 2)
		resp = resp + 28 + bix;
	if (mes > 3)
		resp = resp + 31;
	if (mes > 4)
		resp = resp + 30;
	if (mes > 5)
		resp = resp + 31;
	if (mes > 6)
		resp = resp + 30;
	if (mes > 7)
		resp = resp + 31;
	if (mes > 8)
		resp = resp + 31;
	if (mes > 9)
		resp = resp + 30;
	if (mes > 10)
		resp = resp + 31;
	if (mes > 11)
		resp = resp + 30;
	return resp;
}
