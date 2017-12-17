#include <stdio.h>
#include <stdlib.h>

char primo(int a)
{
    int i,b=0;

    for(i=1; i<=a; i++)
    {
        if((a%i)==0)
        {
            b++;
        }
    }
    if (b==2)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int numero,i;
    printf("\n\n\tIntroduzca el numero hasta donde quiera calcular sus primos:\t");
    scanf("%i",&numero);

    if (numero<0)
    {
        printf("Escriba un numero entero positivo\a");
    }
    else
    {
        for(i=1; i<=numero; i++)
        {
            if ((primo(i))==1)
            {
                printf("\nEl numero %i es primo",i);
            }
        }
    }
    return 0;
}
