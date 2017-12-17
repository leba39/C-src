#include <stdio.h>

const int MAX=3; //tambien podria usar define

void main()
{ 
	int i; //Para bucles for como contador.

	//E J E M P L O    B A S I C O
	int x=5;
	int *x_p;

	x_p=&x;	
	

	printf("Variable x:\t\t\t%i\n",x);
	printf("Direccion con &:\t\t%p\n",&x);
	printf("Valor en x con pointer:\t\t%i\n",*x_p);
	printf("Direccion de x con pointer:\t%p\n\n\n",x_p);
	
	/*
	Es buena practica declarar NULL a un pointer si aun no tenemos
	una direccion para asignarle.
	*/

	int *p_vacio=NULL;
	printf("La direccion de este pointer esta vacia:\t%p\n",p_vacio);
	/*
	La direccion 0 indica que este pointer no señala a ningun punto de 
	acceso en la memoria donde se pueda encontrar un valor INT pj.
	Los pointer como condicion logica por si solo indican si contienen
	o no una direccion de memoria.
	*/
	if (p_vacio)
	{
		printf("El pointer NO esta vacio.\n");
	}
	if (!p_vacio)
	{
		printf("El pointer no contiene ninguna direccion valida.\n");
	}
	
	printf("\n\n");	

	//P O I N T E R    A R I T H M E T I C: ++,--,+,-

	int var[]={1,2,3};
	int *p_var;

	p_var=var;	//AL SER ARRAY NO HACE FALTA HACER &var

	for(i=0;i<MAX;i++)
	{
		printf("Valor de var[%i] a traves de indice:\t%i\n",i,var[i]);
		printf("Valor de var[%i] a traves de pointer:\t%i\n",i,*p_var);
		printf("Direccion que contiene el pointer:\t%p\n\n\n",p_var);
		
		p_var++; //Movemos el pointer a la siguiente localizacion
			 //como el pointer es de tipo INT (32bits) se movera
			 //en incrementos de 4 bytes.
	}
	
	/*
	PUEDO HACER LO MISMO CON --:
	poniendo en el pointer la direccion del ultimo elemento del array
	p_var=&var[MAX-1] 
	y haciendo un for(int i=MAX;i>0;i--)
	*/

	// C O M P A R A C I O N   D E   P O I N T E R S: mismo ejemplo

	int cont=0;
	p_var=var;	//vuelvo asignarle el comienzo de la matriz RESETEO
	/*
	bucle mientras que la dir del pointer no coincida con la del ultimo
	elemento del array
	*/
	printf("A TRAVES DE BUCLE COMPARATIVO DE POINTERS\n");
	while (p_var <= &var[MAX-1])
	{
		printf("Valor de var[%i] a traves de pointer:\t%i\n",cont,*p_var);
		printf("Direccion que contiene el pointer:\t%p\n\n\n",p_var);
		p_var++;
		cont++;	
	}

	//A R R A Y S   D E   P O I N T E R S

	int *p_array[MAX];
	//bucle para asignar las direcciones a los pointers del array
	for(i=0;i<MAX;i++)		//reuso i
	{
		p_array[i]=&var[i];	//&var[0]=var		
	}
	printf("Usando un array de pointers, guardando en cada uno la dir de cada [i]\n");

	for(i=0;i<MAX;i++)
	{
		printf("Valor de var[%i]:\t%i\n",i,*p_array[i]);
	}
	printf("\n\n");
	
	//P O I N T E R S   A    O T R O S    P O I N T E R S

	int **x_pp;	//pointer a pointer
	x_pp=&x_p;

	printf("Variable x:\t\t\t%i\n",x);
	printf("Valor en x con pointer:\t\t%i\n",*x_p);
	printf("Valor de x con doblepointer:\t%i\n\n",**x_pp);
	printf("Direccion de x propia:\t\t\t\t%p\n",&x);
	printf("Direccion de x con pointer:\t\t\t%p\n",x_p);
	printf("Direccion propia del 1er pointer:\t\t%p\n",&x_p);
	printf("Direccion del 1er pointer a traves del 2o:\t%p\n",x_pp);
	printf("Direccion propia del 2o pointer:\t\t%p\n",&x_pp);

	/*
	No me enteré muy bien de los arrays de caracteres.
	FIN
	*/
	printf("\a\a\a");
	
}
