/*
	SIMPLE NUMBER INPUT FUNCTION - WITH GETCHAR
	by leba
*/
//PREPROCESSOR
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
//FUNCTION DECLARATIONS
int read_digits(int *number);

int main(void){
	//declaration
	int num;

	printf("Digits Read:\t%d\n",read_digits(&num));
	printf("Number:\t%d\n",num);
	exit(EXIT_SUCCESS);
}

int read_digits(int *number){

	//DECLARACIONES
	int digits[SIZE]; //podria inicializarlo segun GNU con digits[SIZE]={[0 ... SIZE-1] = -1}
	int stop,last,i,multiplier,numero;
	//DEF
	stop   = 0;
	last = 0;
	numero = 0;

	for (i=0;i<SIZE;i++){
		digits[i]=-1;
	}
	
	//READING INPUT. Ex: 1234
	while (stop != 1){
		digits[last]=getchar();
		if (digits[last] == '\n' || last == SIZE){
			stop = 1;
		}else{
			last = last + 1;
		}
	}
	//CONVERTING TO NUMBER. From left to right 4*1+3*10+2*100+1*1000
	multiplier = 1;
	for (i=last-1;i>=0;i--){
		/*
		 *digits[i] hold the  ascii value of the numbers introduced by the user.
		 *for 1234 it hols 49-50-51-52.
		 *I need them to operate as the real number (symbol) they represent.
		 * why cant I cast them into their char?
		 */
		if (digits[i] < '0' || digits[i] > '9'){
			puts("Non valid user input. Digits only.");
			exit(EXIT_FAILURE);
		}else{
			char cifra =  digits[i] - '0'; //menos 48
			numero = numero + cifra*multiplier;
			multiplier = multiplier * 10;
		}
	}
	
	//END FUNCTION. UPDATES POINTER AND RETURNS DIGITS READ.
	*number=numero;
	return last; 

}
