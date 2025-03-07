#include <stdio.h>
#include <conio2.h>
#include <windows.h>

#define TF 100


void LeVetor(int v[TF],int &Tam);
void MostrarVetor(int vet[TF],int Qtde);
int Achou(int Vet[TF], int Qtde, int Valor);
void Consulta(int Vet[TF], int Qtde);
void VerFrequencia(int Vet[TF], int Qtde, int &NumMais, int &QtdeVezes);
int SomaElementos(int Vet[TF], int Qtde);
char DecimalBinario(int valor);
void SolicitaNumero(char Frase[60], int &Num);
void SubtrairConjuntos(int Vet[TF],int Vetor[TF],int V[TF*2], int qtdaA, int qtdaB, int &qtdaC);
void InterseccaoConjuntos(int Vet[TF],int Vetor[TF],int V[TF*2], int qtdaA, int qtdaB, int &qtdaC);
void UniaoConjuntos(int Vet[TF],int Vetor[TF],int V[TF*2], int qtdaA, int qtdaB, int &qtdaC);
char Menu(void);
char MenuVetor(void);
void AperteEnter();

int main(void)
{				
	char opcao, opcVetor;
	int vetor[TF], TLA=0; 
	int vetorB[TF], TLB=0; 
	int vetorC[TF*2], TLC=0;
	int valor, Vezes=0, MaisAparece=0;
	do
	{
		opcao = Menu();
		switch(opcao)
		{
			case 'A':	
						clrscr();
						printf("\n### Inserir elementos no Vetor ### \n");
						opcVetor = MenuVetor();
							switch(opcVetor)
							{
								case 'A':
										LeVetor(vetor, TLA);
										break;
								case 'B':
										LeVetor(vetorB, TLB);
										break;
							}
						break;
			case 'B':		
						clrscr();
						printf("\n### Mostrar elementos no Vetor ### \n");
						opcVetor = MenuVetor();
							switch(opcVetor)
							{
								case 'A':
										MostrarVetor(vetor, TLA);
										break;
								case 'B':
										MostrarVetor(vetorB, TLB);
										break;
							}
								
						break;
			case 'C':	
						clrscr();
						
						/*
						if(TL==0)
							printf("\nO vetor nao possui elementos!");
						else
							{
								VerFrequencia(vetor,TL,MaisAparece,Vezes);
								printf("\nValor de maior frequencia: %d e aparece %d vezes!",MaisAparece, Vezes)
							}
						*/	
							
						
						break;
			case 'D':		
						printf("Soma dos elementos do vetor: [%d]",SomaElementos(vetor, TLA));
						getch();
						break;
			case 'E':
						Consulta(vetor, TLA);
						break;
			case 'F':
						clrscr();
					
						break;
			case 'G':
						SubtrairConjuntos(vetor, vetorB, vetorC, TLA, TLB, TLC);
						break;
			case 'H':
						InterseccaoConjuntos(vetor, vetorB, vetorC, TLA, TLB, TLC);
						break;
			case 'J':
						UniaoConjuntos(vetor, vetorB, vetorC, TLA, TLB, TLC);
						break;
		}
	}
	while(opcao!=27);
	return 0;	

}

void LeVetor(int v[TF],int &Tam)
{
	clrscr();
	printf("\n### Inserir elementos no Vetor ### \n");
	int aux;
	if(Tam<TF)
	{
		printf("\nVetor[%d]: ",Tam);
		scanf("%d",&aux);
		while(Tam<TF && aux>0)
		{
			v[Tam++] = aux;
			if(Tam<TF)
			{
				printf("\nVetor[%d]: ",Tam);
				scanf("%d",&aux);
			}
			else
				{
					printf("\nO Vetor esta cheio!");
					Sleep(2000);	
				}	
		}
	}
	else
		{
			printf("\nO Vetor esta cheio!");
			Sleep(2000);
		}
}

void MostrarVetor(int vet[TF],int Qtde)
{
	clrscr();
	printf("\n### Mostrar elementos no Vetor ### \n");
	int i;
		if(Qtde==0)
	{
		printf("\nO Vetor esta vazio!");
		Sleep(2000);
	} 
	else
		{
			for(i=0; i<Qtde; i++)
				printf("\nVetor[%d]: %d\n",i ,vet[i]);
			AperteEnter();
		}
	
	
}

int Achou(int Vet[TF], int Qtde, int Valor)
{
	int i=0;
	while(i<Qtde && Valor!=Vet[i])
		i++;
		
	if(i<Qtde)	
		return 1;
	else
		return 0;				
}

void Consulta(int Vet[TF], int Qtde)
{
	clrscr();
	int Elemento;
	printf("\n### Consultar Elementos do Vetor ###\n");
	if(Qtde==0)
	{
		printf("\nO Vetor esta vazio!");
		Sleep(2000);
	} 
	else
		{
			printf("\nElemento a ser consultado: ");
			scanf("%d",&Elemento);
			while(Elemento>0)
			{
				if(Achou(Vet,Qtde,Elemento)==1)
					printf("\nElemento [%d] encontrado no vetor!\n",Elemento);
				else
					printf("\nElemento [%d] nao encontrado no vetor!\n",Elemento);
					
				Sleep(2000);
				printf("\nElemento a ser consultado: ");
				scanf("%d",&Elemento);
			}
		}
}

/* void VerFrequencia(int Vet[TFA], int Qtde, int &NumMais, int &QtdeVezes)
{
	int i, aux, frequencia;
	for(i=0;i<Qtde;i++)
	aux=Vet[i+1];
	{
		if(Vet[i]==aux)
			frequencia++;
	}
}
*/
int SomaElementos(int Vet[TF], int Qtde)
{
	clrscr();
	int i, soma=0;
	for(i=0; i<Qtde; i++)
	{
		soma += Vet[i];	
	}
	return soma;
}

void SolicitaNumero(char Frase[60], int &Num)
{
	clrscr();
	printf("\n%s",Frase);
	scanf("%d",&Num);
}

char DecimalBinario(int valor)
{
	char binario[32];
	int i, resto=0;
	for(i=0;valor>0;valor/=2)
	{
		resto = valor%2;

	}
	return binario[32];
}

void SubtrairConjuntos(int Vet[TF],int Vetor[TF],int V[TF*2], int qtdaA, int qtdaB, int &qtdaC)
{
	if(qtdaA==0 || qtdaB==0)
		printf("\nUm ou mais vetores estao vazios!");
	else
		{
			int i;
			qtdaC=0;
			for(i=0; i<qtdaA; i++)
				if(!Achou(Vetor,qtdaB,Vet[i]))
					if(!Achou(V,qtdaC,Vet[i]))
						V[qtdaC++] = Vet[i];
			
			MostrarVetor(V,qtdaC);	
		}
}

void InterseccaoConjuntos(int Vet[TF],int Vetor[TF],int V[TF*2], int qtdaA, int qtdaB, int &qtdaC)
{
	if(qtdaA==0 || qtdaB==0)
		printf("\nUm ou mais vetores estao vazios!");
	else
		{
			int i;
			qtdaC=0;
			for(i=0; i<qtdaA; i++)
				if(Achou(Vetor,qtdaB,Vet[i]))
					if(!Achou(V,qtdaC,Vet[i]))
						V[qtdaC++] = Vet[i];
			
			MostrarVetor(V,qtdaC);	
		}
}

void UniaoConjuntos(int Vet[TF],int Vetor[TF],int V[TF*2], int qtdaA, int qtdaB, int &qtdaC)
{
	if(qtdaA==0 || qtdaB==0)
		printf("\nUm ou mais vetores estao vazios!");
	else
		{
			int i;
			qtdaC=0;
			for(i=0; i<qtdaA; i++)
				if(!Achou(V,qtdaC,Vet[i]))
					V[qtdaC++] = Vet[i];
					
			for(i=0; i<qtdaB; i++)
				if(!Achou(V,qtdaC,Vetor[i]))
					V[qtdaC++] = Vetor[i];
					
			MostrarVetor(V,qtdaC);	
		}
}

char Menu(void)
{
	clrscr();
	printf("\n### M E N U ###\n");
	printf("\n[A] Le Vetor");
	printf("\n[B] Mostra Vetor");
	printf("\n[C] Ver Frequencia");
	printf("\n[D] Somar Elementos");
	printf("\n[E] Buscar no Vetor");
	printf("\n[G] Subtracao de Conjuntos");
	printf("\n[H] Interseccao de Conjuntos");
	printf("\n[J] Uniao de Conjuntos");
	printf("\n\n[ESC] Finalizar");
	printf("\n\nOpcao desejada: ");
	return toupper(getche());
}

char MenuVetor(void)
{
	printf("\n[A] Ler Vetor A");
	printf("\n[B] Ler Vetor B");
	printf("\n\n[ESC] Finalizar");
	printf("\n\nOpcao desejada: ");
	return toupper(getche());
}

void AperteEnter()
{
	printf("\n\nTecle [ENTER] para continuar");
	getch();
}
