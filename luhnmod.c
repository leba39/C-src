#include <stdio.h>
#include <stdbool.h>

long long int NUMERO = 455673758689925;

int doblarNumero(int x);
int sumacifras(int x);

void main()
{
	long long int tarjeta=NUMERO;
	int sumatotal=0;
	int cont=true;
	int cifra;

	while (tarjeta>0)
	{
		cifra=tarjeta%10;
		if (cont==true)
		{
			sumatotal+=doblarNumero(cifra);
			cont=false;
		}
		else
		{
			sumatotal+=cifra;
			cont=true;
		}
		tarjeta=tarjeta/10;		
	}
	
	printf("El numero de tarjeta:\t%lli\n",NUMERO);
	if ((sumatotal%10)==(NUMERO%10))
	{
		printf("CHECKSUM:\t%i\t ==>\t%lli\nES CORRECTO\n",sumatotal,NUMERO%10);
	}	
	else
	{
		printf("CHECKSUM:\t%i\t =!=>\t%lli\nES INCORRECTO\n",sumatotal,NUMERO%10);
	}	
}

//DEVUELVE EL DOBLE DE UN NUMERO, SI LLEGA A LAS DECENAS LA SUMA DE SUS CIFRAS
int doblarNumero(int x)
{
	int suma=0;
	int num;
	
	num=x*2;
	if (num>9)
	{
		num=sumacifras(num); 	
	}
	
	return num;
}

//SUMA LAS CIFRAS DE UN NUMERO
int sumacifras(int x)
{
	int contador=0;

	while(x>0)
	{
		contador+=x%10;
		x=x/10;
	}

	return contador;
}
