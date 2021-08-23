%{
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "parser.h"
#include "scanner.h"
#include "logger.h"
#include "tablaSimbolos.h"


void yyerror(char const *s){printf ("Error en el Parser: %s\n", s);} 
static int yylex();


%}

%union { 
  int intVal;
  char strVal[100];
}

// 
%token <strVal> MULTIPLICACION ADICION IDENTIFICADOR PARENTESIS_IZQ PARENTESIS_DER ASIGNACION ERROR_LEXICO EVALUACION FDT 0 // es necesario darle el valor cero para indicar que es el token de EOF
%token <intVal> CONSTANTE_NATURAL

%type <intVal> factor termino expresion sentencia listaSentencias programa

%%

programa: listaSentencias FDT;

listaSentencias: sentencia 
  | listaSentencias sentencia;

sentencia: IDENTIFICADOR ASIGNACION CONSTANTE_NATURAL {setIdValue($1,$3); }
  | EVALUACION expresion {log_info("El resultado es: %d\n", $2);};

expresion: termino {$$=$1;}
 | expresion ADICION termino {$$=$1+$3;}
 ;

termino: factor {$$=$1;}
 | factor MULTIPLICACION termino {$$=$1*$3;}
 ;

factor: IDENTIFICADOR {$$=getIdValue($1);}
 | CONSTANTE_NATURAL {$$=$1;}
 | PARENTESIS_IZQ expresion PARENTESIS_DER {$$=$2;}
;


%%


static int yylex(){   
    return GetNextToken();
}

void parser(){
  switch(yyparse()){
    case 0:
      return;
    case 1:
     printf("Error Sintactico \n");
     return;
    default:
      printf("Otro Error\n");
      return;
  }
}


