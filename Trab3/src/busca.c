#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "structs.h"
#include "prototipos.h"

TipoCelulaCliente * Busca_cpf(char cpf[], TipoListaCliente *cliente)
{ 
	int tem=1;
	TipoApontadorCliente q,q_ant;
	q=cliente->Frente;
	q_ant=cliente->Frente;
	if (q==NULL)
		return NULL;
	while (q_ant!=NULL && tem!=0)
	{
		q_ant = q;
		q=q->Prox;
		if (q==NULL)
			return NULL;
		tem=strcmp(q->Cliente.cpf,cpf);
	}
	return q_ant;
}

TipoCelulaHotel * Busca_nome(char nome[], TipoListaHotel *hotel)
{ 
	int tem=1;
	TipoApontadorHotel q,q_ant;
	q=hotel->Frente;
	q_ant=hotel->Frente;
	if (q==NULL)
		return NULL;
	while (q_ant!=NULL && tem!=0)
	{
		q_ant = q;
		q=q->Prox;
		if (q==NULL)
			return NULL;
		tem=strcmp(q->Hotel.nome_h,nome);
	}
	return q_ant;
}

TipoCelulaVoo * Busca_companhia(char cia[], TipoListaVoo *voo)
{ 
	int tem=1;
	TipoApontadorVoo q,q_ant;
	q=voo->Frente;
	q_ant=voo->Frente;
	if (q==NULL)
		return NULL;
	while (q_ant!=NULL && tem!=0)
	{
		q_ant = q;
		q=q->Prox;
		if (q==NULL)
			return NULL;
		tem=strcmp(q->Voo.cia_aerea,cia);
	}
	return q_ant;
}

TipoCelulaHotel * Busca_hotel(char nome[], TipoListaHotel *hotel)
{ 
	int tem=1,tam;
	TipoApontadorHotel q,q_ant;
	q=hotel->Frente;
	q_ant=hotel->Frente;
	if (q==NULL)
		return NULL;
	while (q_ant!=NULL && tem!=0)
	{
		q_ant = q;
		q=q->Prox;
		if (q==NULL)
			return NULL;
		tam=strlen (nome);
		tem=strncmp(q->Hotel.nome_h,nome,tam);
	}
	return q_ant;
}

TipoCelulaPasseio * Busca_passeio(char id[], TipoPilhaPasseio *passeio)
{ 
	int tem=1;
	TipoApontadorPilha q,q_ant;
	q=passeio->Frente;
	q_ant=passeio->Frente;
	if (q==NULL)
		return NULL;
	while (q_ant!=NULL && tem!=0)
	{
		q_ant = q;
		q=q->Prox;
		if (q==NULL)
			return NULL;
		tem=strcmp(q->Passeio.nome_p,id);
	}
	return q_ant;
}
