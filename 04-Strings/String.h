#include<stdio.h>
#include<stdlib.h>
// Asumo que todas las cadenas que me van a pasar son finitas, el puntero no apunta a una cadena infinita


int getLength(const char * text );
int isEmpty( const char * text );
void power( const char * text, unsigned n, char destination[] );
int myStrcmp(const char* first_text,const char*second_text);
