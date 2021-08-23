#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "parser.h"
#include "scanner.h"
#include "logger.h"
#include "tablaSimbolos.h"


int resultado=0;

// Funciones privadas
static void listaSentencias();
static void sentencia();
static int expresion();
static int termino();
static int factor();
static void programa();
static void matchAndConsume(Token t);
static void ErrorSintactico();



void parser (){
  programa();
}

static void programa(){
  listaSentencias();
  matchAndConsume(FDT);
}

static void listaSentencias(){
  sentencia();
  while (1) {
    switch (getNextToken()) {
      case IDENTIFICADOR:case EVALUACION:
        sentencia();
        break;
      default:
        return;
    }
  }
}

static void sentencia(){
  char idName[MAXVAL];
  switch (getNextToken()){
    case IDENTIFICADOR:
      matchAndConsume(IDENTIFICADOR);
      strcpy(idName,lexema);
      matchAndConsume(ASIGNACION);
      matchAndConsume(CONSTANTE_NATURAL);
      setIdValue(idName,atoi(lexema));
      return;
    case EVALUACION:
      matchAndConsume(EVALUACION);
      resultado=expresion();
      log_info("[Parser] Resultado de evaluación: %d\n", resultado);
      return;
  }
}

static int expresion(){
  int expresionValue=termino();
  if (getNextToken()==ADICION){
      matchAndConsume(ADICION);
      expresionValue=expresionValue+expresion();
    }
  return expresionValue;
}

static int termino(){
  int terminoValue =factor();
  if (getNextToken()==MULTIPLICACION){
        matchAndConsume(MULTIPLICACION);
        terminoValue=terminoValue*termino();
  }
  return terminoValue;
}

static int factor(){
  int factorValue = 0;
  switch (getNextToken()){
    case IDENTIFICADOR:  
      matchAndConsume(IDENTIFICADOR);
      return getIdValue(lexema);
    case CONSTANTE_NATURAL:
      matchAndConsume(CONSTANTE_NATURAL);
      return atoi(lexema);
    case PARENTESIS_IZQ:
      matchAndConsume(PARENTESIS_IZQ);
      factorValue=expresion();
      matchAndConsume(PARENTESIS_DER);
      return factorValue;
    default:
      ErrorSintactico();     
      return factorValue;
  }
}

static void matchAndConsume(Token t){
  if ( !(t == getNextToken())) 
    ErrorSintactico();
  flagToken = 0; 
}

static void ErrorSintactico(){
  printf("Error Sintactico\n");
  exit(0);
}