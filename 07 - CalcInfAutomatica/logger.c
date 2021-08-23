#include "logger.h"

int DEBUG = 0;

const char LOG_LEVEL_INFO[] = "\033[0m";

void log_info(const char *formato, ...){
    va_list arg;
    va_start(arg, formato);
    print(LOG_LEVEL_INFO, formato, arg);
    va_end(arg);
}

void print(const char level[], const char *formato, va_list args){
    printf("%s", level);
    vfprintf(stdout, formato, args);
    reiniciar();
}

void reiniciar(void){
    printf("%s", LOG_LEVEL_INFO);
}

