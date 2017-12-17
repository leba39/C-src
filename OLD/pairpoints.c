/*
	GIVEN
	struct pair{
		struct point one;
		struct point two;
	}

	struct point{
		double x;
		double y;
	}

	RETURN THE CLOSEST PAIR.

	struct pair -> closest_pair(struct point *points, int number_of_points);

*/

//PREPROCESSOR
#include <stdio.h>
#include <stdlib.h>
#include <math.h>  //link with -lm
#define TOTALPOINTS 3
//STRUCTS
struct point{
	double x;
	double y;
};
/*
struct pair{
	struct point one;
	struct point two;
}
*/
//FUNCTION DECLARATION
	//struct pair closest_pair(struct point *point1,int number_of_points);
double distance(struct point *point1,struct point *point2);
//MAIN
int main(void){

	//DECLARATION&DEFINITION
	struct point p1 = {5.0,5.0};
	struct point p2 = {1.0,1.0};
	struct point p3 = {3.0,1.0};
	struct point total[TOTALPOINTS] = {p1,p2,p3};
	
	int num_points  = TOTALPOINTS;
		//closest pair should be p2-p3

	/*
	 *WE NEED TO check the X distances given Y points.
	 *2 points -> 1 distance   checks
	 *3 points -> 3 distances  checks
	 *4 points -> 6 distances  checks
	 *5 points -> 10 distances checks
	 * ...
	 *
	 * 
	 */
	int i,j;
	double min,aux;

	min = 100;
	aux = 0;
	//LOOP OF DISTANCES
	for (i=0;i<num_points;i++){
		for (j=i;j<num_points;j++){
			//CHECK DISTANCE WITH THE NEXT ELEMENT
			aux = distance(&total[i],&total[j]);
			if (aux < min){
				//WE UPDATE THE MIN DISTANCE
				min = aux;
			}
		}
	}

	printf("Minimun distance: %g\n",min);		


	exit(EXIT_SUCCESS);
}

double distance(struct point *p1,struct point *p2){
	//distance between two points

	//DECLARATION
	double d,x1,x2,y1,y2;

	//DEF
	d  = 0;
	x1 = (p1->x);  //accesing through pointers??
	y1 = (p1->y);
	x2 = (p2->x);
	y2 = (p2->y);

	d=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));  
	//can I use pow from math?

	return d;
}













