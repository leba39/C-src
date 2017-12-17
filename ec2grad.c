#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    float a,b,c,raiz;

    printf("\n\n\t\t****ECUACIONES DE SEGUNDO GRADO****\n\n\n\n\n");

    printf("\nIntroduzca los coeficientes de la ecuacion:\t");
    scanf("%f%f%f",&a,&b,&c);
    printf("\n\n\nLa ecuacion introducida es %.2fx^2 + %.2fx + %.2f",a,b,c);

    if (a==0)
    {
        if (b==0)
        {
            printf("\n\n\tEso no es una ecuacion");
        }
        else
        {
            printf("\n\n\tLa solucion de la ecuacion es %.2f",((-c)/b));
        }
    }
    else
    {
        if ((b*b-4*a*c)<0)
        {
            printf("\n\n\n\tLa ecuacion no tiene raices reales.");
        }
        else
        {
            raiz= sqrt(b*b-4*a*c);
            printf("\n\n\n\tLa solucion de la ecuacion de segundo grado es:\t%.2f y %.2f\n\n",(-b+raiz)/(2.*a),(-b-raiz)/(2.*a));
        }
    }

    return 0;
}
