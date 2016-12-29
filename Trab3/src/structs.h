typedef struct TipoCelula *TipoApontador; //fila
typedef char TipoChave;
typedef struct TipoItem {
	TipoChave cpf[13];
	int status[3];
} TipoItem;

typedef struct TipoCelula {
	TipoItem Pessoa;
	TipoApontador Prox;
}TipoCelula;

typedef struct TipoFila {
	TipoApontador Frente;
	TipoApontador Tras;
}TipoFila;	

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct TipoCelulaHotel *TipoApontadorHotel; //Lista Hotel
typedef char TipoChaveHotel;
typedef struct TipoItemHotel {
	int id_h;
	int valor_h;
	int qtdd_qtos_disp;
	TipoChaveHotel nome_h[52];
	TipoChaveHotel end_h[102];
	TipoChaveHotel cidade_h[22];
} TipoItemHotel;

typedef struct TipoCelulaHotel {
	TipoItemHotel Hotel;
	TipoApontadorHotel Prox;
}TipoCelulaHotel;

typedef struct TipoListaHotel {
	TipoApontadorHotel Frente;
	TipoApontadorHotel Tras;
}TipoListaHotel;	

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct TipoCelulaCliente *TipoApontadorCliente; //Lista Cliente
typedef char TipoChaveCliente;
typedef struct TipoItemCliente {
	TipoChaveCliente cpf[13];
	TipoChaveCliente nome_c[102];
	TipoChaveCliente end_c[102];
	TipoChaveCliente telefone_c[13];
	TipoChaveCliente email_c[32];
	int status_c;
} TipoItemCliente;

typedef struct TipoCelulaCliente {
	TipoItemCliente Cliente;
	TipoApontadorCliente Prox;
}TipoCelulaCliente;

typedef struct TipoListaCliente {
	TipoApontadorCliente Frente;
	TipoApontadorCliente Tras;
}TipoListaCliente;	

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct TipoCelulaVoo *TipoApontadorVoo; //Lista Voo
typedef char TipoChaveVoo;
typedef struct TipoItemVoo {
	int id_v;
	TipoChaveVoo cia_aerea[52];
	TipoChaveVoo destino[22];
	TipoChaveVoo origem[22];
	int dt_ida_dia;
	int dt_ida_mes;
	int dt_ida_ano;
	TipoChaveVoo hr_ida[8];
	int dt_chegada_dia;
	int dt_chegada_mes;
	int dt_chegada_ano;
	TipoChaveVoo hr_chegada[8];
	int valor_v;
	int qtdd_lugar_disp_v;
} TipoItemVoo;

typedef struct TipoCelulaVoo {
	TipoItemVoo Voo;
	TipoApontadorVoo Prox;
}TipoCelulaVoo;

typedef struct TipoListaVoo {
	TipoApontadorVoo Frente;
	TipoApontadorVoo Tras;
}TipoListaVoo;	

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct TipoCelulaPasseio *TipoApontadorPilha; //Pilha passeio
typedef char TipoChavePasseio;
typedef struct TipoItempasseio {
	int id_p;
	TipoChavePasseio ag_turismo[22];
	TipoChavePasseio nome_p[102];
	TipoChavePasseio cidade[22];
	int dt_ida_dia_p;
	int dt_ida_mes_p;
	int dt_ida_ano_p;
	TipoChavePasseio hr_ida[8];
	TipoChavePasseio hr_chegada[8];
	int valor_p;
	int qtdd_lugar_disp_p;
} TipoItemPasseio;

typedef struct TipoCelulaPasseio {
	TipoItemPasseio Passeio;
	TipoApontadorPilha Prox;
}TipoCelulaPasseio;

typedef struct TipoPilhaPasseio {
	TipoApontadorPilha Frente;
	TipoApontadorPilha Tras;
}TipoPilhaPasseio;	

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef struct TipoCelulaPacote *TipoApontadorPacote; //Lista Pacote
typedef char TipoChavePacote;
typedef struct TipoItemPacote {
	int id_v;
	int id_h;
	int id_p;
} TipoItemPacote;

typedef struct TipoCelulaPacote {
	TipoItemPacote Pacote;
	TipoApontadorPacote Prox;
}TipoCelulaPacote;

typedef struct TipoListaPacote {
	TipoApontadorPacote Frente;
	TipoApontadorPacote Tras;
}TipoListaPacote;
