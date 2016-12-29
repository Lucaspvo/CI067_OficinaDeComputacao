#include <stdio.h>
#include <string.h>
#include <stdlib.h>

	struct dados_cliente
	{
		char cpf[20];
		char nome[102];
		char endereco[102];
		char telefone[14];
		char emprestimo[2];
	};

	struct informacoes_livro
	{
		char tombo[10];
		char titulo[152];
		char autor[102];
		char editora[102];
		char emprestimo[2];
	};
		
	struct dados_emprestimo
	{
		char cpf[20];
		char tombo[10];
		char status[11];
		char data_hj [14];
	};

//==============================================================Operações Cliente=======================================================================================

struct dados_cliente * carrega_struct_usuario(struct dados_cliente *cliente, FILE *fpu, int *tam_u)
	{
		int i, j;
		char ch;
		i=0;
		j=0;
		ch = fgetc (fpu);
		while (ch != EOF) 
		{
			while (ch != '\n') 
			{
				cliente[j].cpf[i]=ch;
				ch = fgetc (fpu);
				i++;
			}
			cliente[j].cpf[i]='\n';
			i=0;
			ch = fgetc (fpu);
			while (ch != '\n') 
			{
				cliente[j].nome[i]=ch;
				ch = fgetc (fpu);
				i++;
			}
			cliente[j].nome[i]='\n';
			i=0;
			ch = fgetc (fpu);
			while (ch != '\n') 
			{
				cliente[j].endereco[i]=ch;
				ch = fgetc (fpu);
				i++;
			}
			cliente[j].endereco[i]='\n';
			i=0;
			ch = fgetc (fpu);
			while (ch != '\n') 
			{
				cliente[j].telefone[i]=ch;
				ch = fgetc (fpu);
				i++;
			}
			cliente[j].telefone[i]='\n';
			ch = fgetc (fpu);
			cliente[j].emprestimo[0]=ch;
			cliente[j].emprestimo[1]='\n';
			ch = fgetc (fpu);
			ch = fgetc (fpu);
			i=0;
			j++;
			(*tam_u)++;
			cliente = (struct dados_cliente *) realloc (cliente,((*tam_u)+1)*sizeof(struct dados_cliente));
		}
		return cliente;
	}

	int carrega_arquivo_usuario(struct dados_cliente *cliente, FILE *fpu, int tam_u)
	{
		int j;
		j=0;
		while (j<tam_u) 
		{
				fputs(cliente[j].cpf, fpu);
				fputs(cliente[j].nome, fpu);
				fputs(cliente[j].endereco, fpu);
				fputs(cliente[j].telefone, fpu);
				fputc(cliente[j].emprestimo[0], fpu);
				fputc(cliente[j].emprestimo[1], fpu);
			j++;
		}
		return j;
	}
	
	int confere_cpf(char cpf[])
	{
		int i, conf=0;
		i=-1;
				while ((conf==0) && (i<12))
				{
					i++;
					conf=isalpha(cpf[i]);
				}
				return conf;
	}
	
	int incluir_cliente(struct dados_cliente *cliente, int tam_u)
	{
		int i, tem=1, cont, conf=1, aux=0;//cont=contador para aumentar o tamanho de clientes existentes
		char cpf[20], ch;
		cont=tam_u;
		system("clear");
		printf("Digite o cpf: ");
		fgets(cpf, 20, stdin);
		if (cpf[0]!='\n')
		{
		while (aux==0)
		{
			if (cpf[11]=='\n')
			{
					if (confere_cpf(cpf)==0)
					{
						i=-1;
						while (tem!=0 && i<tam_u)
						{
							i++;
							tem=strncmp(cliente[i].cpf,cpf,11);
						}
							if (tem!=0)
							{
								strncpy(cliente[tam_u].cpf, cpf, 12);
								printf("Digite o nome: ");
								fgets(cliente[tam_u].nome, 102, stdin);
								//=====================Valida Nome=========================
								i=0;
								conf=1;
								if (cliente[tam_u].nome[i]=='\n')
									conf=0;
								if (conf==0)
								{
									while (conf==0)
									{
										system("clear");
										printf("O nome não foi digitado!\n\n");
										printf("Digite o nome novamente: ");
										fgets(cliente[tam_u].nome, 102, stdin);
										i=0;
										conf=1;
										if (cliente[tam_u].nome[i]=='\n')
											conf=0;
									}
								}
								//===============================================
								printf("Digite o endereço: ");
								fgets(cliente[tam_u].endereco, 102, stdin);
								//=====================Valida Endereço=========================
								i=0;
								conf=1;
								if (cliente[tam_u].endereco[i]=='\n')
									conf=0;
								if (conf==0)
								{
									while (conf==0)
									{
										system("clear");
										printf("O endereço não foi digitado!\n\n");
										printf("Digite o endereço novamente: ");
										fgets(cliente[tam_u].endereco, 102, stdin);
										i=0;
										conf=1;
										if (cliente[tam_u].endereco[i]=='\n')
											conf=0;
									}
								}
								//===============================================
								printf("Digite o telefone(0xx): ");
								fgets(cliente[tam_u].telefone, 20, stdin);
								//===================Valida Telefone===========================
								i=0;
								conf=0;
								if ((cliente[tam_u].telefone[i]=='\n') || (cliente[tam_u].telefone[11]!='\n') || (cliente[tam_u].telefone[0]!='0'))
									conf=1;
								while ((conf==0) && (cliente[tam_u].telefone[i]!='\n'))
								{
									conf=isalpha(cliente[tam_u].telefone[i]);
									i++;
								}
								while (conf)
								{
									system("clear");
									printf("O telefone anterior foi digitado incorretamente!\n\n");
									printf("Digite o telefone novamente(0xx): ");
									fgets(cliente[tam_u].telefone, 20, stdin);
									i=0;
									conf=0;
									if ((cliente[tam_u].telefone[i]=='\n') || (cliente[tam_u].telefone[11]!='\n') || (cliente[tam_u].telefone[0]!='0'))
										conf=1;
									while ((conf==0) && (cliente[tam_u].telefone[i]!='\n'))
									{
										conf=isalpha(cliente[tam_u].telefone[i]);
										i++;
									}
								}
								//===============================================
								cliente[tam_u].emprestimo[0]='0';
								cliente[tam_u].emprestimo[1]='\n';
								cont=cont+1;
								aux=1;
								system("clear");
								printf("O cliente foi cadastrado!\n\n");
								printf("Pressione enter para voltar!\n");
								getchar();
							}
							else
							{
								printf("O cliente já está cadastrado!\n");
								printf("Pressione enter para voltar!\n\n");
								getchar();
								aux=1;
							}
					}
					else
					{
						system("clear");
						printf("Número de cpf não válido!\n\n");
						printf("Digite o CPF novamente: ");
						fgets(cpf, 20, stdin);
						aux=0;
					}
			}
			else
			{
				system("clear");
				printf("Número de cpf não válido!\n\n");
				printf("Digite o CPF novamente: ");
				fgets(cpf, 20, stdin);
				aux=0;
			}
		}
		}
		return cont;
	}

	void busca_cliente(struct dados_cliente *cliente, int tam_u)
	{
		int i, tem, aux, num;
		char cpf[20];
		system("clear");
		printf("Digite o cpf da pessoa que deseja procurar: ");
		fgets(cpf, 20, stdin);
		aux=0;
		while (aux==0)
		{
			if (cpf[0]!='\n')
			{
					if (cpf[11]=='\n')
					{
						if (confere_cpf(cpf)==0)
						{
							i=-1;
							while (tem!=0 && i<tam_u)
							{
								i++;
								tem=strncmp(cliente[i].cpf,cpf,11);
							}
							if (tem==0)
							{
								printf("NOME: ");
								puts(cliente[i].nome);
								printf("ENDEREÇO: ");
								puts(cliente[i].endereco);
								printf("TELEFONE: ");
								puts(cliente[i].telefone);
								printf("EMPRÉSTIMO: ");
								fputc(cliente[i].emprestimo[0],stdout);
								printf("\n\nPressione enter para continuar!");
								getchar();
								aux=1;
							}
							else
							{
								system("clear");
								printf("O CPF digitado não esta cadastrado!\n\n");
								printf("Deseja sair do modo busca cliente?(Digite o número)  1.y | 2.n  \n");
								scanf("%d", &num);
								getchar();
								if (num==2)
								{
									system("clear");
									printf("Digite o CPF novamente: ");
									fgets(cpf, 20, stdin);
								}
								else
									aux=1;
							}																						
						}
						else
						{
							printf("Número de CPF não válido!\n");
							printf("Digite o cpf novamente: ");
							fgets(cpf, 20, stdin);
						}
					}
					else
					{
						printf("Número de CPF não válido!\n");
						printf("Digite o cpf novamente: ");
						fgets(cpf, 20, stdin);
					}
			}
			else
			{
				printf("Deseja sair do modo busca cliente? 1.y | 2.n");
				scanf("%d", &num);
				getchar();
				if (num==2)
				{
					system("clear");
					printf("Digite o CPF novamente: ");
					fgets(cpf, 20, stdin);
				}
				else
					aux=1;
			}
		}
	}
	
	
	void altera_dado_cliente(struct dados_cliente *cliente, int tam_u)
	{
		int i, tem=1, conf, num_e, aux=0, num, j;
		char cpf[20];
		system("clear");
		printf("Digite o CPF do cliente que deseja alterar os dados: ");
		fgets(cpf, 20, stdin);
		while (aux==0)
		{
			if (cpf[0]!='\n')
			{
							if (cpf[11]=='\n')
							{
								if (confere_cpf(cpf)==0)
								{
									i=-1;
									while (tem!=0 && i<tam_u)
									{
										i++;
										tem=strncmp(cliente[i].cpf,cpf,11);
									}
									if ((cliente[i].emprestimo[0]=='0') && (tem==0))
									{
										system("clear");
										printf("Qual dado deseja alterar?\n\n1.CPF\n2.Nome\n3.Endereço\n4.Telefone\n\nDigite sua opção: ");
										scanf("%d", &num_e);
										getchar();
										while (aux==0 && num_e<5)
										{
											if (num_e==1)
											{
												system("clear");
												printf("CPF\n");
												printf("Digite o novo CPF: ");
												fgets(cliente[i].cpf, 20, stdin);
												//===================Valida CPF===========================
													j=0;
													conf=0;
													if (cliente[i].cpf[j]=='\n')
														conf=1;
													while ((conf==0) && (cliente[i].cpf[j]!='\n'))
														{
															conf=isalpha(cliente[i].cpf[j]);
															j++;
														}
													while (conf)
													{
														system("clear");
														printf("O CPF anterior foi digitado incorretamente!");
														printf("Digite o CPF novamente: ");
														fgets(cliente[tam_u].cpf, 14, stdin);
														j=0;
														conf=0;
														if (cliente[i].cpf[j]=='\n')
															conf=1;
														while ((conf==0) && (cliente[i].cpf[j]!='\n'))
														{
															conf=isalpha(cliente[i].cpf[j]);
															j++;
														}
													}
													//===============================================
											}
											if (num_e==2)
											{
												system("clear");
												printf("Nome\n");
												printf("Digite o novo nome: ");
												fgets(cliente[i].nome, 102, stdin);
												//=====================Valida Nome=========================
													j=0;
													conf=1;
													if (cliente[i].nome[j]=='\n')
														conf=0;
													if (conf==0)
													{
														while (conf==0)
														{
															system("clear");
															printf("O nome anterior foi digitado incorretamente!");
															printf("Digite o nome novamente: ");
															fgets(cliente[i].nome, 14, stdin);
															j=0;
															conf=1;
															if (cliente[i].nome[j]=='\n')
																conf=0;
														}
													}
													//===============================================
											}
											if (num_e==3)
											{
												system("clear");
												printf("Endereço\n");
												printf("Digite o novo endereço: ");
												fgets(cliente[i].endereco, 102, stdin);
												//=====================Valida Endereço=========================
												j=0;
												conf=1;
												if (cliente[i].endereco[j]=='\n')
													conf=0;
												if (conf==0)
												{
													while (conf==0)
													{
														system("clear");
														printf("O endereço não foi digitado!\n\n");
														printf("Digite o endereço novamente: ");
														fgets(cliente[i].endereco, 102, stdin);
														j=0;
														conf=1;
														if (cliente[i].endereco[j]=='\n')
															conf=0;
													}
												}
												//===============================================
											}
											if (num_e==4)
											{
												system("clear");
												printf("Telefone\n");
												printf("Digite o novo telefone(0xx): ");
												fgets(cliente[i].telefone, 12, stdin);
												//===================Valida Telefone===========================
													j=0;
													conf=0;
													if ((cliente[i].telefone[j]=='\n') || (cliente[i].telefone[11]!='\n') || (cliente[i].telefone[0]!='0'))
														conf=1;
													while ((conf==0) && (cliente[i].telefone[j]!='\n'))
													{
														conf=isalpha(cliente[i].telefone[j]);
														j++;
													}
													while (conf)
													{
														system("clear");
														printf("O telefone anterior foi digitado incorretamente!");
														printf("Digite o telefone novamente: ");
														fgets(cliente[i].telefone, 14, stdin);
														j=0;
														conf=0;
														if ((cliente[i].telefone[j]=='\n') || (cliente[i].telefone[11]!='\n') || (cliente[i].telefone[0]!='0'))
															conf=1;
														while ((conf==0) && (cliente[i].telefone[j]!='\n'))
														{
															conf=isalpha(cliente[i].telefone[j]);
															j++;
														}
													}
													//===============================================
											}
											system("clear");
											printf("Deseja alterar mais algum dado?\n\n1.CPF\n2.Nome\n3.Endereço\n4.Telefone\n5.Voltar\n\nDigite sua opção: ");
											scanf("%d", &num_e);
											getchar();
										}
										aux=1;
										system("clear");
										printf("Os dados do cliente foram alterados!\n\n");
										printf("Pressione enter para voltar!\n");
										getchar();
									}
									else
									{
										if (tem)
										{
											system("clear");
											printf("O CPF digitado não esta cadastrado!");
											printf("Deseja sair do modo altera dado cliente?(Digite o número)  1.y | 2.n  \n");
											scanf("%d", &num);
											getchar();
											if (num==2)
											{
												system("clear");
												printf("Digite o CPF novamente: ");
												fgets(cpf, 20, stdin);
											}
											else
												aux=1;
										}
										else
										{
											system("clear");
											printf("O cliente em questão possui empréstimos!\n\n");
											printf("Não é permitido a alteração de dados do cliente!");
											printf("Pressione enter para continuar!");
											getchar();
											aux=1;
										}
									}
								}
								else
								{
									system("clear");
									printf("Número de CPF não válido!\n\n");
									printf("Digite o CPF novamente: ");
									fgets(cpf, 20, stdin);
								}
							}
							else
							{
								system("clear");
								printf("Número de CPF não válido!\n\n");
								printf("Digite o CPF novamente: ");
								fgets(cpf, 20, stdin);
							}
			}
			else
			{
				printf("Deseja sair do modo altera dados? 1.y | 2.n");
				scanf("%d",&num);
				getchar();
				if (num==2)
				{
					system("clear");
					printf("Digite o CPF novamente: ");
					fgets(cpf, 20, stdin);
				}
				else
					aux=1;
			}
		}
	}
			
	int exclui_cliente(struct dados_cliente *cliente, int tam_u)
	{
		int i, tem, cont, aux=0, num;
		char cpf[20];
		system("clear");
		printf("Digite o cpf do cliente que deseja excluir: ");
		fgets(cpf, 20, stdin);
		cont=tam_u;
		while (aux==0)
		{
			if (cpf[0]!='\n')
			{
					if (cpf[11]=='\n')
					{
						if (confere_cpf(cpf)==0)
						{
							i=-1;
							while (tem!=0 && i<tam_u)
							{
								i++;
								tem=strncmp(cliente[i].cpf,cpf,11);
							}
							if ((cliente[i].emprestimo[0]=='0') && (tem==0))
							{
								if (i!=tam_u)
								{
									tam_u--;
									strncpy(cliente[i].cpf, cliente[tam_u].cpf,13);
									strncpy(cliente[i].nome, cliente[tam_u].nome,102);
									strncpy(cliente[i].endereco, cliente[tam_u].endereco,102);
									strncpy(cliente[i].telefone, cliente[tam_u].telefone,14);
									strncpy(cliente[i].emprestimo, cliente[tam_u].emprestimo,2);
									cont=cont-1;
									aux=1;
								}
								printf("O cliente foi excluido com sucesso!\n\n");
								printf("Pressione enter para continuar!\n\n");
								getchar();
							}
							else
							{
								system("clear");
								printf("O CPF digitado não esta cadastrado!\n\n");
								printf("Deseja sair do modo exclui cliente?(Digite o número)  1.y | 2.n  \n");
								scanf("%d", &num);
								getchar();
								if (num==2)
								{
									system("clear");
									printf("Digite o CPF novamente: ");
									fgets(cpf, 20, stdin);
								}
								else
									aux=1;
							}	
						}
						else
						{
							system("clear");
							printf("O cpf foi escrito incorretamente!\n\n");
							printf("Digite o CPF novamente: ");
							fgets(cpf, 20, stdin);
						}
					}
					else
					{
						system("clear");
						printf("O cpf possui um número de dígitos superior ao permitido!\n\n");
						printf("Digite o CPF novamente: ");
						fgets(cpf, 20, stdin);
					}
			}
			else
			{
				printf("Deseja sair do modo exclui cliente?  1.y | 2.n\n");
				scanf("%d", &num);
				getchar();
				if (num==2)
				{
					system("clear");
					printf("Digite o CPF novamente: ");
					fgets(cpf, 20, stdin);
				}
				else
					aux=1;
			}
		}
		return cont;
	}


	struct dados_cliente * cliente_f(struct dados_cliente *cliente, int *tam_u)
	{
			int num;
			system("clear");
			printf("1.Incluir Cliente\n2.Busca de Cliente pelo CPF\n3.Alterar dados de um cliente\n4.Excluir Cliente\n5.Voltar");
			printf("\n");
			printf("\n");
			printf("DIGITE A OPÇÃO: ");
			scanf("%d", &num);
			getchar();
			while ((num<5) || (num>5))
			{
				if (num==1) {
					incluir_cliente(cliente,*tam_u);
					(*tam_u)++;
					cliente = (struct dados_cliente *) realloc (cliente,((*tam_u)+1)*sizeof (struct dados_cliente));
					}
				if (num==2)
					busca_cliente(cliente, *tam_u);
				if (num==3)
					altera_dado_cliente(cliente, *tam_u);
				if (num==4) {
					exclui_cliente(cliente,*tam_u);
					(*tam_u)--;
					cliente = (struct dados_cliente *) realloc (cliente,((*tam_u)+1)*sizeof (struct dados_cliente));
					}
				if (num==5)
					return cliente;
				system("clear");
				printf("1.Incluir Cliente\n2.Busca de Cliente pelo CPF\n3.Alterar dados de um cliente\n4.Excluir Cliente\n5.Voltar");
				printf("\n");
				printf("\n");
				printf("DIGITE A OPÇÃO: ");
				scanf("%d", &num);
				getchar();
			}
			return cliente;
	}

//==================================================================Operações Livro==================================================================================

	struct informacoes_livro * carrega_struct_livro(struct informacoes_livro *livro, FILE *fpl,int *tam_l)
	{
		int i, j;
		char ch;
		i=0;
		j=0;
		ch = fgetc (fpl);
		while (ch != EOF) 
		{
			while (ch != '\n') 
			{
				livro[j].tombo[i]=ch;
				ch = fgetc (fpl);
				i++;
			}
			livro[j].tombo[i]='\n';
			i=0;
			ch = fgetc (fpl);
			while (ch != '\n') 
			{
				livro[j].titulo[i]=ch;
				ch = fgetc (fpl);
				i++;
			}
			livro[j].titulo[i]='\n';
			i=0;
			ch = fgetc (fpl);
			while (ch != '\n') 
			{
				livro[j].autor[i]=ch;
				ch = fgetc (fpl);
				i++;
			}
			livro[j].autor[i]='\n';
			i=0;
			ch = fgetc (fpl);
			while (ch != '\n') 
			{
				livro[j].editora[i]=ch;
				ch = fgetc (fpl);
				i++;
			}
			livro[j].editora[i]='\n';
			i=0;
			ch = fgetc (fpl);
			livro[j].emprestimo[0]=ch;
			livro[j].emprestimo[1]='\n';
			ch = fgetc (fpl);
			ch = fgetc (fpl);
			i=0;
			j++;
			(*tam_l)++;
			livro = (struct informacoes_livro *) realloc (livro,((*tam_l)+1)*sizeof(struct informacoes_livro));
		}
		return livro;
	}

	int carrega_arquivo_livro(struct informacoes_livro *livro, FILE *fpl, int tam_l)
	{
		int j, i;
		j=0;
		while (j<tam_l) 
		{
				for (i=0; i<8; i++)
					fputc(livro[j].tombo[i], fpl);
				fprintf (fpl,"\n");
				fputs(livro[j].titulo, fpl);
				fputs(livro[j].autor, fpl);
				fputs(livro[j].editora, fpl);
				fputc(livro[j].emprestimo[0], fpl);
				fputc(livro[j].emprestimo[1], fpl);
			j++;
		}
		return j;
	}
	
	int confere_tombo_char(char tombo[])
	{
		int i, conf, cont=0;
		i=-1;
				while (i<7)
				{
					i++;
					conf=isalpha(tombo[i]);
					if (conf)
						cont++;
				}
				return cont;
	}
	
	int confere_tombo_int(char tombo[])
	{
		int i, conf, cont=0;
		i=-1;
				while (i<7)
				{
					i++;
					conf=isalpha(tombo[i]);
					if (conf==0)
						cont++;
				}
				return cont;
	}
	
	int incluir_livro(struct informacoes_livro *livro, int tam_l)
	{
		int cont, aux=0, num, i, tem, conf;//cont=contador para aumentar o tamanho de livros cadastrados
		char tombo[20];
		cont=tam_l;
		system("clear");
		printf("Digite o código do livro: ");
		fgets(tombo, 20, stdin);
		while (aux==0)
		{
			if (tombo[0]!='\n')
			{
				if (tombo[8]=='\n')
				{
					if ((confere_tombo_char(tombo)==2) && (confere_tombo_int(tombo)==6))
					{
								strncpy(livro[tam_l].tombo, tombo, 10);
								printf("Digite o título do livro: ");
								fgets(livro[tam_l].titulo, 152, stdin);
								//=====================Valida Título=========================
								i=0;
								conf=1;
								if (livro[tam_l].titulo[i]=='\n')
									conf=0;
								if (conf==0)
								{
									while (conf==0)
									{
										system("clear");
										printf("O título anterior foi digitado incorretamente!\n\n");
										printf("Digite o título novamente: ");
										fgets(livro[tam_l].titulo, 152, stdin);
										i=0;
										conf=1;
										if (livro[tam_l].titulo[i]=='\n')
											conf=0;
									}
								}
								//===============================================
								printf("Digite o autor do livro: ");
								fgets(livro[tam_l].autor, 102, stdin);
								//=====================Valida Autor=========================
								i=0;
								conf=1;
								if (livro[tam_l].autor[i]=='\n')
									conf=0;
								if (conf==0)
								{
									while (conf==0)
									{
										system("clear");
										printf("O nome do autor foi digitado incorretamente!\n\n");
										printf("Digite o nome do autor novamente: ");
										fgets(livro[tam_l].autor, 152, stdin);
										i=0;
										conf=1;
										if (livro[tam_l].autor[i]=='\n')
											conf=0;
									}
								}
								//===============================================
								printf("Digite a editora do livro: ");
								fgets(livro[tam_l].editora, 102, stdin);
								//=====================Valida Editora=========================
								i=0;
								conf=1;
								if (livro[tam_l].editora[i]=='\n')
									conf=0;
								if (conf==0)
								{
									while (conf==0)
									{
										system("clear");
										printf("O nome da editora foi digitado incorretamente!\n\n");
										printf("Digite o nome da editora novamente: ");
										fgets(livro[tam_l].editora, 152, stdin);
										i=0;
										conf=1;
										if (livro[tam_l].editora[i]=='\n')
											conf=0;
									}
								}
								//===============================================
								livro[tam_l].emprestimo[0] = '0';
								livro[tam_l].emprestimo[1] = '\n';
								cont=cont+1;
								aux=1;
								system("clear");
								printf("O livro foi cadastrado com sucesso!\n\n");
								printf("Pressione enter para voltar!");
								getchar();
					}
					else
					{
						system("clear");
						printf("O código do livro digitado é inválido!\n\n");
						printf("Digite o código do livro novamente: ");
						fgets(tombo, 20, stdin);
					}
				}
				else
				{
					system("clear");
					printf("O código do livro foi escrito incorretamente!\n\n");
					printf("Digite o código do livro novamente: ");
					fgets(tombo, 20, stdin);
				}
			}
			else
			{
				printf("Deseja sair do modo exclui cliente?  1.y | 2.n\n");
				scanf("%d", &num);
				getchar();
				if (num==2)
				{
					system("clear");
					printf("Digite o código do livro novamente: ");
					fgets(tombo, 20, stdin);
				}
				else
					aux=1;
			}
		}
		return cont;
	}

	void busca_livro(struct informacoes_livro *livro, int tam_l)
	{
		int i, tem, aux=0, num;
		char tombo[20];
		system("clear");
		printf("Digite o código do livro que deseja procurar: ");
		fgets(tombo, 20, stdin);
		while (aux==0)
		{
			if (tombo[0]!='\n')
			{
				if (tombo[8]=='\n')
				{
					if ((confere_tombo_char(tombo)==2) && (confere_tombo_int(tombo)==6))
					{
						i=-1;
						while (tem!=0 && i<tam_l)
						{
							i++;
							tem=strncmp(livro[i].tombo,tombo,8);
						}
						if (tem==0)
						{
							printf("TÍTULO: ");
							puts(livro[i].titulo);
							printf("AUTOR: ");
							puts(livro[i].autor);
							printf("EDITORA: ");
							puts(livro[i].editora);
							printf("EMPRÉSTIMO: ");
							fputc(livro[i].emprestimo[0],stdout);
							printf("\n\nPressione enter para continuar!");
							getchar();
							aux=1;
						}
						else
						{
							system("clear");
							printf("O código do livro digitado não esta cadastrado!\n\n");
							printf("Deseja sair do modo busca livro?(Digite o número)  1.y | 2.n  \n");
							scanf("%d", &num);
							getchar();
							if (num==2)
							{
								system("clear");
								printf("Digite o CPF novamente: ");
								fgets(tombo, 50, stdin);
							}
							else
								aux=1;
						}	
					}
					else
					{
						system("clear");
						printf("O código do livro digitado é inválido!\n\n");
						printf("Digite o código do livro novamente: ");
						fgets(tombo, 20, stdin);
					}
				}
				else
				{
					system("clear");
					printf("O código do livro foi escrito incorretamente!\n\n");
					printf("Digite o código do livro novamente: ");
					fgets(tombo, 20, stdin);
				}
			}
			else
			{
				printf("Deseja sair do modo exclui cliente?  1.y | 2.n\n");
				scanf("%d", &num);
				getchar();
				if (num==2)
				{
					system("clear");
					printf("Digite o código do livro novamente: ");
					fgets(tombo, 20, stdin);
				}
				else
					aux=1;
			}
	}
	}
	
	
	void altera_dado_livro(struct informacoes_livro *livro, int tam_l)
	{
		int i, tem, num, aux=0, j, k, conf;
		char tombo[20];
		system("clear");
		printf("Digite o código do livro que deseja alterar os dados: ");
		fgets(tombo, 20, stdin);
		while (aux==0)
		{
			if (tombo[0]!='\n')
			{
				if (tombo[8]=='\n')
				{
					if ((confere_tombo_char(tombo)==2) && (confere_tombo_int(tombo)==6))
					{
						i=-1;
						while (tem!=0 && i<tam_l)
						{
							i++;
							tem=strncmp(livro[i].tombo,tombo,8);
						}
						if ((livro[i].emprestimo[0]=='0') && (tem==0))
						{
							system("clear");
							printf("Qual dado deseja alterar?\n\n1.Código\n2.Título\n3.Autor\n4.Editora\n\nDigite sua opção: ");
							scanf("%d", &num);
							getchar();
							while (aux==0 && num<5)
							{
										if (num==1)
										{
											printf("Digite o novo código: ");
											fgets(livro[i].tombo, 20, stdin);
											//=====================Valida Tombo=========================
											j=0;
											conf=1;
											if (livro[i].tombo[j]=='\n')
												conf=0;
											if ((confere_tombo_char(livro[i].tombo)==2) && (confere_tombo_char(livro[i].tombo)==6))
												conf=1;
											else
												conf=0;
											k=-1;
											while (tem!=0 && k<tam_l)
											{
												k++;
												tem=strncmp(livro[k].tombo,tombo,8);
											}
											if (conf==0 || tem==0)
											{
												while (conf==0 || tem==0)
												{
													system("clear");
													printf("O código do livro foi digitado incorretamente!\n\n");
													printf("Digite o código do livro novamente: ");
													fgets(livro[tam_l].tombo, 20, stdin);
													j=0;
													conf=1;
													if (livro[i].tombo[j]=='\n')
														conf=0;
													if ((confere_tombo_char(livro[i].tombo)==2) && (confere_tombo_char(livro[i].tombo)==6))
														conf=1;
													else
														conf=0;
													k=-1;
													while (tem!=0 && k<tam_l)
													{
														k++;
														tem=strncmp(livro[k].tombo,tombo,8);
													}
												}
											}
											//===============================================
										}
										if (num==2)
										{
											printf("Digite o novo título: ");
											fgets(livro[i].titulo, 152, stdin);
											//=====================Valida Título=========================
											j=0;
											conf=1;
											if (livro[i].titulo[j]=='\n')
												conf=0;
											if (conf==0)
											{
												while (conf==0)
												{
													system("clear");
													printf("O título anterior foi digitado incorretamente!\n\n");
													printf("Digite o título novamente: ");
													fgets(livro[i].titulo, 152, stdin);
													j=0;
													conf=1;
													if (livro[i].titulo[j]=='\n')
														conf=0;
												}
											}
											//===============================================
										}
										if (num==3)
										{
											printf("Digite o novo autor: ");
											fgets(livro[i].autor, 102, stdin);
											//=====================Valida Autor=========================
											j=0;
											conf=1;
											if (livro[i].autor[j]=='\n')
												conf=0;
											if (conf==0)
											{
												while (conf==0)
												{
													system("clear");
													printf("O nome do autor foi digitado incorretamente!\n\n");
													printf("Digite o nome do autor novamente: ");
													fgets(livro[i].autor, 152, stdin);
													j=0;
													conf=1;
													if (livro[i].autor[j]=='\n')
														conf=0;
												}
											}
											//===============================================
										}
										if (num==4)
										{
											printf("Digite a nova editora: ");
											fgets(livro[i].editora, 102, stdin);
											//=====================Valida Editora=========================
											j=0;
											conf=1;
											if (livro[i].editora[j]=='\n')
												conf=0;
											if (conf==0)
											{
												while (conf==0)
												{
													system("clear");
													printf("O nome da editora foi digitado incorretamente!\n\n");
													printf("Digite o nome da editora novamente: ");
													fgets(livro[i].editora, 152, stdin);
													j=0;
													conf=1;
													if (livro[i].editora[j]=='\n')
														conf=0;
												}
											}
											//===============================================
										}
										system("clear");
										printf("Deseja alterar mais algum dado?\n\n1.Código\n2.Título\n3.Autor\n4.Editora\n5.Sair\n\nDigite sua opção: ");
										scanf("%d", &num);
										getchar();
									}
									aux=1;
								}
								else
								{
									if (tem)
									{
										system("clear");
										printf("O código do livro digitado não esta cadastrado!\n\n");
										printf("Deseja sair do modo altera dado livro?(Digite o número)  1.y | 2.n  ");
										scanf("%d", &num);
										getchar();
										if (num==2)
										{
											system("clear");
											printf("Digite o código do livro novamente: ");
											fgets(tombo, 50, stdin);
										}
										else
											aux=1;
									}
									else
									{
										system("clear");
										printf("O livro em questão esta emprestado!\n\n");
										printf("Não é permitido a alteração de dados do livro!\n\n");
										printf("Pressione enter para continuar!");
										getchar();
										aux=1;
									}
								}
							}
					else
					{
						system("clear");
						printf("O código do livro digitado é inválido!\n\n");
						printf("Digite o código do livro novamente: ");
						fgets(tombo, 20, stdin);
					}
				}
				else
				{
					system("clear");
					printf("O código do livro foi escrito incorretamente!\n\n");
					printf("Digite o código do livro novamente: ");
					fgets(tombo, 20, stdin);
				}
			}
			else
			{
				printf("Deseja sair do modo exclui cliente?  1.y | 2.n\n");
				scanf("%d", &num);
				getchar();
				if (num==2)
				{
					system("clear");
					printf("Digite o código do livro novamente: ");
					fgets(tombo, 20, stdin);
				}
				else
					aux=1;
			}
		}
	}
			
	int exclui_livro(struct informacoes_livro *livro, int tam_l)
	{
		int i, tem, cont, aux=0, num;
		char tombo[20];
		system("clear");
		printf("Digite o código do livro que deseja excluir: ");
		fgets(tombo, 20, stdin);
		cont=tam_l;
		while (aux==0)
		{
			if (tombo[0]!='\n')
			{
				if (tombo[8]=='\n')
				{
					if ((confere_tombo_char(tombo)==2) && (confere_tombo_int(tombo)==6))
					{
						i=-1;
						while (tem!=0 && i<tam_l)
						{
							i++;
							tem=strncmp(livro[i].tombo,tombo,8);
						}
						if ((livro[i].emprestimo[0]=='0') && (tem==0))
						{
							if (i!=tam_l)
							{
								tam_l--;
								strncpy(livro[i].tombo, livro[tam_l].tombo,9);
								strncpy(livro[i].titulo, livro[tam_l].titulo,152);
								strncpy(livro[i].autor, livro[tam_l].autor,102);
								strncpy(livro[i].editora, livro[tam_l].editora,102);
								strncpy(livro[i].emprestimo, livro[tam_l].emprestimo,2);
								cont=cont-1;
								aux=1;
							}
							printf("O livro foi excluido com sucesso!\n\n");
							printf("Pressione enter para voltar!");
							getchar();
						}
						else
						{
							if (tem)
							{
								system("clear");
								printf("O código do livro digitado não esta cadastrado!\n\n");
								printf("Deseja sair do modo altera dado livro?(Digite o número)  1.y | 2.n  ");
								scanf("%d", &num);
								getchar();
								if (num==2)
								{
									system("clear");
									printf("Digite o código do livro novamente: ");
									fgets(tombo, 50, stdin);
								}
								else
									aux=1;
							}
							else
							{
								system("clear");
								printf("O livro em questão esta emprestado!\n\n");
								printf("Não é permitido a alteração de dados do livro!\n\n");
								printf("Pressione enter para continuar!");
								getchar();
								aux=1;
							}
						}
					}
					else
					{
						system("clear");
						printf("O código do livro digitado é inválido!\n\n");
						printf("Digite o código do livro novamente: ");
						fgets(tombo, 20, stdin);
					}
				}
				else
				{
					system("clear");
					printf("O código do livro foi escrito incorretamente!\n\n");
					printf("Digite o código do livro novamente: ");
					fgets(tombo, 20, stdin);
				}
			}
			else
			{
				printf("Deseja sair do modo exclui cliente?  1.y | 2.n\n");
				scanf("%d", &num);
				getchar();
				if (num==2)
				{
					system("clear");
					printf("Digite o código do livro novamente: ");
					fgets(tombo, 20, stdin);
				}
				else
					aux=1;
			}
		}
		return cont;
	}

	struct informacoes_livro * livro_f(struct informacoes_livro *livro, int *tam_l)
	{
			int num;
			system("clear");
		    printf("1.Incluir Livro\n2.Busca de Livro pelo Código\n3.Alterar dados de um Livro\n4.Excluir Livro\n5.Voltar");
			printf("\n");
			printf("\n");
			printf("DIGITE SUA OPÇÃO: ");
			scanf("%d", &num);
			getchar();
			while ((num<5) || (num>5))
			{
					if (num==1) {
					incluir_livro(livro,*tam_l);
					(*tam_l)++;
					livro = (struct informacoes_livro *) realloc (livro,((*tam_l)+1)*sizeof (struct informacoes_livro));
					}
					if (num==2)
						busca_livro(livro, *tam_l);
					if (num==3)
						altera_dado_livro(livro, *tam_l);
					if (num==4) {
					exclui_livro(livro,*tam_l);
					(*tam_l)--;
					livro = (struct informacoes_livro *) realloc (livro,((*tam_l)+1)*sizeof (struct informacoes_livro));
					}
					if (num==5)
						return livro;
				system("clear");
		    	printf("1.Incluir Livro\n2.Busca de Livro pelo Código\n3.Alterar dados de um Livro\n4.Excluir Livro\n5.Voltar");
				printf("\n");
				printf("\n");
				printf("DIGITE SUA OPÇÃO: ");
				scanf("%d", &num);
				getchar();
			}
			return livro;
	}

//===============================================================Outras Operações=====================================================================================

				struct dados_emprestimo * emprestimo_f(struct dados_cliente *cliente, struct informacoes_livro *livro, struct dados_emprestimo *emprestimo, int tam_u, int tam_l, int *tam_e)
				{
					int i, j, tem=1, aux=0, conf, num, k;
					char cpf[13], status[12] = "emprestado\n\0", tombo[20];
					printf("Digite o cpf: ");
					fgets(cpf, 13, stdin);
					while (aux==0)
					{
						if (cpf[0]!='\n')
						{
							if (cpf[11]=='\n')
							{
								if (confere_cpf(cpf)==0)
								{
												i=-1;
												while (tem!=0 && i<tam_u)
												{
													i++;
													tem=strncmp(cliente[i].cpf,cpf,11);
												}
												if (tem==0)
												{
													if (cliente[i].emprestimo[0]<'2')
													{
														printf("Digite o código do livro: ");
														fgets(tombo, 10, stdin);
															//=====================Valida Tombo=========================
															j=0;
															conf=1;
															if (tombo[j]=='\n')
																conf=0;
															if ((confere_tombo_char(tombo)==2) && (confere_tombo_int(tombo)==6))
																conf=1;
															else
																conf=0;
															if (conf)
															{
																k=-1;tem=1;
																while (tem!=0 && k<tam_l)
																{
																	k++;
																	tem=strncmp(livro[k].tombo,tombo,8);
																}
															}
															if (conf)
															{
																system("clear");
																if ((livro[k].emprestimo[0]!='0') && (tem==0))
																{
																	printf("O livro já esta emprestado!\n\n");
																	printf("Pressione enter para continuar!");
																	getchar();
																	aux=1;
																}
																if (tem!=0)
																{
																	printf("O código do livro digitado não esta cadastrado!\n\n");																
																	conf=0;
																}
															}
															if ((conf==0) || (tem!=0))
															{
																while ((conf==0) || (tem!=0))
																{
																	system("clear");
																	printf("O código do livro não foi validado!\n\n");
																	printf("Digite o código do livro novamente: ");
																	fgets(livro[tam_l].tombo, 10, stdin);
																	j=0;
																	conf=1;
																	if (tombo[j]=='\n')
																		conf=0;
																	if ((confere_tombo_char(tombo)==2) && (confere_tombo_int(tombo)==6))
																		conf=1;
																	else
																		conf=0;
																	if (conf)
																	{
																		system("clear");
																		if ((livro[k].emprestimo[0]!='0') && (tem==0))
																		{
																			printf("O livro já esta emprestado!\n\n");
																			printf("Pressione enter para continuar!");
																			getchar();
																			aux=1;
																		}
																		if (tem!=0)
																		{
																			printf("O código do livro digitado não esta cadastrado!\n\n");																
																			conf=0;
																		}
																	}
																}
															}
															//===============================================
																if (aux==0)
																{
																	strncpy(emprestimo[*tam_e].tombo, tombo,10);
																	strncpy(emprestimo[*tam_e].status,status,13);
																	strncpy(emprestimo[*tam_e].cpf, cpf,13);
																	cliente[i].emprestimo[0]++;
																	livro[k].emprestimo[0]++;
																	strcpy(emprestimo[*tam_e].data_hj, __DATE__);
																	system("clear");
																	printf("O livro foi emprestado com sucesso!");
																	printf("\n\nPressione enter para voltar!");
																	getchar();
																	(*tam_e)++;
																	emprestimo=(struct dados_emprestimo *) realloc (emprestimo,((*tam_e)+1)*sizeof (struct dados_emprestimo));
																	aux=1;
																}
													}
													else
													{
														system("clear");
														printf("O cliente já possui 2 livros emprestados!\n\n");
														printf("Pressione enter para voltar!");
														getchar();
													}
											}
											else
											{
												system("clear");
												printf("O CPF digitado não encontra-se cadastrado!\n\n");
												printf("Deseja sair do modo empréstimo?(Digite o número)  1.y | 2.n  \n");
												scanf("%d", &num);
												getchar();
												if (num==2)
												{
													system("clear");
													printf("Digite o CPF novamente: ");
													fgets(cpf, 20, stdin);
												}
												else
													aux=1;
											}
									}
									else
									{
										system("clear");
										printf("O cpf foi escrito incorretamente!\n\n");
										printf("Digite o CPF novamente: ");
										fgets(cpf, 20, stdin);
									}
								}
								else
								{
									system("clear");
									printf("O cpf possui um número de dígitos superior ao permitido!\n\n");
									printf("Digite o CPF novamente: ");
									fgets(cpf, 20, stdin);
								}
						}
						else
						{
							printf("Deseja sair do modo empréstimo?  1.y | 2.n\n");
							scanf("%d", &num);
							getchar();
							if (num==2)
							{
								system("clear");
								printf("Digite o CPF novamente: ");
								fgets(cpf, 20, stdin);
							}
							else
								aux=1;
						}
					}
					return emprestimo;
				}
				
				struct dados_emprestimo * devolucao(struct dados_cliente *cliente, struct informacoes_livro *livro, struct dados_emprestimo *emprestimo, int tam_u, int tam_l, int *tam_e)
				{
					int i, k, j, tem=1, achou, possui, aux=0, num, conf, h;
					char cpf[20], tombo[20], status[12] = "restituido\n\0";
					printf("Digite o cpf: ");
					fgets(cpf, 20, stdin);
					while (aux==0)
					{
						if (cpf[0]!='\n')
							{
								if (cpf[11]=='\n')
								{
									if (confere_cpf(cpf)==0)
									{
												i=-1;
												while (tem!=0 && i<tam_u)
												{
													i++;
													tem=strncmp(cliente[i].cpf,cpf,11);
												}
												if (tem==0)
												{
														printf("Digite o código do livro: ");
														fgets(tombo, 20, stdin);
														//=====================Valida Tombo=========================
															j=0;
															conf=1;
															if (tombo[j]=='\n')
																conf=0;
															if ((confere_tombo_char(tombo)==2) && (confere_tombo_int(tombo)==6))
																conf=1;
															else
																conf=0;
															if (conf)
															{
																k=-1;
																while (tem!=0 && k<tam_l)
																{
																	k++;
																	tem=strncmp(livro[k].tombo,tombo,8);
																}
															}
															if (conf)
															{
																system("clear");
																if ((livro[k].emprestimo[0]=='0') && (tem==0))
																{
																	printf("O livro não esta emprestado!\n\n");
																	printf("Pressione enter para continuar!");
																	getchar();
																	aux=1;
																}
																if (tem!=0)
																{
																	printf("O código do livro digitado não esta cadastrado!\n\n");																
																	conf=0;
																}
															}
															if ((conf==0) || (tem!=0))
															{
																while ((conf==0) || (tem!=0))
																{
																	printf("O código do livro não foi validado!\n\n");
																	printf("Digite o código do livro novamente: ");
																	fgets(tombo, 20, stdin);
																	j=0;
																	conf=1;
																	if (tombo[j]=='\n')
																		conf=0;
																	if ((confere_tombo_char(tombo)==2) && (confere_tombo_int(tombo)==6))
																		conf=1;
																	else
																		conf=0;
																	if (conf)
																	{
																		k=-1;
																		while (tem!=0 && k<tam_l)
																		{
																			k++;
																			tem=strncmp(livro[k].tombo,tombo,8);
																		}
																	}
																	if (conf)
																	{
																		system("clear");
																		if ((livro[k].emprestimo[0]=='0') && (tem==0))
																		{
																			printf("O livro não esta emprestado!\n\n");
																			printf("Pressione enter para continuar!");
																			getchar();
																			aux=1;
																		}
																		if (tem!=0)
																		{
																			printf("O código do livro digitado não esta cadastrado!\n\n");																
																			conf=0;
																		}
																	}
																}
															}
															//===============================================
															h=0;
															while (possui!=0 && h<*tam_e)
															{
																h++;
																tem=strncmp(emprestimo[h].cpf,cpf,11);
																achou=strncmp(emprestimo[h].tombo,tombo,8);
																if (tem==0 && achou==0 && emprestimo[h].status[0]=='e')
																	possui=0;
															}
														if (possui==0)
														{
															//strncpy(emprestimo[*tam_e].tombo, tombo,10);
															strncpy(emprestimo[h].status,status,13);
															//strncpy(emprestimo[*tam_e].cpf, cpf,13);
															system("clear");
															printf("O livro foi devolvido com sucesso!\n\n");
															cliente[i].emprestimo[0]--;
															livro[k].emprestimo[0]--;
															strcpy(emprestimo[h].data_hj, __DATE__);
															printf("Pressione enter para voltar!");
															getchar();
															//(*tam_e)++;
															//emprestimo=(struct dados_emprestimo *) realloc (emprestimo,((*tam_e)+1)*sizeof (struct dados_emprestimo));
															aux=1;
														}
														else
														{
															system("clear");
															printf("O cliente não possui o livro em questão locado!\n\n");
															printf("Pressione enter para continuar!");
															getchar();
														}
													}
													else
													{
														system("clear");
														printf("O CPF digitado não encontra-se cadastrado!\n\n");
														printf("Deseja sair do modo empréstimo?(Digite o número)  1.y | 2.n  \n");
														scanf("%d", &num);
														getchar();
														if (num==2)
														{
															system("clear");
															printf("Digite o CPF novamente: ");
															fgets(cpf, 20, stdin);
														}
														else
															aux=1;
													}
												}
												else
												{
													system("clear");
													printf("O cpf foi escrito incorretamente!\n\n");
													printf("Digite o CPF novamente: ");
													fgets(cpf, 20, stdin);
												}
											}
											else
											{
												system("clear");
												printf("O cpf possui um número de dígitos superior ao permitido!\n\n");
												printf("Digite o CPF novamente: ");
												fgets(cpf, 20, stdin);
											}
									}
									else
									{
										printf("Deseja sair do modo devolução?  1.y | 2.n\n");
										scanf("%d", &num);
										getchar();
										if (num==2)
										{
											system("clear");
											printf("Digite o CPF novamente: ");
											fgets(cpf, 20, stdin);
										}
										else
											aux=1;
									}
								}
						return emprestimo;
					}
					
	struct dados_emprestimo * carrega_struct_emprestimo(struct dados_emprestimo *emprestimo, FILE *fpe, int *tam_e)
	{
		int i, j;
		char ch;
		i=0;
		j=0;
		ch = fgetc (fpe);
			//ch = fgetc (fpe);
		while (ch != EOF) 
		{

			while (ch != '\n') 
			{
				emprestimo[j].tombo[i]=ch;
				ch = fgetc (fpe);
				i++;
			}
			emprestimo[j].tombo[i]='\n';
			i=0;
			ch = fgetc (fpe);
			while (ch != '\n') 
			{
				emprestimo[j].cpf[i]=ch;
				ch = fgetc (fpe);
				i++;
			}
			emprestimo[j].cpf[i]='\n';
			i=0;
			ch = fgetc (fpe);
			while (ch != '\n') 
			{
				emprestimo[j].data_hj[i]=ch;
				ch = fgetc (fpe);
				i++;
			}
			ch = fgetc (fpe);
			i=0;
			while (ch != 'o') 
			{
				emprestimo[j].status[i]=ch;
				ch = fgetc (fpe);
				i++;
			}
			emprestimo[j].status[i]=ch;
			i++;
			emprestimo[j].status[i]='\n';
			i=0;
			j++;
			(*tam_e)++;
			emprestimo = (struct dados_emprestimo *) realloc (emprestimo,((*tam_e)+1)*sizeof(struct dados_emprestimo));
			ch = fgetc (fpe);
			ch = fgetc (fpe);
		}
		return emprestimo;
	}

	int carrega_arquivo_emprestimo(struct dados_emprestimo *emprestimo, FILE *fpe, int tam_e)
	{
		int j, k;
		j=0;
		while (j<tam_e) 
		{
				for (k=0;k<8;k++)
					fputc(emprestimo[j].tombo[k], fpe);
					fprintf(fpe, "\n");
				for (k=0;k<11;k++)
					fputc(emprestimo[j].cpf[k], fpe);
					fprintf(fpe, "\n");
				for (k=0;k<11;k++)
					fputc(emprestimo[j].data_hj[k], fpe);
				fprintf(fpe, "\n");
				for (k=0;k<10;k++)
					fputc(emprestimo[j].status[k], fpe);
					fprintf(fpe, "\n");
					
			j++;
		}
	}

//====================================================================================================================================================================
	int main()
	{
			struct dados_cliente *cliente;
			struct informacoes_livro *livro;
			struct dados_emprestimo *emprestimo;
			cliente=(struct dados_cliente *) calloc(1,sizeof(struct dados_cliente));
			livro=(struct informacoes_livro *) calloc(1,sizeof(struct informacoes_livro));
			emprestimo=(struct dados_emprestimo *) calloc(1,sizeof(struct dados_emprestimo));
			int num, tam_u=0, tam_l=0, tam_e=0;
			FILE *fpu, *fpl, *fpe;
			fpu = fopen("usuarios.txt","a+");
			cliente=carrega_struct_usuario(cliente, fpu, &tam_u);
			fclose (fpu);
			fpl = fopen("livros.txt","a+");
			livro=carrega_struct_livro(livro, fpl, &tam_l);
			fclose (fpl);
			fpe = fopen("emprestimos.txt","a+");
			emprestimo=carrega_struct_emprestimo(emprestimo, fpe, &tam_e);
			fclose (fpe);
				if (fpu==NULL || fpl==NULL || fpe==NULL)
				{
					printf("Erro ao abrir um dos arquivos!");
					return 0;
				}
		    	else
		    	{
		    		system("clear");
					printf("1.Cliente\n2.Livro\n3.Empréstimo\n4.Devolução\n5.Sair\n");
					printf("\n");
					printf("\n");
					printf("DIGITE A OPÇÃO: ");
					scanf("%d", &num);
					getchar();
					while ((num<5) || (num>5))
					{
							if (num==1)
								cliente=cliente_f(cliente, &tam_u);
							if (num==2)
								livro=livro_f(livro, &tam_l);
							if (num==3)
								emprestimo = emprestimo_f(cliente, livro, emprestimo, tam_u, tam_l, &tam_e);
							if (num==4)
								emprestimo = devolucao(cliente, livro, emprestimo, tam_u, tam_l, &tam_e);
							if (num==5)
								return 0;
						system("clear");
						printf("1.Cliente\n2.Livro\n3.Empréstimo\n4.Devolução\n5.Sair\n");
						printf("\n");
						printf("\n");
						printf("DIGITE A OPÇÃO: ");
						scanf("%d", &num);
						getchar();
					}
				}
				fpu = fopen("usuarios.txt","w");
				tam_u=carrega_arquivo_usuario(cliente, fpu, tam_u);
				fclose (fpu);
				fpl = fopen("livros.txt","w");
				tam_l=carrega_arquivo_livro(livro, fpl,tam_l);
				fclose (fpl);
				fpe = fopen("emprestimos.txt","w");
				tam_e=carrega_arquivo_emprestimo(emprestimo, fpe,tam_e);
				fclose (fpe);
			}
