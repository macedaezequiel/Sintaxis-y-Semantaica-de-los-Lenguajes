#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "scanner.h"

char lexema[MAXVAL];
Token actualToken;
int flagToken = 0;
static int pos=0;

int getNextToken(){
    if (!flagToken){  //Entro si es 0
        actualToken = scanner();
        flagToken = 1;
    }
    return actualToken;
}

//FUNCIONES PRIVADAS
Token scanner(){
    cleanLexema();
    int c;
    c = getchar();
    
    
    if (isEOF(c)){
        writeToken(c);
        return FDT;
    }

    else if (isalpha(c)){
        writeToken(c);
        readId();
        return IDENTIFICADOR;
    }
    
    else if (isdigit(c)){
        writeToken(c);
        readConst();
        return CONSTANTE_NATURAL;
    }

    else if (isMultiplicacion(c)){
        writeToken(c);
        endToken();
        return MULTIPLICACION;
    }
    else if (isSuma(c)){
        writeToken(c);
        endToken();
        return ADICION;
    }
    else if (isLBracket(c)){
        writeToken(c);
        endToken();
        return PARENTESIS_IZQ;
    }
    else if (isRBracket(c)){
        writeToken(c);
        endToken();
        return PARENTESIS_DER;
    }
    else if (isspace(c)){
        getNextToken();
    }
    else if (isAsignacion(c)){
        writeToken(c);
        endToken();
        return ASIGNACION;
    }
    else if (isEvaluacion(c)){
        writeToken(c);
        endToken();
        return EVALUACION;
    }
    else {   
        errorLexico();
    }
    
}

bool isMultiplicacion(const int c){
   return c=='*';
}
bool isSuma(const int c){
    return c=='+';
}
bool isEOF(const int c){
    return c==EOF;
}
bool isLBracket(const int c){
  return c == '(';
}
bool isRBracket(const int c){
  return c == ')';
}
bool isAsignacion (const int c){
  return c == '=';
}
bool isEvaluacion(const int c){
  return c == '$';
}
void readId(){
    int c;
    c = getchar();
    if (isalpha(c)){
        writeToken(c);
        readId();
    }
    else{
        endToken();
        ungetc(c, stdin);
        return;
    }    

}
void readConst(){
    int c ;
    c = getchar();
    if (isdigit(c)){
        writeToken(c);
        readConst();
    }
    else{
        endToken();
        ungetc(c, stdin);
        return;
    }
}

void cleanLexema(){
  pos=0;
  lexema[pos]='\0';

}

void writeToken(int c){
  if (pos > MAXVAL){
    printf("[Scanner] El lexema supera el máximo definido para el buffer");
    exit(0);
  }
  lexema[pos++] = c;
  return;
}

void endToken(){
  writeToken('\0');
}

const char * getToken(Token token){
    switch(token){
        case MULTIPLICACION:
            return "MULTIPLICACION";
        case ADICION:
            return "ADICION";
        case CONSTANTE_NATURAL:
            return "CONSTANTE";
        case IDENTIFICADOR:
            return "IDENTIFICADOR";
        case PARENTESIS_IZQ:
            return "LBRACKET";
        case PARENTESIS_DER:
            return "RBRACKET";
        case ERROR_LEXICO:
            return "INVALIDO";
        case EVALUACION:
            return "EVALUACION";
        case ASIGNACION:
            return "ASIGNACION";
        case FDT:
            return "EOF";
    }
    return "WRONG TOKEN";
}

void errorLexico(){
  printf("[Scanner] Error Lexico - Caracter invalido\n");
  exit(0);
}