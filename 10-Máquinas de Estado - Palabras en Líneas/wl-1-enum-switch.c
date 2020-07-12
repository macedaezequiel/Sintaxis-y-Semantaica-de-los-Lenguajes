#include <stdio.h>

typedef enum {SAMELINE, NEWLINE, ENDOF} State;

int main()
{
    State state = ENDOF;
    char c;
    if((c = getchar()) != EOF)
        state = SAMELINE;

    while(state != ENDOF){

        switch(state) {
            case SAMELINE:
                putchar(c);
                while((c = getchar()) == ' ' || '\n' || '\t') ;
                    state=NEWLINE;    
                if (c == EOF)
                    state=ENDOF;
                break;
            case NEWLINE:
                printf("\n");
                state=SAMELINE;
                break;
            case ENDOF:
                state = ENDOF;
                break;
        }
    }

}