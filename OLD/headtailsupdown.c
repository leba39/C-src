/*
	HEAD/TAILS and HIGHER/LOWER GAME -by LEBA
*/

#include <stdio.h>
#include <stdlib.h>  	//RANDOM GENERATOR
#include <time.h>	//FUNCION TIME
//FUNCTIONS
char pMenu(void);
int playAgain(void);
void headTails(void);
void higherLower(void);

//NOTE: I can implement the playAgain code as a sub part at the end of
//      headTails and higerLower changing the type of this functions to int
//      so then I can simplify the whiles on the switch statement.?


void main()
{		
	//VARs
	char opt;
	int end=0;
	//MENU DISPLAY
	opt=pMenu();
	switch (opt)
	{
		case '1':
			while (end!=1)
			{
				headTails();
				end=playAgain();	
			}
			break;
		case '2':
			while (end!=1)
			{
				higherLower();
				end=playAgain();	
			}
			break;
		case '3':
			exit(0); //Default exit
		default:
			printf("Wrong menu option!\n");
			exit(1); //Wrong menu character.
	}
}

char pMenu()
{
	//VARs
	char resp;
	//CODE
	printf("WELCOME. Select your option:\n\n");
	printf("\t1.Head-Tails\n\t2.Higher-Lower\n\t3.Quit\n");
	resp=getchar(); 
	//reads only 1c and puts it in resp.
	//If the user enter more it only returns the first.
	return resp;

}

int playAgain()
{
	//VARs
	char fin;
	//CODE
	printf("\nDo you want to play again?:\t(Y)es-(N)o\n");
	scanf("%s",&fin);
 
	if (fin == 'Y' || fin == 'y')
	{
		return 0; 
	}
	else
	{
		return 1;
	}	

	/* NOTES:
	SCANF reads a string and puts it in char 'fin'. If the user enters more
	than one character(aka string) and error happens. 
	Can't seem to make this work using getchar() to avoid this from happening.	  
	If I make fin as an array[] so that it can properly hold the string I guess
	I could make the if condition like this (fin[0]=='y')?

	How can I make the same process using pointers?
	Pointer to a predefined empty array of chars?
		char str[10];
		char *p;
		p=str; p=&str[0]; (EQUIVALENT?)
	*/
}


void headTails()
{
	//INITIALIZE SEED. using time like this produces a warning?
	srand(time(NULL));
	//VARs
	int coin;   
	//can I make this a char? It will only have values 0-1 but
	//rand() seems to return an int in its doc.
	char user;
	int score=0;
	int i;

	//CODE
	printf("-A coin will be tossed 10 times. Guess at least half of the results to win.-\n");
	
	for(i=1;i<=10;i++)
	{
		coin=rand()%2;	//coin=0> head coin=1> tail

		printf("\n\n\tTry N%i:...\n",i);
		printf("(H)ead or (T)ail?\n");
		
		scanf("%s",&user);//scans response
 
		if ((user =='H' || user =='h') && (coin == 0))
		{
			score+=1;
			printf("\nNice! Your score is %d of %i.\n",score,i);
		}
		else if ((user =='T' || user =='t') && (coin == 1))
		{
			score+=1;
			printf("\nNice! Your score is %d of %i.\n",score,i);
		}
		else
		{
			printf("\nWrong! Your score is %d of %i.\n",score,i);	
		}		
	}
	//NOTE: Something awful happens with 'score'. It pops random ints and
	//      doesn't keep the count.

	
	if (score<5)
	{
		printf("\n\nYOU LOSE! G A M E    O V E R.\n\a");
	}
	else
	{
		printf("\n\nYOU WON! G A M E    O V E R.\n\a");
	}	
}

void higherLower()
{
	//INITIALIZE SEED. time gives warning.
	srand(time(NULL));

	//VARs
	int lives=3;
	int nums[20];
	char resp;
	int i=0;

	//CODE
	printf("-You are given three lives. Guess correctly the output of at least half of this 20 number set.-\n");

	//RANDOM ARRAY GENERATION.
	for(i=0;i<20;i++)
	{
		nums[i]=(rand()%10)+1; //1-10
	}
	
	//GAME LOOP
	i=0; //RESET as counter.
	while (lives>0 && i < 20)
	{
		printf("This number popped up!:\t%d\n",nums[i]);
		printf("\t(H)igher or (L)ower?:\n");
		scanf("%s",&resp);
		
		if((nums[i+1] > nums[i]) && (resp == 'h' || resp == 'H'))
		{
			//next number is higher and user guessed correctly.
			printf("\tNice. Keep going.\n");
		}
		else if((nums[i+1] < nums[i]) && (resp == 'l' || resp == 'L'))
		{
			//next number is lower and user guessed correctly.
			printf("\tNice. Keep going.\n");
		}
		else
		{
			//next number is whatever and user guessed incorrectly.
			lives-=1;
			printf("\tWrong! %d lives remaining!\n",lives);
		}
		i++;
		//Something goes wrong with lives. It goes random on the first fail.
		
	}
	//OUT OF MAIN LOOP: EITHER HE RAN OUT OF LIVES OR HE COMPLETED THE SET.
	//REWARD
	if (i > 10)
	{
		printf("YOU WON! Score is %d with %d lives.\n",i,lives);

	}
	else
	{	
		printf("YOU LOSE! Score is %d with %d lives.\n",i,lives);
	}
}
