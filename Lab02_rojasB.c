/***************************************************************
*            Pontificia Universidad Javeriana                   *
*                         ---=---                               *
*                                                               *
* Autores: - Danna Gabriela Rojas Bernal                        *
* Fecha: 13 noviembre de 2025                                   *
* Docente: J. Corredor                                          *
*                                                               *
* Descripción: Este programa demuestra el uso básico de la 	*
*		lectura de ficheros y obtencion de datos de 	*
*		archivos mediante llamadas del sistema		*
* Anaalisis: Se entendio que este programa lea de teclado el nombre*
		de un directorio y muestre en pantalla el nombre *
		y el tamaño que contiene			* 
***************************************************************/
#include <stdio.h> 
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>//libreria para el directorio

//programa principal 
int main()
{
DIR *d;// declaracion de puntero directorio 
char nomdir[90], nomfich[90];
struct stat datos;//guarda informacion del carchivo 
struct dirent *direc;//lee cada entrada del directorio

printf("Introduzca el nombre de un directorio: ");
fgets(nomdir,sizeof(nomdir),stdin);
nomdir[strlen(nomdir) -1]='\0'; //eliminamos el \n del nombre dle fichero 
if((d=opendir(nomdir)) ==NULL){
printf("el directorio no exite \n");
return -1;

}

while((direc=readdir(d)) !=NULL){ // se empieza a leer el directorio
strcpy (nomfich, nomdir);
strcat(nomfich, "/");
strcat (nomfich,direc->d_name );

stat(nomfich, &datos);// Obtiene la información del archivo usando 'stat'
if (S_ISREG(datos.st_mode))
printf("Nombre; %s\t| Tamaño: %ld\n", direc->d_name, datos.st_size);
}//fin del while 

closedir(d);//cierra directorio 
}


