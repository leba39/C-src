#include <stdio.h>


int N=19625;
void main()
{

	int numero=19625;
	int suma=0;

	while (numero>0)
	{	
		suma+=numero%10;
		numero=numero/10;

	}
	
	printf("La suma de las cifras de %i es:\t%i\n",N,suma);

	//DONE?

}
