#include <stdio.h>

int main(void)
{
   FILE* fichero;
    fichero = fopen("output.txt", "wt");
    fputs("Hola Mundo\n", fichero);
    fclose(fichero);
    printf("Proceso completado");
    return 0;
}