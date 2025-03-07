#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>

#define TFP 10
#define TFC 30
#define TFV 50

int main(void)
{
	char Produto[TFP][25], Cliente[TFC][30], opcao, AuxProd[25], AuxClien[50], AuxClienVen[50], AuxProdVen[25];
	float Preco[TFP];
	int Estoque[TFP], Vendas[TFV][3], TLP=0, TLC=0, TLV=0, i, codClien, codProd = -1, ClienVen=-1, AuxQtdVen, ProdVen;

	
	do
	{
		clrscr();   //system("cls");
	
		textcolor(10);  //0 BLACK .. 15 WHITE
		gotoxy(33,3);
		printf("# # #  M E N U  # # #");
		textcolor(15);
		gotoxy(33,5);
		printf("[A] Cadastrar Produtos");
		gotoxy(33,6);
		printf("[B] Exibir Produtos");
		gotoxy(33,7);
		printf("[C] Cadastrar Clientes");
		gotoxy(33,8);
		printf("[D] Exibir Clientes");
		gotoxy(33,9);
		printf("[E] Realizar Vendas");
		gotoxy(33,10);
		printf("[F] Excluir Produtos");
		gotoxy(33,11);
		printf("[G] Consultar Clientes");
		gotoxy(33,12);
		printf("[H] Ordenar Clientes");
		gotoxy(33,13);
		printf("[I] Relatorio de Vendas");
		textcolor(8);
		gotoxy(33,15);
		printf("[ESC] Finalizar");
		textcolor(15);
		gotoxy(33,17);
		printf("Opcao desejada: ");
		opcao = toupper(getche());
		
		switch (opcao)
		{
			case 'A':	clrscr();
					    printf("\n*** Cadastrar Produtos ***\n");
					    printf("Descricao Produto[%d]: ",TLP);
					    fflush(stdin);
					    gets(AuxProd);
					    //while (TLP<TFP && strlen(AuxProd)>0)
					    //while (TLP<TFP && AuxProd[0]!='\0')
					    while (TLP<TFP && strcmp(AuxProd,"\0")!=0)
					    {
							strcpy(Produto[TLP],AuxProd);
							printf("Preco: R$ ");
							scanf("%f",&Preco[TLP]);
							printf("Qtde em Estoque: ");
							scanf("%d",&Estoque[TLP++]);
							
							if (TLP==TFP)
							{
								printf("\nNao ha espaco!\n");
								getch();
							}
							else
								{
									printf("\nDescricao Produto[%d]: ",TLP);
								    fflush(stdin);
								    gets(AuxProd);
								}	
					    }
						break;
						
			case 'B':	clrscr();
					    printf("\n*** Exibir Produtos ***\n");
					    if (TLP==0)
					    	printf("\nNao ha Produtos!\n");
					    else
							for(i=0; i<TLP; i++)
							{
								printf("%s \t %.2f \t %d\n",Produto[i],Preco[i],Estoque[i]);
								Sleep(100);
							}
						
						getch();
						break;
			
			case 'C':   clrscr();
					    printf("\n*** Cadastrar Clientes ***\n");
					    printf("Nome do cliente[%d]: ",TLC);
					    fflush(stdin);
					    gets(AuxClien);
					    while(TLC<TFC && strlen(AuxClien)>0)
					    {
					    	strcpy(Cliente[TLC++], AuxClien);
					    	if (TLC==TFC)
							{
								printf("\nNao ha espaco!\n");
								getch();
							}
							else
								{
									printf("\nNome do cliente[%d]: ",TLC);
								    fflush(stdin);
								    gets(AuxClien);
								}	
					    	
					    }
					    
					    
						break;
						
			case 'D':	clrscr();
						textcolor(10);
					    printf("\n*** Exibir Clientes ***\n");
					    gotoxy(33,4);
					    if(TLC==0)
					    {
					    	printf("\nNao ha clientes!\n");
					    }
					    else
					    	{
					    		for(int i=0; i<TLC; i++)
								{
									
									printf("\n%d# %s\n",i,Cliente[i]);
									Sleep(1000);
					    		}	
					    		textcolor(8);
					    		printf("\nPressione [ENTER] para continuar");	
					    	}
					    getch();
						break;
			
			case 'E':
						clrscr();			
						codClien=0;	
						printf("\n*** Realizar Vendas***\n");
						printf("\nDigite nome do cliente:%d ",TLV);
						fflush(stdin);
						gets(AuxClienVen);
						  
						for(int i=0;i<TLC;i++)
						{
							if(strcmp(Cliente[i],AuxClienVen) == 0)
							{
								codClien=1;
								ClienVen = i;
								i=TLC;
							}
							
						}
								
						if(codClien==1)
						{
							codProd=0;
							printf("\nDigite o produto: ");
							fflush(stdin);
							gets(AuxProdVen);
							
							for(int i=0;i<TLP;i++)
							{
								if(strcmp(Produto[i],AuxProdVen)==0 && strlen(AuxProdVen)!=0)
								{
									codProd=1;
									ProdVen = i;
									i=TLC;
									printf("\nDigite a quantidade: ");
									fflush(stdin);
									scanf("%d",&AuxQtdVen);
									if(AuxQtdVen <= Estoque[ProdVen] && AuxQtdVen>0)
									{
										Estoque[ProdVen]--;
										Vendas[TLV][0] = ClienVen;
										Vendas[TLV][1] = ProdVen;
										Vendas[TLV++][2] = AuxQtdVen;
									} 
										else 
											{
												printf("\nQuantidade insuficiente!\n");
											}
								}
							}
									if(codProd!=1)
									{
										printf("\nProduto nao encontrado!\n");
									}	
						}
							else
								{
									printf("\nCliente nao encontrado!\n");
								}
						textcolor(8);
						printf("\nPressione [ENTER] para continuar");				
						getch();
						break;
						
			case 'F':
						break;
			
			case 'G':
						break;
			
			case 'H':
						break;			
			
			case 'I':
						clrscr();
						printf("\n*** Relatorio de Vendas ***\n");
						if(TLV==0)
						{
							printf("Nao ha vendas");
						}
							else
								{
					    		for(int i=0; i<TLV; i++)
									{
										printf("\n%d \t%d \t %d \t %d\n",i,Vendas[i][0],Vendas[i][1],Vendas[i][2]);
										Sleep(1000);
						    		}		    			
					    		}
					    textcolor(8);
					    printf("\nPressione [ENTER] para continuar");
					    getch();
						break;			
		}
	}while(opcao != 27);  //ESC
	
	return 0;
}

