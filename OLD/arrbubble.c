/*
	EJEMPLO ARRAY 1 - ORDENAMIENTO BURBUJA
	by leba
*/

//PREPROCESADOR
#include <stdio.h>
#include <stdlib.h>
#define CELDAS 10

//MAIN

int main(void){

	//declaraciones
	int arr_char[CELDAS],cont1;
	int cont2,stop,ultimo;

	//definiciones
	ultimo = 0;
	stop   = 0;

	/*
	 *Metemos las letra introducidas en el array
	 *Paramos si hay endofline o llenamos por completo.
	 */

	while (stop != 1){
		arr_char[ultimo] = getchar();
		if (arr_char[ultimo] == '\n'){
			stop = 1;
		}else{
			ultimo = ultimo + 1;
		}
		if (ultimo == CELDAS){
			stop = 1;
		}
	//COMENTARIOS: se introducen de golpe, como si fuera una sola string.
	}
	ultimo = ultimo - 1;

	/*
	 *A continuacion el metodo bubble para ordenar los numeros.
	 */
	cont1 = 0;
	while (cont1 < ultimo){
		cont2 = cont1 + 1;
		while (cont2 <= ultimo){
			if (arr_char[cont1] > arr_char[cont2]){
				//swap-cambio
				int temp;//se declara y define dentro de este bloque
				temp = arr_char[cont1];
				arr_char[cont1] = arr_char[cont2];
				arr_char[cont2] = temp;
			}
			cont2 = cont2 + 1;
		}
		cont1 = cont1 + 1;
	}

	/*
	 *OUTPUT: printeamos el array sorteado.
	 */
	cont1=0; //recliclamos
	while (cont1 <= ultimo){ //podria hacer lo mismo con FOR
		printf("%c\t%d\n",arr_char[cont1],arr_char[cont1]);
		cont1 = cont1 + 1;
		//Probar con %d.
	}
/*
	Con %c si le meto letras me muestra letras ordenadas numericamente segun
	su valor en la tabla ASCII. si le meto numeros me muestra los numeros 
	ordenados segun su valor inherente.
	EJ:
	>132654		123456
	>fhgje		efghj

	Con %d si le meto letras me muestra el valor numerico de estas segun la
	tabla ASCII y por supuesto las ordena. Si le meto numeros me muestra el
	valor numerico de estos segun la tabla ASCII y los ordena.
	EJ:
	>132654		49 50 51 52 53 54 55
	>fhgje		101 102 103 104 106
*/
	exit(EXIT_SUCCESS);
}

