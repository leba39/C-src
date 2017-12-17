#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numero,i,factorial;

    printf("\n\n\t\t****FACTORIAL DE UN NUMERO****\n\n\n\n");
    printf("\tIntroduzca un numero natural:\t");
    scanf("%d",&numero);
    if (numero<0)
    {
        printf("\n\n\n\t\tEl numero tiene que ser un entero positivo!\n\n\a");
    }
    else
    {
        if (numero==0)
        {
            printf("\n\n\n\t\tEl factorial de %i es:\t1\n\n", numero);
        }
        else
        {
            factorial = numero;
            for(i=1;i<numero;i++)
            {
                factorial=factorial*i;
            }

         printf("\n\n\n\tEl factorial de %d es:\t%d\n\n",numero,factorial);
        }
    }
    return 0;
}
