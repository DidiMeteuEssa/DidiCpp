#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>

#define TF 100
#define TFE 25
#define TFC 20
#define TFN 30

struct TpEndereco
{
	char Rua[TFE], Bairro[TFE], Complemento[TFC], CEP[10], Cidade[TFC], Estado[3], Pais[TFN];
	int Num;
};

struct TpFone
{
	int DDD, Nro;
};

struct TpData
{
	int dia, mes, ano;
};

struct TpAgenda
{
	char Nome[TFN], Email[TFE], Obs[60];
	TpEndereco Endereco;
	TpFone Fone;
	TpData DataNasc;	
};

void CADAgenda(TpAgenda Ag[TF], int &TLA)
{
	char AuxNome[TFN];
	clrscr();
	printf("\n### Cadastro de Pessoas ###\n");
	printf("\nNome: "); fflush(stdin);
	gets(AuxNome);
	while(TLA<TF && strcmp(AuxNome,"\0")!=0)
	{
		strcpy(Ag[TLA].Nome, AuxNome);
		
		printf("e-mail: "); fflush(stdin);
		gets(Ag[TLA].Email);
		
		printf("\n--- Endereco Completo: \n\n");
		printf("Rua: "); fflush(stdin);
		gets(Ag[TLA].Endereco.Rua);
		
		printf("Numero: ");
		scanf("%d",&Ag[TLA].Endereco.Num);
		
		printf("Bairro: "); fflush(stdin);
		gets(Ag[TLA].Endereco.Bairro);
		
		printf("Complemento: "); fflush(stdin);
		gets(Ag[TLA].Endereco.Complemento);
		
		printf("CEP: "); fflush(stdin);
		gets(Ag[TLA].Endereco.CEP);
		
		printf("Cidade: "); fflush(stdin);
		gets(Ag[TLA].Endereco.Cidade);
		
		printf("UF: "); fflush(stdin);
		gets(Ag[TLA].Endereco.Estado);
		
		printf("Pais: "); fflush(stdin);
		gets(Ag[TLA].Endereco.Pais);
		
		printf("\n--- Telefone: \n\n");
		printf("DDD: ");
		scanf("%d",&Ag[TLA].Fone.DDD);
		
		printf("Numero: ");
		scanf("%d",&Ag[TLA].Fone.Nro);
		
		printf("\nData de Nascimento [dd mm aaaa]: ");
		scanf("%d %d %d",&Ag[TLA].DataNasc.dia, &Ag[TLA].DataNasc.mes, &Ag[TLA].DataNasc.ano);
		
		printf("Observacao: "); fflush(stdin);
		gets(Ag[TLA++].Obs);
		
		printf("\nNome: "); fflush(stdin);
		gets(AuxNome);
	}
}

void RELAgenda(TpAgenda Ag[TF], int TLA)
{
	int i;
	clrscr();
	printf("\n### Relatorio de Pessoas ###\n");
	
	if(TLA==0)
		printf("\nAgenda Vazia!\n");
	else
		{
			for(i=0; i<TLA; i++)
			{
				printf("\n==============================");
	            printf("\n#%d - Nome: %s", i + 1, Ag[i].Nome);
	            printf("\nE-mail: %s", Ag[i].Email);
	
	            printf("\n\n--- Endereco ---");
	            printf("\nRua: %s, Número: %d", Ag[i].Endereco.Rua, Ag[i].Endereco.Num);
	            printf("\nBairro: %s", Ag[i].Endereco.Bairro);
	            printf("\nComplemento: %s", Ag[i].Endereco.Complemento);
	            printf("\nCEP: %s", Ag[i].Endereco.CEP);
	            printf("\nCidade: %s - %s", Ag[i].Endereco.Cidade, Ag[i].Endereco.Estado);
	            printf("\nPaís: %s", Ag[i].Endereco.Pais);
	
	            printf("\n\n--- Telefone ---");
	            printf("\nDDD: %d  Número: %d", Ag[i].Fone.DDD, Ag[i].Fone.Nro);
	
	            printf("\n\n--- Data de Nascimento ---");
	            printf("\n%d/%d/%d", Ag[i].DataNasc.dia, Ag[i].DataNasc.mes, Ag[i].DataNasc.ano);
	
	            printf("\n\n--- Observação ---");
	            printf("\n%s", Ag[i].Obs);
	            printf("\n==============================\n");	
			}
				
		}
	getch();
}

void POSAgenda(TpAgenda Ag[TF], int pos)
{
		printf("\n==============================");
	    printf("\n#%d - Nome: %s", pos + 1, Ag[pos].Nome);
	    printf("\nE-mail: %s", Ag[pos].Email);
        printf("\n\n--- Endereco ---");
        printf("\nRua: %s, Número: %d", Ag[pos].Endereco.Rua, Ag[pos].Endereco.Num);
        printf("\nBairro: %s", Ag[pos].Endereco.Bairro);
        printf("\nComplemento: %s", Ag[pos].Endereco.Complemento);
        printf("\nCEP: %s", Ag[pos].Endereco.CEP);
        printf("\nCidade: %s - %s", Ag[pos].Endereco.Cidade, Ag[pos].Endereco.Estado);
        printf("\nPaís: %s", Ag[pos].Endereco.Pais);

        printf("\n\n--- Telefone ---");
        printf("\nDDD: %d  Número: %d", Ag[pos].Fone.DDD, Ag[pos].Fone.Nro);

        printf("\n\n--- Data de Nascimento ---");
        printf("\n%d/%d/%d", Ag[pos].DataNasc.dia, Ag[pos].DataNasc.mes, Ag[pos].DataNasc.ano);

        printf("\n\n--- Observação ---");
        printf("\n%s", Ag[pos].Obs);
        printf("\n==============================\n");		
}

int BuscarNome(TpAgenda Ag[TF], int TLA, char Pessoa[TFN])
{
	int i=0;
	while (i<TLA && stricmp(Pessoa,Ag[i].Nome)!=0)
		i++;
		
	if (i<TLA)
		return i;
	else
		return -1;
}

void Busca1Nome(TpAgenda Ag[TF],int TLA)
{
	int pos;
	char nome[25];
	clrscr();
	printf("\n### Busca por Primeiro Nome\n");
	printf("\nDigite o nome da pessoa a ser buscada: ");
	gets(nome);
	
	pos = BuscarNome(Ag, TLA, nome);
	
	if(pos==-1)
		printf("\nO nome nao foi encontrado!");
	else
		POSAgenda(Ag,pos);
	
	getch();
}

void BuscaMes(TpAgenda Ag[TF],int TLA)
{
	int mes, cod=1, i;
	clrscr();
	printf("\n### Busca por Mes de Aniversario\n");
	if(TLA==0)
		printf("\nNenhuma pessoa foi cadastrada!");
	else
		{
			printf("\nDigite o mes de aniversario: ");
			scanf("%d",&mes);
	
			if(mes>0 && mes<13)
				for(i=0; i<TLA; i++)
				{
					if(Ag[i].DataNasc.mes == mes)
					{
							POSAgenda(Ag,i);
							
							cod = 0;
					}
				}
			else
				printf("\nInsira um mes valido!");
		}
	
		if(cod==1)
			printf("\nNenhuma pessoa com esse mes de nascimento encontrado!");
			
	getch();
}

void BuscaDiaMes(TpAgenda Ag[TF],int TLA)
{
	int mes, dia, cod=1, i;
	clrscr();
	printf("\n### Busca por Mes de Aniversario\n");
	if(TLA==0)
		printf("\nNenhuma pessoa foi cadastrada!");
	else
		{
			printf("\nDigite o dia de aniversario: ");
			scanf("%d",&dia);
			
			printf("\nDigite o mes: ");
			scanf("%d",&mes);
	
			if(mes>0 && mes<13 && dia>0 && dia<32)
				for(i=0; i<TLA; i++)
				{
					if(Ag[i].DataNasc.mes == mes && Ag[i].DataNasc.dia == dia)
					{
							POSAgenda(Ag,i);
							
							cod = 0;
					}
				}
			else
				printf("\nInsira um dia/mes valido!\n");
		}
	
		if(cod==1)
			printf("\nNenhuma pessoa com essa data de nascimento encontrado!\n");
			
	getch();
}

void EXCAgenda(TpAgenda Ag[TF], int &TLA)
{
	char AuxNome[TFN];
	int pos;
	clrscr();
	printf("\n### Exclusao de Pessoas ###\n");
	printf("\nNome a Excluir: "); fflush(stdin);
	gets(AuxNome);
	while (TLA>0 && strcmp(AuxNome,"\0")!= 0)
	{
		pos = BuscarNome(Ag,TLA,AuxNome);
		if (pos == -1)
			printf("\nNome nao Cadastrado!\n");
		else
			{
				printf("\nDados Encontrados:\n");
				printf("Nome: %s\n",Ag[pos].Nome);
				printf("e-mail: %s\n",Ag[pos].Email);
				printf("Telefone: (%d)%d\n",Ag[pos].Fone.DDD,Ag[pos].Fone.Nro);
				
				printf("\nConfirma Exclusao (S/N)? ");
				if (toupper(getche()) == 'S')
				{
					for( ; pos<TLA-1; pos++)
						Ag[pos] = Ag[pos+1];
					
					TLA--;	
					printf("\nPessoa deletada!\n");
				}
			}
		printf("\nNome a Excluir: "); fflush(stdin);
		gets(AuxNome);	
	}
}

void OrdenarAgenda(TpAgenda Ag[TF], int TLA)
{
	int a, b;
	TpAgenda aux;
	for (a=0; a<TLA-1; a++)
		for (b=a+1; b<TLA; b++)
			if (stricmp(Ag[a].Nome,Ag[b].Nome)>0)
			{
				aux = Ag[a];
				Ag[a] = Ag[b];
				Ag[b] = aux;
			}
			
	printf("\nAgenda Ordenada pelo Nome!\n");
	getch();
}

char Menu(void)
{
	clrscr();
	printf("\n### M E N U ###\n");
	printf("\n[A] Cadastro de Pessoas");
	printf("\n[B] Relatorio de Pessoas");
	printf("\n[C] Buscar por 1 Nome");
	printf("\n[D] Buscar por mes");
	printf("\n[E] Buscar por die e mes");
	printf("\n\n[ESC] Finalizar");
	printf("\n\nOpcao desejada: ");
	return toupper(getche());
}

int main()
{
	TpAgenda Agenda[TF];
	int TL=0;
	char opcao;
	do
	{
		opcao = Menu();
		switch(opcao)
		{
			case 'A':
					CADAgenda(Agenda,TL);
					break;
					
			case 'B':
					RELAgenda(Agenda,TL);
					break;
					
			case 'C':
					Busca1Nome(Agenda,TL);
					break;
					
			case 'D':
					BuscaMes(Agenda,TL);
					break;
					
			case 'E':
					BuscaDiaMes(Agenda,TL);
					break;		
		}
	} while(opcao!=27);
	return 0;	
}


