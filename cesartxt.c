#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

char *dirarchivo = "cifrar.txt";

void main()
{
	int contador=0;
	int fd;		
	char letra;
	int fin=1;
	
	fd=open(dirarchivo,O_CREAT); 	//dirachivo contiene la direccion de la variable?
	
	if (fd!=-1)
	{	
		while (fin>0)
		{
			fin=read(fd,&letra,1);	//leo un byte y lo guardo en la direccion del char letra
			if (fin==-1)
			{
				perror("ERROR");
				exit(1);
			}
			letra+=3;
			printf("%c",letra);	
		}		

		close(fd);
	}
}
