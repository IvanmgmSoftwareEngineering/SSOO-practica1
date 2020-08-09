#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libreria.h"


int main (int argc, char *argv[]){

	int lineas;
	int errHead,errTail, errLonglines;

        if(argc == 1)
        {
                lineas = 10;

        }
        else if (argc == 2)
        {
                char *num = argv[1];
                lineas = atoi(num);
        }
        else
        {
                printf("Uso: \"%s -N\" para ver las N primeras líneas, o \"%s\" para las 10 primeras líneas\n", argv[0], argv[0]);
                return 1;
        }
	printf("\n");
	printf("--Probando la funcion Head. . . \n");
	errHead = head(lineas);
	if(errHead==0){
		printf("--Hemos terminado de probar la funcion Head y todo ha ido bien \n");
		printf("\n");
	}
	else{
		return errHead;
	}

	printf("--Probando la funcion Tail. . . \n");
        errTail=tail(lineas);
	if(errTail==0){
                printf("--Hemos terminado de probar la funcion Tail y todo ha ido bien \n");
        	printf("\n");
	}
        else{
                return errTail;
        }
	
	printf("--Probando la funcion Longlines. . . \n");
        errLonglines=longlines(lineas);
	if(errLonglines==0){
                printf("--Hemos terminado de probar la funcion LongLines y todo ha ido bien \n");
        	printf("\n");
	}
        else{
                return errLonglines;
        }

	return 0;

}
