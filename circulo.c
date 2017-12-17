#include <stdio.h>
#include <stdlib.h>
#define PI 3.14

int main()
{
    float radio;
    int salir=1;

    printf("\n\n\t****AREA Y PERIMETRO DE UN CIRCULO****\n\n\n\n");

    while (salir==1)
    {

        printf("\n\t\tEscriba el radio del circulo:\t");
        scanf("%f",&radio);

        if (radio>=0.)
        {
            printf("\n\n\tEl area del circulo es:\t\t%.2f",(PI*radio*radio));
            printf("\n\n\tEl perimetro del circulo es:\t%.2f\n\n\n",(2*PI*radio));
        }
        else
        {
            printf("\n\nEl radio de un circulo no puede ser negativo\a\a\a\n\n");
        }
      printf("\nQuiere realizar otro calculo?\tSi-1\tNo-2\t");
      scanf("%i",&salir);

    }

   return 0;
}
