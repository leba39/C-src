/*
	HEAD/TAILS and HIGHER/LOWER GAME -by LEBA
*/

#include <stdio.h>
#include <stdlib.h>  	//RANDOM GENERATOR
#include <time.h>	//FUNCION TIME
//FUNCTIONS
void pMenu(char *opt);
int playAgain();
void headTails(void);
void higherLower(void);

//NOTE: I can implement the playAgain code as a sub part at the end of
//      headTails and higerLower changing the type of this functions to int
//      so then I can simplify the whiles on the switch statement.?


int main()
{		
	//VARs
	char opt;
	//MENU DISPLAY
	pMenu(&opt);

	switch (opt)
	{
		case '1':
			do
			{
				headTails();
			}while(playAgain());
			break;
		case '2':
			do
			{
				higherLower();
			}while(playAgain());
			break;
		case '3':
			exit(0); //Default exit
		default:
			printf("Wrong menu option!\n");
			exit(1); //Wrong menu character.
	}
}
void pMenu(char *opt)
{
	//CODE
	printf("WELCOME. Select your option:\n\n");
	printf("\t1.Head-Tails\n\t2.Higher-Lower\n\t3.Quit\n");
	*opt = getchar(); 
	/*
	 *	reads only 1c and puts it in opt.
	 *	As it is the first input read it leaves de newline char in the
	 *	buffer. That's the reason it skipped some iterations in the for
	 *	loop in headtais and higherlower functions. FIXED
	 */

}

int playAgain()  //returns 1(TRUE) if user wants to keep playing
{
	//VARs
	char fin;
	//CODE
	printf("\nDo you want to play again?:\t(Y)es-(N)o\n");
	fin = getchar();
	if (fin == '\n'){
		fin = getchar(); //cleaning buffer from newline char.
	}

	if (fin == 'Y' || fin == 'y')
	{
		return 1;
	}else{

		return 0;
	}

}


void headTails()
{
	//INITIALIZE SEED. using time like this produces a warning?
	srand(time(NULL));
	//VARs
	int coin;   
	char user;
	int score = 0;
	int i;

	//CODE
	printf("-A coin will be tossed 10 times. Guess at least half of the results to win.-\n");
	
	for(i=1;i<=10;i++)
	{
		coin=rand()%2;	//coin=0> head coin=1> tail

		printf("\n\n\tTry N%d:...\n",i);
		printf("(H)ead or (T)ail?\n");
		
		user = getchar();
		if (user == '\n'){
			user = getchar(); //cleaning buffer from newline char
		} 		

		if ((user =='H' || user =='h') && (coin == 0))
		{
			score += 1;
			printf("\nNice! Your score is %d of %d.\n",score,i);
		}
		else if ((user =='T' || user =='t') && (coin == 1))
		{
			score += 1;
			printf("\nNice! Your score is %d of %d.\n",score,i);
		}
		else
		{
			printf("\nWrong! Your score is %d of %d.\n",score,i);	
		}		
	}
	//NOTE: Something awful happens with 'score'. It pops random ints and
	//      doesn't keep the count.

	
	if (score<5)
	{
		printf("\n\nYOU LOSE! G A M E    O V E R !\n\a");
	}
	else
	{
		printf("\n\nYOU WON! C O N G R A T S !\n\a");
	}	
}

void higherLower()
{
	//INITIALIZE SEED. time gives warning.
	srand(time(NULL));

	//VARs
	int lives,score;
	int nums[20];
	char resp;
	int i;

	//CODE
	printf("-You are given three lives. Guess correctly the output of at least half of this 20 number set.-\n");

	//RANDOM ARRAY GENERATION.
	for(i=0;i<20;i++)
	{
		nums[i]=(rand()%10)+1; //1-10
	}
	
	//GAME LOOP
	i=0; 		//RESETs
	lives = 3;
	score = 0;
	while (lives>0 && i < (20-1))
	{
		printf("This number popped up!:\t%d\n",nums[i]);
		printf("\t(H)igher or (L)ower?:\n");

		resp = getchar();	
		if (resp == '\n'){
			resp = getchar(); //cleaning buffer from newlines
		}	

		if((nums[i+1] > nums[i]) && (resp == 'h' || resp == 'H'))
		{
			//next number is higher and user guessed correctly.
			score++;
			printf("\tNice. Keep going.\n");
		}
		else if((nums[i+1] < nums[i]) && (resp == 'l' || resp == 'L'))
		{
			//next number is lower and user guessed correctly.
			score++;
			printf("\tNice. Keep going.\n");
		}
		else
		{
			//next number is whatever and user guessed incorrectly.
			lives--;
			printf("\tWrong! %d lives remaining!\n",lives);
		}

		i++;
	}
	//OUT OF MAIN LOOP: EITHER HE RAN OUT OF LIVES OR HE COMPLETED THE SET.
	//REWARD
	if (score > 10)
	{
		printf("YOU WON! Score is %d out of %d with %d lives.\n"
		,score,i,lives);

	}
	else
	{	
		printf("YOU LOSE! Score is %d out of %d with %d lives.\n"
		,score,i,lives);
	}
}
