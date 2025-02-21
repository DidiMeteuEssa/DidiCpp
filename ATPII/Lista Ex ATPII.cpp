#include <stdio.h>
#include <stdlib.h>
#include <conio2.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <windows.h>

void TabelaASCII(void);
char Menu(void);
int DecimalBinario(int decimal);
int BinarioDecimal(int binario);
void VerificaPerfeito(int numero);
int VerificaSegundos(int SF, int MF, int HF, int SI, int MI, int HI);
void DesenhaMoldura(int LF, int CF, int LI, int CI);
int Fatorial(int numero);
void sound(int frequencia);
void Piano(void);
void PianoGrafico(void);
void Resultado(int valor);
void AperteEnter(void);
int SolicitaNumero(void);
void Sound(int frequencia);

int main(void)
{
	char opcao;
	do
	{
		opcao = Menu();
		switch(opcao)
		{
			case 'A':
						TabelaASCII();
						break;
			case 'B':
						Resultado(DecimalBinario(SolicitaNumero()));
						break;
			case 'C':
						Resultado(BinarioDecimal(SolicitaNumero()));
						break;
			case 'D':
						VerificaPerfeito(SolicitaNumero());
						break;
			case 'E':
						Resultado(VerificaSegundos(SolicitaNumero(),
						SolicitaNumero(),SolicitaNumero(),SolicitaNumero(),
						SolicitaNumero(),SolicitaNumero()));
						break;
			case 'F':
						DesenhaMoldura(SolicitaNumero(),SolicitaNumero(),
						SolicitaNumero(),SolicitaNumero());	
						AperteEnter();
						break;
		    case 'G':
						Resultado(Fatorial(SolicitaNumero()));
						break;
			case 'H':
						clrscr();
						Piano();
						break;
			case 'I':
						clrscr();
						PianoGrafico();
						break;											
		}
	}while(opcao!=27);
	return 0;	
}

void TabelaASCII(void)
{
	clrscr();
	int i, cor = 5, contadorL=1, contadorC=1;
	for(i=0;i<=255;i++)
	{
		textcolor(cor);
		gotoxy(contadorC, contadorL++);
		printf("%d %c %o %x",i,i,i,i);
		
		if(contadorL==31)
		{
			contadorL=1;
			contadorC+=15;
			cor++;
		}
	}
	getch();
}

char Menu(void)
{
	clrscr();
	printf("\n### M E N U ###\n");
	printf("\n[A] Tabela ASCII");
	printf("\n[B] Decimal para Binario");
	printf("\n[C] Binario para Decimal");
	printf("\n[D] Verificar N/ Perfeito");
	printf("\n[E] Calc. Diferenca de Seg.");
	printf("\n[F] Desenhar Moldura");
	printf("\n[G] Calcular Fatorial");
	printf("\n[H] Usar Piano");
	printf("\n[I] Usar Piano c/ Grafico");
	printf("\n\n[ESC] Finalizar");
	printf("\n\nOpcao desejada: ");
	return toupper(getche());
}

int DecimalBinario(int decimal)
{	
	int binario = 0, resto = 0;
	
	for(int i=1;decimal>0;i*=10)
	{
		resto = decimal%2;
		binario += i*resto;
		decimal = decimal/2;
	}
	return binario;
}

int BinarioDecimal(int binario)
{	
	int decimal = 0;
	
	for(int i=0;binario!=0;i++)
	{
		int digito = binario%10;
		decimal += digito * pow(2,i);
		binario /= 10;
	}
	return decimal;
}

void VerificaPerfeito(int numero)
{
	clrscr();
	int divisores = 0;
	for(int i=numero-1;i!=0;i--)
	{
		if(numero%i == 0)
		{
			divisores += i;
		}
	}
	
	printf("\nResultado: ");
	if(divisores == numero)
	{
		printf("O numero %d e perfeito!",numero);
	} 
		else
			{
				printf("O numero %d nao e perfeito!",numero);
			}
	AperteEnter();
}

int VerificaSegundos(int SF, int MF, int HF, int SI, int MI, int HI)
{
	int horaInSeg=0, minInSeg=0, horaFinSeg=0, minFinSeg=0, totalIn=0, totalFin=0, diferenca=0; 
	
	horaInSeg = HI*3600;
	minInSeg = MI*60;
	
	horaFinSeg = HF*3600;
	minFinSeg = MF*60;
	
	totalIn = horaInSeg + minInSeg + SI;
	totalFin = horaFinSeg + minFinSeg + SF;
	
	diferenca = totalIn - totalFin;
	
	if(diferenca < 0)
		diferenca *= -1;
		
	return diferenca;	

}

void DesenhaMoldura(int LF, int CF, int LI, int CI)
{
	clrscr();
	int a;
	gotoxy(CI,LI);
	printf("%c",218);
	
	gotoxy(CF,LF);
	printf("%c",217);
	
	gotoxy(CI,LF);
	printf("%c",192);
	
	gotoxy(CF,LI);
	printf("%c",191);
	
	for(a=CI+1;a<CF;a++)
	{
		gotoxy(a,LI);
		printf("%c",196);
		Sleep(10);
		gotoxy(a,LF);
		printf("%c",196);
	}
	
	for(a=LI+1;a<LF;a++)
	{
		gotoxy(CI,a);
		printf("%c",179);
		Sleep(10);
		gotoxy(CF,a);
		printf("%c",179);
	}
}

int Fatorial(int numero)
{
	int fatorial = 1;
	
	while(numero>0)
	{
		fatorial *= numero;
		numero--;
	}
		
	return fatorial;	
}

void Piano(void)
{
	char tecla;
	printf(" # # # PIANO # # # \n");
	printf("\n[ESC] Finalizar\n");
	do
	{
		fflush(stdin);
		tecla = toupper(getch());
		
		switch(tecla)
		{
			case 'A':
					Sound(1300);
					break;	
			case 'S':
					Sound(1460);
					break;	
			case 'D':
					Sound(1640);
					break;	
			case 'F':
					Sound(1740);
					break;	
			case 'G':
					Sound(1960);
					break;	
			case 'H':
					Sound(2200);
					break;	
			case 'J':
					Sound(2460);
					break;									
		}
		
	} 
	while(tecla != 27);
	
}

void PianoGrafico(void)
{
	printf("\n\n[A] DO / [S] RE / [D] MI / [F] FA / [G] SOL / [H] LA / [J] SI\n\n");
	Piano();
}

void Resultado(int valor)
{
	clrscr();
	printf("Resultado: %d",valor);
	AperteEnter();
}

void AperteEnter()
{
	printf("\n\nTecle [ENTER] para continuar");
	getch();
}

int SolicitaNumero(void)
{
	clrscr();
	int numero;
	printf("Digite um numero: ");
	scanf("%d",&numero);
	return numero;
}

void Sound(int frequencia)
{
	Beep(frequencia,150);
}

