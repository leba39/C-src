#include <stdio.h>

char TEXTOPLANO[] = "Mensaje a cifrar.\n";
int KEY = 3;


void main()
{

	//convertir variable en array?  - NOHACEFALTA

	
	int contador=0;

	while(TEXTOPLANO[contador]!='\0')
	{
		TEXTOPLANO[contador]+=KEY;
		contador++;
	}
	printf("\tMENSAJE CIFRADO:\n%s",TEXTOPLANO);
}
