#include <stdio.h>
#include <time.h>

void pega_data_sistema (int *dia,int *mes,int *ano)
{
	struct tm *local;
	time_t t;
	t = time(NULL);
	local=localtime(&t);

	*dia = local->tm_mday;
	*mes = local->tm_mon + 1;
	*ano = local->tm_year + 1900;
}
