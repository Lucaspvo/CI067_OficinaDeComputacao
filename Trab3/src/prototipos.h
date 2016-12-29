

TipoCelulaCliente * Busca_cpf(char [], TipoListaCliente *);

TipoCelulaHotel * Busca_nome(char [], TipoListaHotel *);

TipoCelulaVoo * Busca_companhia(char [], TipoListaVoo *);

TipoCelulaHotel * Busca_hotel(char [], TipoListaHotel *);

void inclui_cliente(int ,char [], TipoListaCliente *);

void altera_dado_cliente(char [],TipoListaCliente *);

void exclui_cliente(char *,TipoListaCliente *);

void inclui_hotel(TipoListaHotel *);

void altera_dado_hotel(TipoListaHotel *);

void exclui_hotel(TipoListaHotel *);

void pega_data_sistema (int *,int *,int *);

void cria_pacote_turistico(TipoListaVoo *, TipoListaPacote *, TipoListaHotel *, TipoPilhaPasseio *);

void menu_geral (int , char *,TipoListaCliente *,TipoListaHotel *,TipoListaVoo *,TipoPilhaPasseio *,TipoListaPacote *);



int confere_hotel (TipoListaHotel *, char [], int , TipoListaPacote *);

int confere_passeio(TipoPilhaPasseio *, char [], int , int , int , int , int , int , int ,TipoListaPacote *);

void FFVazia (TipoFila *);

void FLVazia_H (TipoListaHotel *);

void FLVazia_C (TipoListaCliente *);

void FLVazia_V (TipoListaVoo *);

void FPVazia_P (TipoPilhaPasseio *);

void FLVazia_P (TipoListaPacote *);

void Carrega_Hotel (TipoListaHotel *);

void Carrega_Cliente (TipoListaCliente *);

void Carrega_Voo (TipoListaVoo *);

void Carrega_Passeio (TipoPilhaPasseio *);

void Carrega_Pacote (TipoListaPacote *);

void Carrega_Fila (TipoFila *,TipoFila *,TipoFila *);

int Vazia (TipoFila *);

void Enfileira (char [], TipoFila *);

void Desenfileira (int , TipoFila *, TipoListaCliente *,TipoListaHotel *,TipoListaVoo *,TipoPilhaPasseio *,TipoListaPacote *);

void save (TipoFila *,TipoFila *,TipoFila *);

int bissexto (int );

int transforma_data (int , int , int );

void valida_nome(char *);

void valida_endereco(char *); 

void valida_telefone(char *);

void valida_email(char *);

int valida_cpf(char []);

int valida_data(int , int , int );

int valida_cidade(char []);

int valida_hotel(char []);

int valida_quantidade(int );

void inclui_voo(TipoListaVoo *);

void altera_dado_voo(TipoListaVoo *);

void exclui_voo(TipoListaVoo *);

void menu_cliente (int , char [], TipoListaCliente *,TipoListaHotel *,TipoListaVoo *,TipoPilhaPasseio *);

TipoCelulaPasseio * Busca_passeio(char [] , TipoPilhaPasseio *);

void inclui_passeio(TipoPilhaPasseio *);

void altera_dado_passeio(TipoPilhaPasseio *);

void exclui_passeio(TipoPilhaPasseio *);

void save_tudo (TipoListaCliente *, TipoListaHotel *, TipoListaPacote *, TipoListaVoo *, TipoPilhaPasseio *);

