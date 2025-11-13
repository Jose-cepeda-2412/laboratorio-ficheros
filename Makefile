##############################################
#                                            #
#       Pontificia Universidad Javeriana     #
#       Autor: José Cepeda                   #
#       Materia: Sistemas Operativos         #
#		Fecha: 13 de noviembre				 #
#		Profesor: J.Corredor PhD			 #
#       Makefile                             #
#       Script para automatizar la           #
#       compilación y limpieza de los        #
#       programas lab01ficheros-lab03ficheros#
#											 #
##############################################


# Compilador a usar
GCC = gcc

# Lista de programas a compilar
PROGRAMAS = lab01Ficheros lab02Ficheros lab03Ficheros

#compilacion de programas uno a uno
lab01Ficheros:
	$(GCC) $@.c -o $@

lab02Ficheros:
	$(GCC) $@.c -o $@

lab03Ficheros:
	$(GCC) $@.c -o $@

#limpieza de archivos compilados
clean:
	$(RM) $(PROGRAMAS)