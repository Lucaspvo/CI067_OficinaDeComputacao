#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"
#include "prototipos.h"


void FFVazia (TipoFila *Fila) { 
	Fila->Frente = (TipoApontador) malloc (sizeof(TipoCelula));
	Fila->Frente->Prox = (TipoApontador) malloc (sizeof(TipoCelula));
	Fila->Tras = Fila->Frente;
	Fila->Tras->Prox = Fila->Frente->Prox;
}

void FLVazia_H (TipoListaHotel *Lista) { 
	Lista->Frente = (TipoApontadorHotel) malloc (sizeof(TipoCelulaHotel));
	Lista->Tras = Lista->Frente;
	Lista->Tras->Prox = NULL;
}

void FLVazia_C (TipoListaCliente *Lista) { 
	Lista->Frente = (TipoApontadorCliente) malloc (sizeof(TipoCelulaCliente));
	Lista->Tras = Lista->Frente;
	Lista->Tras->Prox = NULL;
}

void FLVazia_V (TipoListaVoo *Lista) { 
	Lista->Frente = (TipoApontadorVoo) malloc (sizeof(TipoCelulaVoo));
	Lista->Tras = Lista->Frente;
	Lista->Tras->Prox = NULL;
}

void FPVazia_P (TipoPilhaPasseio *Lista) { 
	Lista->Frente = (TipoApontadorPilha) malloc (sizeof(TipoCelulaPasseio));
	Lista->Tras = Lista->Frente;
	Lista->Tras->Prox = NULL;
}

void FLVazia_P (TipoListaPacote *Lista) { 
	Lista->Frente = (TipoApontadorPacote) malloc (sizeof(TipoCelulaPacote));
	Lista->Tras = Lista->Frente;
	Lista->Tras->Prox = NULL;
}

void Carrega_Hotel (TipoListaHotel *Hotel) {
	int i=0,numero;
	char tmp[102],letra;
	FILE *fp;
	fp = fopen ("hoteis.txt","a+");
	letra = fgetc(fp);
	while (letra != EOF) { 
		Hotel->Tras->Prox = (TipoApontadorHotel) malloc (sizeof(TipoCelulaHotel));
		Hotel->Tras = Hotel->Tras->Prox;
		Hotel->Tras->Prox = NULL;
		i=0;
		while (letra != '\n') {
			tmp[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		numero=atoi(tmp);
		tmp[0]='\n';
		tmp[1]='\0';
		tmp[2]='\0';
		tmp[3]='\0';
		tmp[4]='\0';
		tmp[5]='\0';
		tmp[6]='\0';
		tmp[7]='\0';
		tmp[8]='\0';
		tmp[9]='\0';
		Hotel->Tras->Hotel.id_h=numero;
		letra = fgetc(fp);
		i=0;
		while (letra != '\n') {
			tmp[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		tmp[i] = '\n';
		tmp[i+1] = '\0';
		strcpy (Hotel->Tras->Hotel.nome_h,tmp);
		letra = fgetc(fp);
		i=0;
		while (letra != '\n') {
			tmp[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		tmp[i] = '\n';
		tmp[i+1] = '\0';
		strcpy (Hotel->Tras->Hotel.end_h,tmp);
		letra = fgetc(fp);
		i=0;
		while (letra != '\n') {
			tmp[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		tmp[i] = '\n';
		tmp[i+1] = '\0';
		strcpy (Hotel->Tras->Hotel.cidade_h,tmp);
		letra = fgetc(fp);
		tmp[0]='\n';
		tmp[1]='\0';
		tmp[2]='\0';
		tmp[3]='\0';
		tmp[4]='\0';
		tmp[5]='\0';
		tmp[6]='\0';
		tmp[7]='\0';
		tmp[8]='\0';
		tmp[9]='\0';
		i=0;
		while (letra != '\n') {
			tmp[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		numero=atoi(tmp);
		tmp[0]='\n';
		tmp[1]='\0';
		tmp[2]='\0';
		tmp[3]='\0';
		tmp[4]='\0';
		tmp[5]='\0';
		tmp[6]='\0';
		tmp[7]='\0';
		tmp[8]='\0';
		tmp[9]='\0';
		tmp[4]='\0';
		Hotel->Tras->Hotel.valor_h=numero;
		i=0;
		letra = fgetc(fp);
				i=0;
		while (letra != '\n') {
			tmp[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		numero=atoi(tmp);
		tmp[0]='\n';
		tmp[1]='\0';
		tmp[2]='\0';
		tmp[3]='\0';
		tmp[4]='\0';
		tmp[5]='\0';
		tmp[6]='\0';
		tmp[7]='\0';
		tmp[8]='\0';
		tmp[9]='\0';
		Hotel->Tras->Hotel.qtdd_qtos_disp=numero;
		letra = fgetc(fp);
		i=0;
	}
}

void Carrega_Cliente (TipoListaCliente *Cliente) {
	int i=0,numero;
	char tmp[102],letra;
	FILE *fp;
	fp = fopen ("cliente.txt","a+");
	letra = fgetc(fp);
	while (letra != EOF) { 
		Cliente->Tras->Prox = (TipoApontadorCliente) malloc (sizeof(TipoCelulaCliente));
		Cliente->Tras = Cliente->Tras->Prox;
		Cliente->Tras->Prox = NULL;
		while (letra != '\n') {
			tmp[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		tmp[i] = '\n';
		tmp[i+1] = '\0';
		strcpy (Cliente->Tras->Cliente.cpf,tmp);
		letra = fgetc(fp);
		i=0;
		while (letra != '\n') {
			tmp[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		tmp[i] = '\n';
		tmp[i+1] = '\0';
		strcpy (Cliente->Tras->Cliente.nome_c,tmp);
		letra = fgetc(fp);
		i=0;
		while (letra != '\n') {
			tmp[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		tmp[i] = '\n';
		tmp[i+1] = '\0';
		strcpy (Cliente->Tras->Cliente.end_c,tmp);
		letra = fgetc(fp);
		i=0;
		while (letra != '\n') {
			tmp[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		tmp[i] = '\n';
		tmp[i+1] = '\0';
		strcpy (Cliente->Tras->Cliente.telefone_c,tmp);
		letra = fgetc(fp);
		i=0;
		while (letra != '\n') {
			tmp[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		tmp[i] = '\n';
		tmp[i+1] = '\0';
		strcpy (Cliente->Tras->Cliente.email_c,tmp);
		letra = fgetc(fp);
		i=0;
		while (letra != '\n') {
			tmp[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		numero=atoi(tmp);
		tmp[0]='\n';
		tmp[1]='\0';
		tmp[2]='\0';
		tmp[3]='\0';
		tmp[4]='\0';
		tmp[5]='\0';
		tmp[6]='\0';
		tmp[7]='\0';
		tmp[8]='\0';
		tmp[9]='\0';
		Cliente->Tras->Cliente.status_c=numero;
		letra = fgetc(fp);
		i=0;
	}
}

void Carrega_Voo (TipoListaVoo *Voo) {
	int i=0,numero;
	char tmp[102],letra;
	FILE *fp;
	fp = fopen ("voos.txt","a+");
	letra = fgetc(fp);
	while (letra != EOF) { 
		Voo->Tras->Prox = (TipoApontadorVoo) malloc (sizeof(TipoCelulaVoo));
		Voo->Tras = Voo->Tras->Prox;
		Voo->Tras->Prox = NULL;
		i=0;
		while (letra != '\n') {
			tmp[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		numero=atoi(tmp);
		tmp[0]='\n';
		tmp[1]='\0';
		tmp[2]='\0';
		tmp[3]='\0';
		tmp[4]='\0';
		tmp[5]='\0';
		tmp[6]='\0';
		tmp[7]='\0';
		tmp[8]='\0';
		tmp[9]='\0';
		Voo->Tras->Voo.id_v=numero;
		letra = fgetc(fp);
		i=0;
		while (letra != '\n') {
			tmp[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		tmp[i] = '\n';
		tmp[i+1] = '\0';
		strcpy (Voo->Tras->Voo.cia_aerea,tmp);
		letra = fgetc(fp);
		i=0;
		while (letra != '\n') {
			tmp[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		tmp[i] = '\n';
		tmp[i+1] = '\0';
		strcpy (Voo->Tras->Voo.destino,tmp);
		letra = fgetc(fp);
		i=0;
		while (letra != '\n') {
			tmp[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		tmp[i] = '\n';
		tmp[i+1] = '\0';
		strcpy (Voo->Tras->Voo.origem,tmp);
		letra = fgetc(fp);
		i=0;
		while (letra != '\n') {
			tmp[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		numero=atoi(tmp);
		tmp[0]='\n';
		tmp[1]='\0';
		tmp[2]='\0';
		tmp[3]='\0';
		tmp[4]='\0';
		tmp[5]='\0';
		tmp[6]='\0';
		tmp[7]='\0';
		tmp[8]='\0';
		tmp[9]='\0';
		Voo->Tras->Voo.dt_ida_dia=numero;
		letra = fgetc(fp);
		i=0;
		while (letra != '\n') {
			tmp[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		numero=atoi(tmp);
		tmp[0]='\n';
		tmp[1]='\0';
		tmp[2]='\0';
		tmp[3]='\0';
		tmp[4]='\0';
		tmp[5]='\0';
		tmp[6]='\0';
		tmp[7]='\0';
		tmp[8]='\0';
		tmp[9]='\0';
		Voo->Tras->Voo.dt_ida_mes=numero;
		letra = fgetc(fp);
		i=0;
		while (letra != '\n') {
			tmp[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		numero=atoi(tmp);
		tmp[0]='\n';
		tmp[1]='\0';
		tmp[2]='\0';
		tmp[3]='\0';
		tmp[4]='\0';
		tmp[5]='\0';
		tmp[6]='\0';
		tmp[7]='\0';
		tmp[8]='\0';
		tmp[9]='\0';
		Voo->Tras->Voo.dt_ida_ano=numero;
		letra = fgetc(fp);
		i=0;
		while (letra != '\n') {
			tmp[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		tmp[i] = '\n';
		tmp[i+1] = '\0';
		strcpy (Voo->Tras->Voo.hr_ida,tmp);
		letra = fgetc(fp);
		i=0;
		while (letra != '\n') {
			tmp[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		numero=atoi(tmp);
		tmp[0]='\n';
		tmp[1]='\0';
		tmp[2]='\0';
		tmp[3]='\0';
		tmp[4]='\0';
		tmp[5]='\0';
		tmp[6]='\0';
		tmp[7]='\0';
		tmp[8]='\0';
		tmp[9]='\0';
		Voo->Tras->Voo.dt_chegada_dia=numero;
		letra = fgetc(fp);
		i=0;
		while (letra != '\n') {
			tmp[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		numero=atoi(tmp);
		tmp[0]='\n';
		tmp[1]='\0';
		tmp[2]='\0';
		tmp[3]='\0';
		tmp[4]='\0';
		tmp[5]='\0';
		tmp[6]='\0';
		tmp[7]='\0';
		tmp[8]='\0';
		tmp[9]='\0';
		Voo->Tras->Voo.dt_chegada_mes=numero;
		letra = fgetc(fp);
		i=0;
		while (letra != '\n') {
			tmp[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		numero=atoi(tmp);
		tmp[0]='\n';
		tmp[1]='\0';
		tmp[2]='\0';
		tmp[3]='\0';
		tmp[4]='\0';
		tmp[5]='\0';
		tmp[6]='\0';
		tmp[7]='\0';
		tmp[8]='\0';
		tmp[9]='\0';
		Voo->Tras->Voo.dt_chegada_ano=numero;
		letra = fgetc(fp);
		i=0;
		while (letra != '\n') {
			tmp[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		tmp[i] = '\n';
		tmp[i+1] = '\0';
		strcpy (Voo->Tras->Voo.hr_chegada,tmp);
		letra = fgetc(fp);
		i=0;
				tmp[0]='\n';
		tmp[1]='\0';
		tmp[2]='\0';
		tmp[3]='\0';
		tmp[4]='\0';
		tmp[5]='\0';
		tmp[6]='\0';
		tmp[7]='\0';
		tmp[8]='\0';
		tmp[9]='\0';
		while (letra != '\n') {
			tmp[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		numero=atoi(tmp);
		tmp[0]='\n';
		tmp[1]='\0';
		tmp[2]='\0';
		tmp[3]='\0';
		tmp[4]='\0';
		tmp[5]='\0';
		tmp[6]='\0';
		tmp[7]='\0';
		tmp[8]='\0';
		tmp[9]='\0';
		Voo->Tras->Voo.valor_v=numero;
		letra = fgetc(fp);
		i=0;
		while (letra != '\n') {
			tmp[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		numero=atoi(tmp);
		tmp[0]='\n';
		tmp[1]='\0';
		tmp[2]='\0';
		tmp[3]='\0';
		tmp[4]='\0';
		tmp[5]='\0';
		tmp[6]='\0';
		tmp[7]='\0';
		tmp[8]='\0';
		tmp[9]='\0';
		Voo->Tras->Voo.qtdd_lugar_disp_v=numero;
		letra = fgetc(fp);
		i=0;
	}
}

void Carrega_Passeio (TipoPilhaPasseio *Passeio) {
	int i=0,numero;
	char tmp[102],letra;
	FILE *fp;
	fp = fopen ("passeios.txt","a+");
	letra = fgetc(fp);
	while (letra != EOF) { 
		Passeio->Tras->Prox = (TipoApontadorPilha) malloc (sizeof(TipoCelulaPasseio));
		Passeio->Tras = Passeio->Tras->Prox;
		Passeio->Tras->Prox = NULL;
		i=0;
		while (letra != '\n') {
			tmp[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		numero=atoi(tmp);
		tmp[0]='\n';
		tmp[1]='\0';
		tmp[2]='\0';
		tmp[3]='\0';
		tmp[4]='\0';
		tmp[5]='\0';
		tmp[6]='\0';
		tmp[7]='\0';
		tmp[8]='\0';
		tmp[9]='\0';
		Passeio->Tras->Passeio.id_p=numero;
		letra = fgetc(fp);
		i=0;
		while (letra != '\n') {
			tmp[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		tmp[i] = '\n';
		tmp[i+1] = '\0';
		strcpy (Passeio->Tras->Passeio.ag_turismo,tmp);
		letra = fgetc(fp);
		i=0;
		while (letra != '\n') {
			tmp[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		tmp[i] = '\n';
		tmp[i+1] = '\0';
		strcpy (Passeio->Tras->Passeio.nome_p,tmp);
		letra = fgetc(fp);
				i=0;
		while (letra != '\n') {
			tmp[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		tmp[i] = '\n';
		tmp[i+1] = '\0';
		strcpy (Passeio->Tras->Passeio.cidade,tmp);
		i=0;
		letra = fgetc(fp);
		while (letra != '\n') {
			tmp[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		numero=atoi(tmp);
		tmp[0]='\n';
		tmp[1]='\0';
		tmp[2]='\0';
		tmp[3]='\0';
		tmp[4]='\0';
		tmp[5]='\0';
		tmp[6]='\0';
		tmp[7]='\0';
		tmp[8]='\0';
		tmp[9]='\0';
		Passeio->Tras->Passeio.dt_ida_dia_p=numero;
		letra = fgetc(fp);
		i=0;
		while (letra != '\n') {
			tmp[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		numero=atoi(tmp);
		tmp[0]='\n';
		tmp[1]='\0';
		tmp[2]='\0';
		tmp[3]='\0';
		tmp[4]='\0';
		tmp[5]='\0';
		tmp[6]='\0';
		tmp[7]='\0';
		tmp[8]='\0';
		tmp[9]='\0';
		Passeio->Tras->Passeio.dt_ida_mes_p=numero;
		letra = fgetc(fp);
		i=0;
		while (letra != '\n') {
			tmp[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		numero=atoi(tmp);
		tmp[0]='\n';
		tmp[1]='\0';
		tmp[2]='\0';
		tmp[3]='\0';
		tmp[4]='\0';
		tmp[5]='\0';
		tmp[6]='\0';
		tmp[7]='\0';
		tmp[8]='\0';
		tmp[9]='\0';
		Passeio->Tras->Passeio.dt_ida_ano_p=numero;
		letra = fgetc(fp);
		i=0;
		while (letra != '\n') {
			tmp[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		tmp[i] = '\n';
		tmp[i+1] = '\0';
		strcpy (Passeio->Tras->Passeio.hr_ida,tmp);
		letra = fgetc(fp);
		i=0;
		while (letra != '\n') {
			tmp[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		tmp[i] = '\n';
		tmp[i+1] = '\0';
		strcpy (Passeio->Tras->Passeio.hr_chegada,tmp);
		letra = fgetc(fp);
		tmp[0]='\n';
		tmp[1]='\0';
		tmp[2]='\0';
		tmp[3]='\0';
		tmp[4]='\0';
		tmp[5]='\0';
		tmp[6]='\0';
		tmp[7]='\0';
		tmp[8]='\0';
		tmp[9]='\0';
		i=0;
		while (letra != '\n') {
			tmp[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		numero=atoi(tmp);
		tmp[0]='\n';
		tmp[1]='\0';
		tmp[2]='\0';
		tmp[3]='\0';
		tmp[4]='\0';
		tmp[5]='\0';
		tmp[6]='\0';
		tmp[7]='\0';
		tmp[8]='\0';
		tmp[9]='\0';
		Passeio->Tras->Passeio.valor_p=numero;
		letra = fgetc(fp);
		i=0;
		while (letra != '\n') {
			tmp[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		numero=atoi(tmp);
		tmp[0]='\n';
		tmp[1]='\0';
		tmp[2]='\0';
		tmp[3]='\0';
		tmp[4]='\0';
		tmp[5]='\0';
		tmp[6]='\0';
		tmp[7]='\0';
		tmp[8]='\0';
		tmp[9]='\0';
		Passeio->Tras->Passeio.qtdd_lugar_disp_p=numero;
		letra = fgetc(fp);
		i=0;
	}
}

void Carrega_Pacote (TipoListaPacote *Pacote) {
	int i,numero;
	char letra,tmp[100];
	FILE *fp;
	fp = fopen ("pacote.txt","a+");
	letra = fgetc(fp);
	while (letra != EOF) { 
		Pacote->Tras->Prox = (TipoApontadorPacote) malloc (sizeof(TipoCelulaPacote));
		Pacote->Tras = Pacote->Tras->Prox;
		Pacote->Tras->Prox = NULL;
		i=0;
		while (letra != '\n') {
			tmp[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		numero=atoi(tmp);
		tmp[0]='\n';
		tmp[1]='\0';
		tmp[2]='\0';
		tmp[3]='\0';
		tmp[4]='\0';
		tmp[5]='\0';
		tmp[6]='\0';
		tmp[7]='\0';
		tmp[8]='\0';
		tmp[9]='\0';
		Pacote->Tras->Pacote.id_v=numero;
		letra = fgetc(fp);
		i=0;
		while (letra != '\n') {
			tmp[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		numero=atoi(tmp);
		tmp[0]='\n';
		tmp[1]='\0';
		tmp[2]='\0';
		tmp[3]='\0';
		tmp[4]='\0';
		tmp[5]='\0';
		tmp[6]='\0';
		tmp[7]='\0';
		tmp[8]='\0';
		tmp[9]='\0';
		Pacote->Tras->Pacote.id_h=numero;
		letra = fgetc(fp);
		i=0;
		while (letra != '\n') {
			tmp[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		numero=atoi(tmp);
		tmp[0]='\n';
		tmp[1]='\0';
		tmp[2]='\0';
		tmp[3]='\0';
		tmp[4]='\0';
		tmp[5]='\0';
		tmp[6]='\0';
		tmp[7]='\0';
		tmp[8]='\0';
		tmp[9]='\0';
		Pacote->Tras->Pacote.id_p=numero;
		letra = fgetc(fp);
	}
}

void Carrega_Fila (TipoFila *Fila_pop,TipoFila *Fila_vip,TipoFila *Fila_normal) {
	int i=0;
	char cpf[13],letra;
	FILE *fp;
	fp = fopen ("fila.txt","a+");
	letra = fgetc(fp);
	if (letra == EOF)
		return;
	while (letra != ':') //TIRA OS >>
		letra = fgetc(fp);
	letra = fgetc(fp);
	letra = fgetc(fp);
	while (letra != '>') { //CARREGA FILA POP
		while (letra != '\n') {
			cpf[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		cpf[i] = '\n';
		cpf[i+1] = '\0';
		Enfileira (cpf,Fila_pop);
		letra = fgetc(fp);
		i=0;
	}
	while (letra != ':') //TIRA OS >>
		letra = fgetc(fp);
	letra = fgetc(fp); //\n?
	letra = fgetc(fp); //1o num
	while (letra != '>') { //CARREGA FILA VIP
		while (letra != '\n') {
			cpf[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		cpf[i] = '\n';
		cpf[i+1] = '\0';
		Enfileira (cpf,Fila_vip);
		letra = fgetc(fp);
		i=0;
	}
	while (letra != ':') //TIRA OS >>
		letra = fgetc(fp);
	letra = fgetc(fp);
	letra = fgetc(fp);
	while (letra != EOF) { //CARREGA FILA NOOBS
		while (letra != '\n') {
			cpf[i] = letra;
			letra = fgetc (fp);
			i++;
		}
		cpf[i] = '\n';
		cpf[i+1] = '\0';
		Enfileira (cpf,Fila_normal);
		letra = fgetc(fp);
		i=0;
	}
}

int Vazia (TipoFila *Fila) {
	if (Fila->Frente == Fila->Tras)
		return 1;
	else
		return 0;
}

void Enfileira (char x[], TipoFila *Fila) { 
	Fila->Tras->Prox = (TipoApontador) malloc (sizeof(TipoCelula));
	Fila->Tras = Fila->Tras->Prox;
	strcpy (Fila->Tras->Pessoa.cpf,x);
	Fila->Tras->Prox = NULL;
}

void Desenfileira (int status, TipoFila *Fila, TipoListaCliente *cliente,TipoListaHotel *hotel,TipoListaVoo *voo,TipoPilhaPasseio *passeio,TipoListaPacote *pacote) {
	TipoApontador q;
	char cpf[13];
	q = Fila->Frente;
	Fila->Frente=Fila->Frente->Prox;
	strcpy (cpf,Fila->Frente->Pessoa.cpf);
	free (q);
	menu_geral (status,cpf,cliente,hotel,voo,passeio,pacote); 
}

void save (TipoFila *Fila_pop,TipoFila *Fila_vip,TipoFila *Fila_q) {
	FILE *fp;
	fp = fopen ("fila.txt","w");
	fprintf (fp,">>>>>>>>>> FILA DOS POPs <<<<<<<<<<:\n");
	while (Fila_pop->Frente->Prox != NULL) {
		Fila_pop->Frente = Fila_pop->Frente->Prox;
		fputs (Fila_pop->Frente->Pessoa.cpf,fp);
	}
	fprintf (fp,">>>>>>>>>> FILA DOS VIPs <<<<<<<<<<:\n");
	while (Fila_vip->Frente->Prox != NULL) {
		Fila_vip->Frente = Fila_vip->Frente->Prox;
		fputs (Fila_vip->Frente->Pessoa.cpf,fp);
	}
	fprintf (fp,">>>>>>>>>> FILA DOS NOOBs <<<<<<<<<<:\n");
	while (Fila_q->Frente->Prox != NULL) {
		Fila_q->Frente = Fila_q->Frente->Prox;
		fputs (Fila_q->Frente->Pessoa.cpf,fp);
	}
	fclose (fp);
}

void save_tudo (TipoListaCliente *cliente, TipoListaHotel *hotel, TipoListaPacote *pacote, TipoListaVoo *voo, TipoPilhaPasseio *passeio) {
	FILE *fpc,*fph,*fppct,*fpv,*fpp;
	fpc = fopen ("cliente.txt","w");
	fph = fopen ("hoteis.txt","w");
	fppct = fopen ("pacote.txt","w");
	fpv = fopen ("voos.txt","w");
	fpp = fopen ("passeios.txt","w");
	cliente->Frente=cliente->Frente->Prox;
	while (cliente->Frente != NULL) {
		fputs (cliente->Frente->Cliente.cpf,fpc);
		fputs (cliente->Frente->Cliente.nome_c,fpc);
		fputs (cliente->Frente->Cliente.end_c,fpc);
		fputs (cliente->Frente->Cliente.telefone_c,fpc);
		fputs (cliente->Frente->Cliente.email_c,fpc);
		fprintf (fpc,"%d\n",cliente->Frente->Cliente.status_c);
		cliente->Frente = cliente->Frente->Prox;
	}
	hotel->Frente=hotel->Frente->Prox;
	while (hotel->Frente != NULL) {
		fprintf (fph,"%d\n",hotel->Frente->Hotel.id_h);
		fputs (hotel->Frente->Hotel.nome_h,fph);
		fputs (hotel->Frente->Hotel.end_h,fph);
		fputs (hotel->Frente->Hotel.cidade_h,fph);
		fprintf (fph,"%d\n",hotel->Frente->Hotel.valor_h);
		fprintf (fph,"%d\n",hotel->Frente->Hotel.qtdd_qtos_disp);
		hotel->Frente = hotel->Frente->Prox;
	}
	pacote->Frente=pacote->Frente->Prox;
	while (pacote->Frente != NULL) {
		fprintf (fppct,"%d\n",pacote->Frente->Pacote.id_v);
		fprintf (fppct,"%d\n",pacote->Frente->Pacote.id_h);
		fprintf (fppct,"%d\n",pacote->Frente->Pacote.id_p);
		pacote->Frente = pacote->Frente->Prox;
	}
	voo->Frente=voo->Frente->Prox;
	while (voo->Frente != NULL) {
		fprintf (fpv,"%d\n",voo->Frente->Voo.id_v);
		fputs (voo->Frente->Voo.cia_aerea,fpv);
		fputs (voo->Frente->Voo.destino,fpv);
		fputs (voo->Frente->Voo.origem,fpv);
		fprintf (fpv,"%d\n",voo->Frente->Voo.dt_ida_dia);
		fprintf (fpv,"%d\n",voo->Frente->Voo.dt_ida_mes);
		fprintf (fpv,"%d\n",voo->Frente->Voo.dt_ida_ano);
		fputs (voo->Frente->Voo.hr_ida,fpv);
		fprintf (fpv,"%d\n",voo->Frente->Voo.dt_chegada_dia);
		fprintf (fpv,"%d\n",voo->Frente->Voo.dt_chegada_mes);
		fprintf (fpv,"%d\n",voo->Frente->Voo.dt_chegada_ano);
		fputs (voo->Frente->Voo.hr_chegada,fpv);
		fprintf (fpv,"%d\n",voo->Frente->Voo.valor_v);
		fprintf (fpv,"%d\n",voo->Frente->Voo.qtdd_lugar_disp_v);
		voo->Frente = voo->Frente->Prox;
	}
	passeio->Frente=passeio->Frente->Prox;
	while (passeio->Frente != NULL) {
		fprintf (fpp,"%d\n",passeio->Frente->Passeio.id_p);
		fputs (passeio->Frente->Passeio.ag_turismo,fpp);
		fputs (passeio->Frente->Passeio.nome_p,fpp);
		fputs (passeio->Frente->Passeio.cidade,fpp);
		fprintf (fpp,"%d\n",passeio->Frente->Passeio.dt_ida_dia_p);
		fprintf (fpp,"%d\n",passeio->Frente->Passeio.dt_ida_mes_p);
		fprintf (fpp,"%d\n",passeio->Frente->Passeio.dt_ida_ano_p);
		fputs (passeio->Frente->Passeio.hr_ida,fpp);
		fputs (passeio->Frente->Passeio.hr_chegada,fpp);
		fprintf (fpp,"%d\n",passeio->Frente->Passeio.valor_p);
		fprintf (fpp,"%d\n",passeio->Frente->Passeio.qtdd_lugar_disp_p);
		passeio->Frente = passeio->Frente->Prox;
	}
}











	
