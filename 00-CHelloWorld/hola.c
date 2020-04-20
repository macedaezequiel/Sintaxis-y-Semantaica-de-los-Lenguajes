// Autor: Ezequiel Maceda
//Fecha de última modificación: 20/04/2020
//Nombre del programa: Hola Mundo


#include <stdio.h>

int main(void)
{
   FILE* fichero;
    fichero = fopen("output.txt", "wt");
    fputs("Hola Mundo\n", fichero);
    fclose(fichero);
    printf("Proceso completado");
    
}
