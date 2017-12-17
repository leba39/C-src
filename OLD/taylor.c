#include <stdio.h>
#include <stdlib.h>
int k;
int main()
{
    int numcorrectox=0,numcorrectok=0;
    double x;

    printf("\n\n\t***POLINOMIOS TAYLOR***\n\n");
    printf("\nIntroduzca un valor de x entre -20 y 20:\t");
    scanf("%lf",&x);

    while (numcorrectox==0)
    {
        if ((x<=20.)&&(x>=-20.))
        {
            numcorrectox=1;
        }
        else
        {
            printf("\n\n\tValor no valido.Vuelta a introducirlo:\t");
            scanf("%lf",&x);
            numcorrectox=0;
        }
    }


    printf("\nIntroduzca un valor de k entre 1 y 100:\t");
    scanf("%i",&k);

    while (numcorrectok==0)
    {
        if ((k<=100)&&(k>=1))
        {
            numcorrectok=1;
        }
        else
        {
            printf("\n\n\tValor no valido.Vuelta a introducirlo:\t");
            scanf("%i",&k);
            numcorrectok=0;
        }
    }


    printf("La aproximacion de e^(x) es igual a %lf\n\n",exponente(x));

    return 0;

}


double exponente(double a)
{
    int n;
    double numerador,denominador,suma=0;

    for(n=0;n<=k;n++)
    {
    denominador=factorial(n);
    numerador=elevado(a,n);
    suma=suma + (numerador/denominador);
    }
    return suma;
}

double factorial(int b)
{
    int i;
    double z=1;
    if ((b==0)||(b==1))
    {
        return z;
    }
    else
    {
        for(i=1;i<=b;i++)
        {
            z=z*i;
            return z;
        }
    }
}
double elevado(double a,int b)
{
    int i,z=1;

    for(i=1;i<=b;i++)
    {
        z=z*a;
    }
    return z;
}

