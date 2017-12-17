/*

SIEVE OF ERATOSTHENES - PRIME NUMBERS - by leba

*/

#include <stdio.h>
#include <stdlib.h>

int main(){

	//INPUT
	unsigned int num;
	puts("S I E V E   O F   E R A T O S T H E N E S");
	fprintf(stdout,"Find prime numbers to any given limit:\t");
	fscanf(stdin,"%d",&num);
	puts("Processing...");
	//ARRAY
	unsigned int sieve[num+1];
	int i,j;
	for (i=0; i<(num+1);i++){
		sieve[i]=i+1;		//it goes 1,2,3,4,5...
	}
	
	for (i=1;i<(num+1);i++){ 	//starts at element[1]=2
		
		if (sieve[i]!=0){	//if it isnt empty already...
			j=2;
			while (sieve[i]*j<=(num+1)){
				sieve[(sieve[i]*j-1)]=0;//remove its multipliers
				j++;	
			}
		}
	}
	//OUTPUT 
	for (j=1;j<(num+1);j++){
		if (sieve[j]!=0){
			fprintf(stdout,"Number %d is a prime number.\n",sieve[j]);
		}
	}
	exit(EXIT_SUCCESS);
}


