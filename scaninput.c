#include <stdio.h>

void main()
{
	int num1=0,num2=0;
	char operation;
	float div;
	fscanf(stdin,"%i %c %i",&num1,&operation,&num2);

	switch (operation)
	{
		case '+':
			fprintf(stdout,"%i\n",num1+num2);
			break;
		case '-':
			fprintf(stdout,"%i\n",num1-num2);
			break;
		case '*':
			fprintf(stdout,"%i\n",num1*num2);
			break;
		case '/':
			//I tried declaring div here but it showed error.
			div=num1/num2;
			fprintf(stdout,"%.2f\n",div);
			break;
		default:
			fprintf(stdout,"Invalid operator!");
			break;
	}
}
