#include <stdio.h>
#include <stdbool.h>

//CONSTANTE: N ELEMENTOS SERIE

int N=11;   //IMPAR

void main(){


	double PI;
	double sumatorio=1;
	bool resta=true;

	for(int i=3;i<=N;i+=2)               //Va creciendo por numeros impares hasta N elementos
	{
		if (resta==true)
		{
			sumatorio-=1.0/i;
			resta=false;
		}	
		else
		{
			sumatorio+=1.0/i;
			resta=true;
		}

	}

	PI=4*sumatorio;
	printf("La aproximacion por serie de PI de %i elementos es:\t%g\n",N,PI);
	//DONE?!

}
