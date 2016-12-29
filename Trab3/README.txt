													LEIAME:
	=====================================================												
	Autoria:	André Purri Ziviani		GRR20118044
			Lucas Pazelo Vargas de Oliveira GRR20113495
	=====================================================
	
	MÓDULOS:
	
	bin...................(pasta que contém o executavel);
	src...................(pasta que contém os códigos fonte abaixo);
	agturismo.c...........(é o main da função);
	busca.c...............(fornece o endereço de memória do item a ser encontrado(caso não exista retorna NULL);
	cliente.c.............(realiza as funções inclui, altera dados e exclui cliente);
	data.c................(fornece a data do sistema);
	hoteis.c..............(realiza as funções inclui, altera dados e exclui hoteis);
	makefile..............(arquivo para compilar o programa);
	menu_ger.c............(gerencia as opções que desejamos escolher para trabalhar com as demais funções);
	pacote.c..............(cria o pacote turístico);
	passagem.c............(confere se existem voos, hoteis e passeios disponíveis);
	passeios.c............(realiza as funções inclui, altera dados e exclui passeios);
	structs.c.............(encontra-se as funções enfileira, desenfileira, cria lista e fila e carrega da struct pro arquivo e do arquivo para a struct);
	transforma_data.c.....(converte a data de dia, mes e ano apenas para dias);
	valida.c..............(realiza a validação das entradas);
	voos.c................(realiza as funções inclui, altera dados e exclui voos);
	prototipos.h..........(contém todas as funções utilizadas no programa);
	struct.h..............(contém as structs das quais utilizamos nas funções);
	
	
	COMO COMPILAR O CÓDIGO FONTE:
		$ cd src
		$ make tudo
		$ cd ../bin
		$ ./agturismo
	
	CAPÍTULO ESPECIAL:
	
	=====================Módulos Voo, Hotel, Passeio, Cliente=====================
	->Nos algoritmos de inclui realizamos a validação das entradas e, de acordo com a struct
 que estamos lidando, acrescentamos os itens utilizando funções específicas para inserir na
 lista ou para enfileirar na fila ou ainda empilhar na pilha;
	->Nos algoritmos de exclui realizamos, praticamente, os mesmos procedimentos que no inclui,
 só que utilizando funções específicas para excluir de lista, fila e pilha(quando necessário);
	==============================================================================
	
	=====================Fila, Pilha, Lista=======================================
	->As estruturas de dados que implementamos para armazenar as informações obtidas de
 cliente, hotel, voo e passeio foram listas e pilhas. As listas foram utilizadas nas funções
 de cliente, hotel e voo porque, como tais structs estao em constante mudança, ou seja, as
 informações delas sao atualizadas constantemente, a lista é uma operação mais simples de se
 trabalhar, pois com ela podemos excluir de qualquer parte da lista, sem nos preocuparmos em
 retirar os itens anteriores para excluir um item específico e depois recolocar os itens
 retirados. Já a pilha foi utilizada nos passeios porque, como o passeio irá permanecer,
 praticamente, inalterado, não há a necessidade de atualizá-lo constantemente, apenas quando
 realiza-se a inclusão de um novo passeio. Já a fila, também utilizada em nosso programa, se
 restringe apenas em guardar os cpfs que são fornecidos quando o cliente chega no local, mas
 sempre realizando todas as funções com o cpf que se encontra na frente da fila.
	==============================================================================
	
	=========================Módulo pacote.c======================================
	->No pacote.c é utilizado um algoritmo que, para criar o pacote turístico, confere em todo
 o sistema passagens que coincidam com as datas fornecidas pelo cliente, assim como hotéis e
 passeios, uma vez conferido isso, o cliente pode realizar a compra.
	==============================================================================
	
	============================Módulo passagem.c=================================
	->A função que auxilia na criação do pacote turístico é a passagem.c pois, a mesma é a
 grande responzável em percorrer todas as structs de voos, hotéis e passeios para verificar
 se o cliente consiguirá realizar a viagem no período fornecido pelo mesmo.Sempre trabalhando
 com ponteiros para verificar nas listas e pilha.
	==============================================================================
	
	================================Validação data================================
	->A função pega_data_sistema foi implementada para fornecer a data do dia, que será
 utilizada para conferir se a data em que o cliente deseja viajar não é uma data inválida,
 por exemplo, dia atual 10/10/2011, data para viajar 10/09/2011, data inválida.
	==============================================================================
	
	================================Módulo transforma_data.c======================
	->A função transforma_data foi implementada na instancia de realizarmos a checagem das
 datas para as passagens utilizando apenas dias, sem ter a preocupação da mudança de mes, por
 exemplo, caso o cliente queira viajar 10 dias, no período de 25/09 à 15/10, para não me
 preocupar com a passagem de mes e a passagem do dia 30 ou 31(dependendo do mes) para o
 primeiro, eu transformo as datas em dias do ano e trabalho encima de apenas um inteiro.
	==============================================================================
	
	=================================Módulo agturismo.c==========================
	->Este arquivo contém o main e o menu principal do programa.
	==============================================================================
	
	=================================Módulo Busca.c===============================
	->Realiza a busca pelo item que se deseja encontrar, retornando o endereço de memória
	ou NULL, caso o mesmo não seja encontrado.
	==============================================================================
	
	================================Módulo menu_ger.c=============================
	->Este arquivo contém os seguintes menus:
					MENU GERAL                           MENU CLIENTE
			1.Cria Pacote                          1.Inclui cliente
			2.Gerencia Cliente                     2.Altera dado cliente
			                                       3.Exclui cliente
	==============================================================================
	
	================================Módulo prototipos.h===========================
	->Concentra todos os protótipos de todas as funções do programa.
	==============================================================================
	
	================================Módulo structs.c==============================
	->Concentra as funções que criam, inicializam as Listas, Filas e a Pilha.
	->Também contém as funções de carrega informações do arquivo .txt para as structs,
	assim como das strcuts para os arquivos .txt.
	==============================================================================
	
	================================Módulo structs.h==============================
	->Tal arquivo possui as definições de Lista, Fila e Pilha.
	==============================================================================
	
	================================Módulo valida.c===============================
	->O arquivo valida, nome, endereço, telefone, email, cpf, data, cidade, hotel,
	quantidade.
	==============================================================================  
	
	==============================================================================
	->A versão do programa que foi entregue foi escolhido pois, consideramos os algoritmos
 implementados como os mais compatíveis e eficientes.
	==============================================================================
	 
	BUGS CONHECIDOS:
	->No módulo passagem.c, ao escolher o passeio, a função retornará para o módulo pacote.c, onde será realizada, novamente, a pergunta se o cliente deseja efetuar a compra do passeio.
	
	OUTRAS INFORMAÇÕES IMPORTANTES:
	
	->Nas structs Voo, Hotel e Passeio foi criado um novo item, id_h/id_v/id_p, para utilizar
 na hora de realizar a criação do pacote. Quando é encontrado um voo, um hotel e um passeio
 em que estejam dentro da data de viagem do cliente, seus ids são salvos na struct pacote
 para que depois, para achar as informações do pacote e mostrá-las ao cliente, comparemos os
 ids do pacote com seus respectivos ids de voo, hotel e passeio até que encontrem as células
 de seus respectivos ids, jogando diretamente das structs para a tela. Logo depois, quando
 realizada a compra do pacote, é decrementado o número de pessoas da quantidade de lugares
 disponíveis de cada uma das structs.
	->Na Pilha Passeio, foi adicionado o char cidade, para que dessa maneira, quando o cliente
 realiza a compra de um passeio, seja confirmado que tal passeio será realizado no local de
 destino da viagem.
	->É criado o arquivo Pacote.txt para armazenar os pacotes anteriores.
	->Os cpfs que estao na fila para serem atendidos são registrados como especial, vip ou normal.
	->Nos módulos cliente.c, voos.c, hoteis.c e passeio.c foi implementado, em cada um, a função altera_dado.
	->Cada passeio encontrado, um por vez, será mostrado as informações para o cliente, caso ele recuse o passeio, será procurado outro até que não existam mais passeios na pilha. Caso contrário o cliente irá comprar somente o passeio escolhido.
	
