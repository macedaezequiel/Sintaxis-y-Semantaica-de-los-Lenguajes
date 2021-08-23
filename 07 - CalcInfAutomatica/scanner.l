
%{
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"
%}

%option noyywrap

%%

[0-9]+    {yylval.intVal=atoi(yytext);return CONSTANTE_NATURAL;}
\(        return PARENTESIS_IZQ;
\)        return PARENTESIS_DER;
\*        return MULTIPLICACION;
\+        return ADICION;
\$        return EVALUACION;
\=        return ASIGNACION;
[a-zA-Z]*      {strcpy(yylval.strVal, yytext);return IDENTIFICADOR;}
<<EOF>>   return FDT;
[ ]+ ;
.         {
            errorLexico();
            return ERROR_LEXICO;
          }


%%


int GetNextToken(){
  return yylex();
}

void errorLexico(){
  printf("[Scanner] Error Lexico - Caracter invalido\n");
  exit(0);
}