#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define aceleraciong 9.81

/*  Autor:Abel Pampín Rodríguez
    Grupo: 4B
*/


double angulo(float x,float y,float vcero,char opcion)
{
    float calculo,raduno,raddos;
    calculo=(aceleraciong*x*x)/(vcero*vcero*2);

        if (opcion==1)
        {
            raduno=(x+sqrt(x*x-4*calculo*(calculo+y)))/(2*calculo);
            return raduno;
        }
        else
        {
            raddos=(x-sqrt(x*x-4*calculo*(calculo+y)))/(2*calculo);
            return raddos;
        }
}

//devuelve uno si se da en diana, 0 si no da e imprime como de cerca.
char relacionang(double angint,double anguno,double angdos,short int contador)
{//Si el valor abs.de la resta de ang. es menor que la de la otra resta entonces es el primer ang. el que esta mas cerca del introducido
    if ((fabs(angint-anguno))<(fabs(angint-angdos)))
    {   //En estas llaves trabajo con la opcion de que el ang int esta mas cerca del anguno.


        if ((fabs(angint-anguno))<0.5)
        {
            printf("\n\n\tEnhorabuena, has dado en la diana en %i intentos!!!!\n\n",contador);
            return 1;
        }
        if (((angint-anguno)<0)&&(fabs(angint-anguno)>5.))
        {//el ang int es menor q el angulo y se queda corto.
            printf("\n\n\tTe has quedado corto!!!\a");
        }
        if (((angint-anguno)<0)&&(fabs(angint-anguno)<5.))
        {//el ang int es menor q el angulo y se queda cortito.
            printf("\n\n\tTe has quedado corto por poquito!!!\a");
        }
        if (((angint-anguno)>0)&&(fabs(angint-anguno)>5.))
        {//el ang int es mayor q el angulo y se pasa de largo.
            printf("\n\n\tTe has pasado!!!\a");
        }
        if (((angint-anguno)>0)&&(fabs(angint-anguno)<5.))
        {//el ang int es mayor q el angulo y se pasa por poco.
            printf("\n\n\tTe has pasado por poquito!!!\a");
        }


    }
    else
    {   //En estas llaves trabajo con la opcion de que el ang int esta mas cerca del angdos.

        if ((fabs(angint-angdos))<0.5)
        {
            printf("\n\n\tEnhorabuena, has dado en la diana en %i intentos!!!!\n\n",contador);
            return 1;
        }
        if (((angint-angdos)<0)&&(fabs(angint-angdos)>5.))
        {//el ang int es menor q el angulo y se queda corto.
            printf("\n\n\tTe has quedado corto!!!\a");
        }
        if (((angint-angdos)<0)&&(fabs(angint-angdos)<5.))
        {//el ang int es menor q el angulo y se queda cortito.
            printf("\n\n\tTe has quedado corto por poquito!!!\a");
        }
        if (((angint-angdos)>0)&&(fabs(angint-angdos)>5.))
        {//el ang int es mayor q el angulo y se pasa de largo.
            printf("\n\n\tTe has pasado!!!\a");
        }
        if (((angint-angdos)>0)&&(fabs(angint-angdos)<5.))
        {//el ang int es mayor q el angulo y se pasa por poco.
            printf("\n\n\tTe has pasado por poquito!!!\a");
        }


    }
    return 0;
}


int main()
{
    float x,y,vcero,anguno,angdos,angint;
    char verificar=0;
    short int contador=0;

    printf("\n\t\t***TIRO PARABOLICO***\n\n");

    //Distancia eje X

    while(verificar==0)
    {
        printf("\n\n  Distancia en metros a la que se encuentra el blanco (0 - 600):\t");
        scanf("%f",&x);
        if ((x>0.)&&(x<=600.))
        {
            verificar=1;
        }
        else
        {
            printf("\n\t\t\aError en el rango, introduzca el dato de nuevo.");
        }
    }

    verificar=0;        //Para poder usar la misma variable en vez de verificary,verificarvcero...

    //Altura eje Y

    while(verificar==0)
    {
        printf("\n\n  Altura en metros a la que se encuentra el blanco (-100 - 300):\t");
        scanf("%f",&y);
        if ((y>=(-100.)&&(y<=300.)))
        {
            verificar=1;
        }
        else
        {
            printf("\n\t\t\aError en el rango, introduzca el dato de nuevo.");
        }
    }

    verificar=0;

    //Velocidad inicial

    while(verificar==0)
    {
        printf("\n\n  Velocidad inicial en m/s (70 - 100):\t");
        scanf("%f",&vcero);
        if ((vcero>=70.)&&(vcero<=100.))
        {
            verificar=1;
        }
        else
        {
            printf("\n\t\t\aError en el rango, introduzca el dato de nuevo.");
        }
    }
    verificar=0;


    printf("\n\n\n\n\n\n\n\n\n");
                                                    //a la funcion angulo mando x,y e vcero para q me devuelva la solucion positiva
                                                    //o negativa dependiendo del 1 o 0 del parametro, es decir:
                                                    // la tang del primer angulo y la tang del segundo. Despues le hago la arctg
    anguno=(atan(angulo(x,y,vcero,1))/M_PI)*180.;   //con una funcion declarada en math.h y paso el valor que viene en radianes a
    angdos=(atan(angulo(x,y,vcero,0))/M_PI)*180.;   // grados con la relacion  180º--> Pi rad.
                                                    // Asi ya tengo los dos angulos en grados en los cuales se hace diana.


    printf("%f y %f",anguno,angdos);


    do
    {
        contador++;

        while(verificar==0)
        {
            printf("\n\n\n\tIntroduzca el angulo que crea acertado:\t");
            scanf("%f",&angint);

                if ((angint<0.)||(angint>360.))  //Evito simplificacion de grados(360º+40º=400º=40ºrealmente) y elimino los negativos
                {
                    printf("\n\aAngulo invalido. Debe introducir un valor entre los 0 y 360 grados");
                }  //en realidad nunca superara los 90º ni bajara de 270º porque si no el proyectil se va hacia atras y no da diana
                else
                {
                    verificar=1;
                }

        }

        verificar=0;

    }
    while((contador<=5)&&(relacionang(angint,anguno,angdos,contador)==0));

    if (contador=5){printf("\n\n\n\t\tHa fallado todos los intentos.\n\t\t* * * *G A M E    O V E R* * * *\a\a\a\a\a\a\n\n\n\n");}

    //problema en el numero de intentos, pasar relacionang para adentro. solucionar errores en la ecuacion de segundo grado(sol imag)
    return 0;
}
