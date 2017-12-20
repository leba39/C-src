/*
	GIVEN
	struct point{
		double x;
		double y;
	}

	RETURN THE CLOSEST PAIR.
	struct pair{
		point p1;
		point p2;
	}

	struct pair closest_pair(struct point *points, int number_of_points);

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
struct pair{
	struct point one;
	struct point two;
};

//FUNCTION DECLARATION
struct pair closest_pair(struct point *arr_pts,int nums);
double distance(struct point *point1,struct point *point2);
void point_display(struct pair my_pair);

//MAIN
int main(void){

	//DECLARATION&DEFINITION
	struct point p1 = {5.0,5.0};		//test
	struct point p2 = {1.0,1.0};		//test
	struct point p3 = {3.0,1.0};		//test
	struct point point_arr[TOTALPOINTS] = {p1,p2,p3};
	struct pair min_pair;
		//closest pair should be the pair p2-p3

	//FUNCTION CALLING
	min_pair = closest_pair(point_arr,TOTALPOINTS); //point_arr = &point_arr[0] ???
	point_display(min_pair);

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

struct pair closest_pair(struct point *arr_pts, int nums){

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
	int p;
	int size = 0;
	double aux,min;

	//CALCULATING ARRAY SIZE
	for(i = 0;i < nums;i++){
		for(j = i+1;j < nums;j++){
			size += 1;	
		}
	}

	double distances[size];
	//LOOP OF DISTANCES
	for (i = 0;i < nums;i++){
		static int count = 0;
		
		for (j = i+1;j < nums;j++){
			distances[count] = distance(&arr_pts[i],&arr_pts[j]);
			count += 1;
		}
	}

	//WE NEED TO FIND THE MINIMUN ELEMENT IN THE ARRAY AND WHICH POINTS IT REFERS TO
	
		//MIN
	aux = distances[0];
	for(i = 0;i < size;i++){
		if (distances[i] < aux){
			aux = distances[i];	//updates auxiliar
			min = aux;		//holds record
		} 
	}
		//INDEX
	for(i = 0;i < size;i++){
		if (distances[i] == min){
			p = i+1; //size in which we stop
		}
	}

	printf("Minimun distance: %g\n",min);		

		//WHICH POINTS ARE THEY - we do the size for backwards
	int aux2 = 0;
	int index_1,index_2;

	for(i = 0;i<nums;i++){
		for(j = i+1;j<nums;j++){
			aux2 += 1;
			if (aux2 == p){
				index_1 = i;
				index_2 = j;	
			}
		}

	}
		//FINALLY
	struct pair par;    
	par.one = arr_pts[index_1];
	par.two = arr_pts[index_2];
	//how do I define  struct pair par given an array of pointers  of struct points??
	//Why is it this way?
	//I made more sense to me like par.one = *arr_pts[index_1]
	//I think of this last line as put in par.one the content of the address of 
	//arr_pts[index_1]
	
	return par;

}

void point_display(struct pair my_pair){

	double p1x,p2x,p1y,p2y;

	p1x = my_pair.one.x;
	p1y = my_pair.one.y;
	p2x = my_pair.two.x;
	p2y = my_pair.two.y;

	/*
		If  I were to do the same with pointers:

		p1x = my_pair->one->x      ??????????? 


	*/

	printf("CLOSEST PAIR IS:\n");
	printf("\t(%g,%g) & (%g,%g)\n",p1x,p1y,p2x,p2y);
}
