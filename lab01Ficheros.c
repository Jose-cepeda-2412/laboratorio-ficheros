/**********************************************
 *                                            *
 *      -Pontifica Universidad Javeriana      *
 *      Autor: Jose Jesus Cepeda              *
 *      Materia: sistemas operativos          *
 *      Docente: J.Corredor PhD               *
 *      tema: sistema de ficheros             *
 *      Descripcion: Programa que abre y lee  *
 *      un fichero de texto, llamado          *
 *      readme.txt y lo muestra por pantalla. *
 *                                            *
 **********************************************/

 #include <stdio.h>//libreria estandar para el uso de file, printf, fgets...
 #include <stdlib.h>

 /**
  * funcion principal
  * argc : numero de argumentos en la linea de comandos
  * argv : vector de cadenas 
  * 
  */
 int main(int argc, char* argv[]){
    //declaracion de un apuntador para el nombre del fichero donde se va a leer
    char * nombreArchivo = "readme.txt";
    //Declaracion de un puntero de tipo File y se abre el archivo en modo lectura
    FILE *fp = fopen(nombreArchivo, "r");
    //se verifica si se abrio el archivo correctamente
    //si no se abrio correctamente se muestra el mensaje y sale del programa
    if (fp == NULL)
    {
        printf("No se puede abrir el fichero");
        return -1;
    }
    //imprimir un mensaje para la salida
    printf("\n =============================\n");
    printf("\n Lectura de fichero readme.txt");
    printf("\n =============================\n");
    //lectura de fichero, maximo 256 bytes por linea
    //lectura de linea por linea (busqueda\n)
    //se define una constante coon la longitud de la linea
    const unsigned LARGO_MAX_LINEA = 256;
    //se declara un arrglo de chars donde se guarda cada linea leida
    char buffer[LARGO_MAX_LINEA];

    //bucle de lectura
    //fgets lee una linea del fichero y la almacena en buffer
    //mientras fgets no devuelva null, significa que se ha leido correctamente la linea
    while (fgets(buffer, LARGO_MAX_LINEA, fp))
    {
        //se muestra por pantalla el contenido del archivo readme.txt
        printf("%s", buffer);
    }
    /*cerrar el fichero*/
    fclose(fp);
    //finlaizacion correcta del programa
    return 0;
    
 }