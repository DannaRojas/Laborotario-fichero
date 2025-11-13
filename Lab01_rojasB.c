/**************************************************************
*            Pontificia Universidad Javeriana                 *
*                         ---=---                             *
*                                                             *
* Autores: - Danna Gabriela Rojas Bernal                      *
* Fecha: 30 Octubre de 2025                                   *
* Docente: J. Corredor                                        *
*                                                             *
* Descripción: Este programa demuestra la lectura de un fichero 
*              README.TXT*
*Conclusiones: En este programa se aprendio como se lee un TXT 
 el que tenia como mensaje " hola que tal materia SISTEMAS OPERATIVOS
Genial el estar con udtedes..! "

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
//bucle para leer ficheros  
while(fgets(buffer, LARGO_MAX_LINEA,fp))
printf("%s",buffer);


//cerrar fichero 
fclose(fp);
return 0;

}
