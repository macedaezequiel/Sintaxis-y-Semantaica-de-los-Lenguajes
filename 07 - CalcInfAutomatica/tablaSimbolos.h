#include "logger.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAXVAL 100


typedef struct {
    char variable[MAXVAL];
    int valor;
}Simbolos;

int search(char nombre[MAXVAL]);
void setIdValue(char [],int);
int getIdValue(char []);

