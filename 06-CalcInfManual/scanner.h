#include <stdbool.h>
#define MAXVAL 100

extern int flagToken;

typedef enum{
    CONSTANTE_NATURAL,
    IDENTIFICADOR,
    PARENTESIS_IZQ,
    PARENTESIS_DER,
    ADICION,
    MULTIPLICACION,
    ASIGNACION,
    EVALUACION,
    ERROR_LEXICO,
    FDT //No puedo poner "EOF"
} Token;

extern int  getNextToken(); 

Token scanner();
bool isMultiplicacion(const int );
bool isSuma(const int );
bool isEOF(const int );
bool isLBracket(const int c);
bool isRBracket(const int c);
bool isAsignacion (const int c);
bool isEvaluacion(const int c);
void cleanLexema();
void writeToken(int c);
void endToken();
void readId();
void readConst();
void errorLexico();
const char * getToken(Token token);