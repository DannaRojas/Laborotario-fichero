/***************************************************************
*            Pontificia Universidad Javeriana                   *
*                         ---=---                               *
*Autor: Danna Gabriela Rojas Bernal                             *
* Fecha: 13 noviembre de 2025                                   *
* Docente: J. Corredor                                          *
*                                                               *
* Descripción: Este programa demuestra el uso básico de la      *
***************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <dirent.h>
#include <time.h> // necesaria para time() y ctime()

//programa principal
int main()
{
    int er;
    DIR *d; // declaracion de puntero directorio
    char nomdir[100], nomfich[100], resp[30];
    struct stat atr;
    struct dirent *rd1;
    time_t fecha;

    printf("Nombre de un directorio: \n");
    fgets(nomdir, sizeof(nomdir), stdin);
    nomdir[strlen(nomdir) - 1] = '\0'; // eliminamos el \n del nombre del fichero

    if ((d = opendir(nomdir)) == NULL) {
        printf("el directorio no exite \n");
        return -1;
    } else {
        while ((rd1 = readdir(d)) != NULL) { // se empieza a leer el directorio
            strcpy(nomfich, nomdir);
            strcat(nomfich, "/");
            strcat(nomfich, rd1->d_name);
            printf("fichero :%s:\n", nomfich);
            er = stat(nomfich, &atr);
            printf("modo : %#o:\n", atr.st_mode);

            if ((atr.st_mode & 0400) != 0)
                printf("permiso R para propetario\n");
            else
                printf("no permiso R para propietario\n");

            if (S_ISDIR(atr.st_mode))
                printf("es un directorio \n");

            if (S_ISREG(atr.st_mode)) {
                fecha = time(NULL);
                // ficheros modificados en los ultimos 10 dias
                if ((fecha - 10 * 24 * 60 * 60) < atr.st_mtime) {
                    printf("FICHERO:%s: fecha acceso %s, en sgdos %ld\n",
                           rd1->d_name, ctime(&atr.st_mtime), atr.st_mtime);
                }
            }
        }
        closedir(d); // cierra directorio
    }
}
