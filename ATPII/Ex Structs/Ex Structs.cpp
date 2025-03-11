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

void Busca1Nome(TpAgenda Ag[TF],int TLA)
{
	int i, cod=1;
	char nome[25];
	clrscr();
	printf("\n### Busca pro Primeiro Nome\n");
	printf("\nDigite o nome da pessoa a ser buscada: ");
	gets(nome);
	for(i=0; i<TLA; i++)
	{
		if(strcmp(Ag[i].Nome,nome)==0)
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
			
			cod = 0;
		}	
	}
	
	if(cod!=0)
		printf("\nO nome nao foi encontrado!");
		
	getch();
}


char Menu(void)
{
	clrscr();
	printf("\n### M E N U ###\n");
	printf("\n[A] Cadastro de Pessoas");
	printf("\n[B] Relatorio de Pessoas");
	printf("\n[C] Buscar por 1 Nome");
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
		}
	} while(opcao!=27);
	return 0;	
}


