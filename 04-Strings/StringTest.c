#include"string.h"
#include <assert.h>
#include <string.h>

int main(){

    
    char *text = "hi";

    assert(getLength(text) == strlen(text) );
    assert(isEmpty(text) == 0);
    assert(isEmpty("") == 1);
    char resultado[9];
    power(text, 4, resultado);
    
    printf("%s\n", resultado );
    assert( myStrcmp(resultado,"hihihihi")==1);
    assert( myStrcmp(resultado,"hihihihiasd")==0);

    return 0;
}