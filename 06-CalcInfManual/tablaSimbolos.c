#include "tablaSimbolos.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

Simbolos TablaSimbolos[MAXVAL];
int id_TablaSimbolos=0;


void setIdValue(char nombre[MAXVAL],int valor){
  int pos = search( nombre);
  if (pos == -1){
    strcpy(TablaSimbolos[id_TablaSimbolos].variable,nombre);
    TablaSimbolos[id_TablaSimbolos].valor=valor;
    id_TablaSimbolos++;
  }
  else{
    TablaSimbolos[pos].valor=valor;
  }
}


int getIdValue(char nombre[MAXVAL]){
  int pos = search( nombre);
  if (pos == -1){
    printf("[tablaSimbolos] identificador no declarado: %s\n", nombre);
    exit(0);
  }
  return TablaSimbolos[pos].valor;
}

int search(char nombre[MAXVAL]){
    for (int i = 0; i < id_TablaSimbolos; i++)
        if (strcmp(TablaSimbolos[i].variable, nombre) == 0)
            return i;
    return -1;
}