/*
	AGE CALCULATOR (IN SECONDS) by LEBA
	MESSING WITH TIME FUNCTIONS
*/
//LIBRARIES - MODULES
#include <stdio.h>
#include <time.h>

int main(){
	
	//DECLARATIONS
	time_t 	sec,min,hour,day,year,passed,sec_on_birth,sec_old,seconds;
	size_t 	bday,bmonth,byear,y,m,d,h,mm,s;
	char	format[2];
	clock_t t0,tf;
	double tt;
	struct tm birth = {0};
	
	//DEFINITIONS
	t0	= clock(); //start timing
	sec 	= time(NULL);
	min 	= (double) sec/60;
	hour 	= (double) min/60;
	day 	= (double) hour/24;
	year	= (double) day/365.25; //CALENDARIO JULIANO -CASTING DOUBLE NOT NEEDED?	

	fprintf(stdout,"Seconds since EPOCH\t:\t%li\n",sec);
	fprintf(stdout,"Minutes\t\t\t:\t%li\n",min);
	fprintf(stdout,"Hours\t\t\t:\t%li\n",hour);
	fprintf(stdout,"Days\t\t\t:\t%li\n",day);
	fprintf(stdout,"Years\t\t\t:\t%li\n",year);


	puts("When were you born? (DD-MM-YYYY)");
	fscanf(stdin,"%d%c%d%c%d",&bday,&format[0],&bmonth,&format[1],&byear);
	//DIFERENCIA ENTRE %i y %d	
	birth.tm_year	= byear-1900;
	birth.tm_mon	= bmonth;
	birth.tm_mday	= bday;
	sec_on_birth	= mktime(&birth); //EPOCH TIME GIVEN tm DATA
		
	tf	= clock(); //stop timing
	tt	= (double) (tf-t0)/CLOCKS_PER_SEC;
	passed	= time(NULL); //EQUIVALENT TO time(&passed) ?
	sec_old	= passed-sec_on_birth;	
	
	//AGE IN FORMAT YEAR-MONTHS-DAYS-HOURS-SECONDS GIVEN SECONDS OLD.
	
	seconds	= sec_old; //COPYING
	y	= seconds/(60*60*24*365.25); 	//YEARS
	seconds	= seconds%(60*60*24*365); 	//SECONDS REMAINING-START	
	m	= seconds/(60*60*24*30.5);	//MONTHS
	seconds = seconds%(60*60*24*30);	//SECONDS REMAINING-UPDATE
	d	= seconds/(60*60*24);		//DAYS
	seconds = seconds%(60*60*24);		//SECONDS REMAINING-UPDATE
	h	= seconds/(60*60);		//HOURS
	seconds	= seconds%(60*60);		//SECONDS REMAINING-UPDATE
	mm	= seconds/(60);			//MINUTES
	s	= seconds%(60);			//SECONDS REMAINING-FINAL		

	//^ THIS DOESN'T GIVE THE CORRECT OUTPUT (AGE) ALTHOUGH I THINK THE ARITHMETIC IS OKAY.
	//(APART FROM THE %OPERATORS IN WHICH I CANT PUT DOUBLES SO I CAN'T COUNT FOR LEAP YEARS.
	//I THINK sec_old IS WRONG -THAT IS- THE EPOCH TIME I GET FROM mktime BECAUSE IF IM
	//BORN IN 09-10-1993 AT THIS MOMENT IM 812466390 SECONDS OLD WHICH DIVIDED BY 60*60*365.25
	//GIVES MORE THAN 24 NO MATTER WHAT.


	fprintf(stdout,"You are %li years old.\n",(1970+year-byear));		
	fprintf(stdout,"You are %li seconds old.\n",sec_old);	
	fprintf(stdout,"You are %li seconds older since the start of this script.\n",passed-sec);
	fprintf(stdout,"You are %i years, %i months, %i days, %i hours, %i minutes and %i seconds old\n",
		y,m,d,h,mm,s);
	fprintf(stdout,"Script processing time:\t%g(s).\n",tt);

	/* 
		IF I CAN GET AN EPOCH TIME OUT OF XX-YY-ZZZZ THEN IT WOULD BE A MATTER
		OF SUSTRACTING THIS FROMT HE CURRENT ONE AND TRANSFORM THIS AGAIN INTO
		READABLE HUMAN FORMAT

		MKTIME? STRFTIME?

		I THINK IVE DONE THE MKTIME CORRECTLY. STRFTIME APPEARS TO NEED BOTH A
		STRUCT, THE OUTPUT FORMAT AND A STRING (CHAR ARRAY) TO PUT IT. IF I GOT
		THE USERS AGE IN SECONDS, CAN'T I SIMPLY OBTAIN THE AGE IN YEARS, MONTHS
		, DAYS AND SECONDS USING / AND %?

		DOES THIS WORK?

		at least it compiles ok
	*/
	
	//UPDATE: Funciona mejor con %d pero pierdo precision con los modulos
	return 0;
}

