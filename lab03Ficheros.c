/***************************************************
 *                                                 *
 *      -Pontifica Universidad Javeriana           *
 *      Autor: Jose Jesus Cepeda                   *
 *      Materia: sistemas operativos               *   
 *      Docente: J.Corredor PhD                    *
 *      tema: sistema de ficheros                  *
 *      Descripcion:Recorre un directorio dado     *
 *      por el usuario, obtiene los atributoa      *
 *      de cada entrada y muestra permisos, tipo   *
 *      y fecha de modificacion                    *
 *                                                 *
 ***************************************************/

#include <stdio.h>//libreria estandar para el uso de file, printf, fgets...
#include <string.h>//libreria estandar para el majeo de cadenas
#include <time.h>//libreria estandar para ek uso de time_t, time, ctime
#include <dirent.h>//libreria estanadar para el uyso de DIR, closedir.
#include <fcntl.h>
#include <unistd.h>//libreria estandar para el uso de stat()
#include <sys/stat.h>
#include <sys/types.h>

/**
 * funcion principal
 */
int main(){
    int er;//guarda el codifo de retorno de stat
    //nomdir = cadena para alamacenar el nombre del directorio
    //nomfich = cadena para alamacenar la ruta completa del fichero
    char nomdir[100], nomfich[100], resp[30]; 
    //estructura donde se guardan los atributos del fichero
    struct stat atr;
    //puntero a directorio
    DIR *d;
    //nombre de cada archivo
    struct dirent *rd1;
    //variable para manejar el tiempo
    time_t fecha;
    //solicita al usuario el nombre del directorio
    printf ("Nombre directorio\n");
    //lee el stdin (teclado), una linea como nombre del directorio
    fgets (nomdir, sizeof (nomdir), stdin);
    /* se debe quitar el \n del nombre del directorio*/
    nomdir[strlen(nomdir) -1]='\0';
    //guarda la fecha en el timepo actual,
    fecha=time(&fecha);
    //intenta abrir el directorio con nombre nomdir
    if ((d=opendir(nomdir))==NULL) {
        //si no existe el directorio se muestra el mensaje y finaliza el programa
        printf ("No existe ese directorio \n");
        return -1;
    }else{
        //si el directorio se abrio correctamente, leera hasta que termine, devuelve null
        while (( rd1 =readdir(d)) != NULL){
            //compara que la entrada no sea . ni ..
            //ya que son entradas "especiales", directorio actual y anterior
                if((strcmp(rd1->d_name,".") != 0) &&(strcmp(rd1->d_name, "..") != 0)){
                    //construir la ruta completa
                        strcpy (nomfich, nomdir);//copiar el nombre del directorio
                        strcat (nomfich, "/");//se añade / para separar el directorio
                        strcat (nomfich, rd1->d_name);//añadir el nombre actual del fichero
                        printf ("fichero :%s:", nomfich);//mostrar la ruta completa ddel fichero
                        er=stat (nomfich, &atr);
                        printf ("modo :%#o:", atr.st_mode);//imoprimir permisos mas tipo
                
                }else if((atr.st_mode & 0400) != 0){
                    //si la entrada era . o .. 
                        printf (" permiso R para propietario\n");
                }else{
                    //si no tiene permisos de lectura el propietario
                 printf (" No permiso R para propietario\n");
                 //comprueba si la entrada es unn fichero
                }if (S_ISDIR(atr.st_mode)) printf (" Es un directorio \n");
                if (S_ISREG(atr.st_mode)){
                    //imprime nombre, fheca de ultima actualizacion y la fehca en segundos
                printf("FICHERO:%s: fecha acceso %s, en sgdos %ld\n",
                               rd1->d_name,          
                               ctime(&atr.st_mtime), 
                               (long)atr.st_mtime);  
                }
        } /*cierre while*/
    }   //cerra el archivo
        closedir (d);
        return 0;
  }
/**
 * conclusion:
 * el programa recorre un directorio que lo da el usuario y muestra
 * cada entrada, sus permisos tipo y fehcas de modificacion, en lenguaje c
 */