/**********************************************
 *                                            *
 *      -Pontifica Universidad Javeriana      *
 *      Autor: Jose Jesus Cepeda              *
 *      Materia: sistemas operativos          * 
 *      Docente: J.Corredor PhD               *
 *      tema: sistema de ficheros             *
 *      Descripcion:programa que lee un       *
 *      directorio ingresado por el usuario   *
 *      y muestra los nombres y tamaños       *
 *      de todos los ficheros                 *
 *                                            *
 **********************************************/

 #include <dirent.h>//libreria estandar para el manejo de directorios
 #include <sys/types.h>//libreria estandar para el manejo de de tipos de datos en los directorios
 #include <sys/stat.h>
 #include <sys/mman.h>
 #include <fcntl.h>
 #include <stdio.h>//libreria estandar para el uso de file, printf, fgets...
 #include <unistd.h>
 #include <stdlib.h>
 #include <string.h>//libreria estandar para el majeo de cadenas

/**
 * funcion princiapal
 */
 int main(){
    DIR *d;//puntero a directorio
    char nomdir[90], nomfich[90];//nomdir = nombre de direcctorio, nomfich = ruta completa del archivo
    struct stat datos;//esteuctura donde se guardara la informacion del fichero
    struct dirent *direc;//estructura de entrada de escritorio (nombre, tipo)
    //se pide al ususario el nombre del directorio
    printf("Introduzca el Nombre de un Directorio:");
    //lee la linea ingresada por el usuario, se incluye el \n
    fgets(nomdir, sizeof(nomdir), stdin);
    //se elimina el \n para no tener problemas con la ruta
    nomdir[strlen(nomdir)-1]='\0';  
    //se verifica si al abrir el dirdctorio este falla (no existe), si es asi se muestra un mensaje y se termina la ejecucion del programa
    if ((d=opendir(nomdir))==NULL){
        printf ("El directorio no existe\n");
        return -1;
    } 
    //lee las entradas del directorio una por una
    //readdir devuelve null cuando ya no hay mas archivos
    while ((direc=readdir(d)) !=NULL) {
        //copiar el nombre del directorio
        strcpy(nomfich, nomdir);
        //añadir un / para la ruta completa
        strcat(nomfich, "/");
        //añade el nombre del archivo
        strcat(nomfich, direc->d_name );
        //stat llena la estructura con los datos
        stat (nomfich, &datos);
        
        if (S_ISREG(datos.st_mode))

            //imrpime el nombre del archivo, su tamaño en bytes
            printf ("Nombre: %s\t| Tamaño: %lld\n",direc->d_name,datos.st_size);
    }/*Fin del While*/ 
    closedir(d); 
 }     
