#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libreria.h"

int head(int N){

        int i, lineas;
        char buf[1024];
        int cuenta = 0;
	char **lineasTexto;
        
	lineas=N;
	i=0;
        lineasTexto = (char**)malloc(1024*lineas);
        while(i<lineas){
                lineasTexto[i] = (char*)malloc(1024);
                i++;
        }
        while(fgets(buf, 1024, stdin) != NULL)
        {
		if(cuenta<lineas){
			strcpy(lineasTexto[cuenta],buf);
			cuenta++;
		}
	}
	printf("------------------------------\n");
        printf("Las %i primeras lineas son: \n",lineas);
	printf("\n");
	if(cuenta<lineas){
		for (int z=0;z<cuenta;z++){
                	printf("%s",lineasTexto[z]);
       		 }
	}
	else{
		for (int z=0;z<lineas;z++){
                        printf("%s",lineasTexto[z]);
                 }
	}
	printf("\n");
	for(int z=0;z<lineas;z++){
		free(lineasTexto[z]);
	}
	rewind(stdin);
	free(lineasTexto);
        return 0;
}

int tail(int N)
{
        int lineas;
        char buf[1024];
        int cuenta = 0;
        char *linea;
        char **lineasTexto;
        int i, aux;

	i=0;
	lineas = N;
        lineasTexto = (char**)malloc(1024*lineas);
        while(i<lineas){
                lineasTexto[i] = (char*)malloc(1024);
                i++;
        }
        i = 0;

        while(fgets(buf, 1024, stdin) != NULL){
		if(i<lineas){
                	strcpy(lineasTexto[i],buf);
                	i++;
		}
                else{
                //Si ya hemos completado la estructura, entonces empezamos a meter por el final y a sacer por el principio
			for(int z=1;z<lineas;z++){
				strcpy(lineasTexto[z-1],lineasTexto[z]);
			}
			strcpy(lineasTexto[lineas-1],buf);
                }
        aux = aux +1;
        }
	printf("------------------------------\n");
        printf("Las %i ultimas lineas son: \n",lineas);
	printf("\n");
        if(aux<lineas){
                for(int z = 0; z<aux;z++){
                        printf("%s",lineasTexto[z]);
                }
        }else{
                for(int z= 0; z<lineas;z++){
                        printf("%s", lineasTexto[z]);
                }
        }
	printf("\n");
	
	for(int z=0;z<lineas;z++){
                free(lineasTexto[z]);
        }
        free(lineasTexto);	
	rewind(stdin);
        return 0;
}

int longlines(int N){
	int lineas;
        char buf[1024];
        int cuenta = 0;
        char linea[1024];
        char **lineasTexto;
        int i, aux,w,posicionLineaMenor;
	
	lineas=N;
	i=0;
        lineasTexto = (char**)malloc(1024*lineas);
        while(i<lineas){
                lineasTexto[i] = (char*)malloc(1024);
                i++;
        }
        i = 0;
        w=0;
        aux = 0;
        //se introducen las lineas por la entreda estandar.
        while( (fgets(buf, 1024, stdin) != NULL)){
                //Se guardan todas las lines independientemente del su tamaño hasta llegar al numero de lineas que queremos mostrar N
                if(w==0){
                        strcpy(lineasTexto[i],buf);
                        i++;
                        if(i>lineas-1){
                          w=1;

                        }

                }
                else{
                /* Cuando la estructura de datos esta completa
                 y se siguen introduciendo lineas por la entrada estandar
                tenemos que comprobar si la nueva linea introducida es mayor
                que la linea de menor tamaño previamente almacenada. En el caso de que la nueva linea sea menor
                se descarta y en el caso de que sea mayor se sustituya*/
                        //Buscamos la linea de menor tamaño previamente almacenada
                        posicionLineaMenor =0;
                        for(int z=0; z<lineas;z++){
                                if(strlen(lineasTexto[z])<strlen(lineasTexto[posicionLineaMenor])){
                                    posicionLineaMenor=z;
                                }
                        }
                        /*En este punto tengo localizado la posicion de la linea de menor longitud
                        y si tiene esta linea tiene una longitud menor que la nueva linea se sustituye por la nueva linea*/
                        if(strlen(lineasTexto[posicionLineaMenor])<strlen(buf)){
                                strcpy(lineasTexto[posicionLineaMenor],buf);
                        }



                }
                aux = aux +1;
        }

        //Ordenamos
                /* En este primer caso el numero de lineas introducidas por la entrada estandar es menor que el numero de lineas que queremo$
                por lo tanto mostramos el numero de lineas que se han introducido por la entrada estandar*/
        if (aux<lineas){
                for (int z= 2; z<=aux;z++){
                        for (int j=0; j<=aux-z;j++){
                                if(strlen(lineasTexto[j])<strlen(lineasTexto[j+1])){
                                        strcpy(linea,lineasTexto[j]);
                                        strcpy(lineasTexto[j],lineasTexto[j+1]);
                                        strcpy(lineasTexto[j+1],linea);
                                }
                        }
                }


        }
        /* En este segundo caso el numero de lineas introducido por la entrada estandar es mayor que el numero que queremos mostrar
        por lo que solo mostramos el numero de lineas que queremos mostrar*/
      
        /* En este segundo caso el numero de lineas introducido por la entrada estandar es mayor que el numero que queremos mostrar
        por lo que solo mostramos el numero de lineas que queremos mostrar*/
        else{

                for (int z=2;z <=lineas;z++){
                        for (int j=0; j<=lineas-z;j++){
                                if(strlen(lineasTexto[j])<strlen(lineasTexto[j+1])){
                                        strcpy(linea,lineasTexto[j]);
                                        strcpy(lineasTexto[j],lineasTexto[j+1]);
                                        strcpy(lineasTexto[j+1],linea);
                                }
                        }

                }
        }


	printf("------------------------------\n");
        printf("Las %i lineas mas largas son: \n",lineas);
	printf("\n");
        i=0;
        //Imprimimos por pantalla
        //si hay menos lineas que N muestra todas
        if (aux<lineas){
                while (i<aux){
                        printf("%s",lineasTexto[i]);
                        i++;
                }
        }
        else{
                while (i<lineas){
                        printf("%s",lineasTexto[i]);
                        i++;
                }
        }
	printf("\n");


	for(int z=0;z<lineas;z++){
                free(lineasTexto[z]);
        }
        free(lineasTexto);
	rewind(stdin);
        return 0;
}

