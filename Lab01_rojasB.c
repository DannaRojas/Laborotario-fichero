/*************************************************************
*            Pontificia Universidad Javeriana                *
*                         ---=---                            *
*                                                            *
* Autores: - Danna Gabriela Rojas Bernal                     *
* Fecha: 30 Octubre de 2025                                  *
* Docente: J. Corredor                                       *
*                                                            *
* Descripción: Este programa demuestra el uso básico de      *
***************************************************************/
#include <stdio.h> 
#include <stdlib.h>

int main (int argc, char argv[]){

char *nombrefichero="readme.txt";
FILE * fp= fopen(nombrefichero,"r");

if (fp==NULL){
printf("error \n");
return 1;

}
printf("\n ================================\n");
printf("\n =LECTURA FICHERO readme.txt===========\n");
printf("\n ================================\n");


//lectura fuchero, maximo 256 bytes por linea 
//lectura de linea por  libnea (nuscar\n)

const unsigned  LARGO_MAX_LINEA = 256;
char buffer[LARGO_MAX_LINEA];

while(fgets(buffer, LARGO_MAX_LINEA,fp))
printf("%s",buffer);


//cerrar fichero 
fclose(fp);
return 0;

}
