#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "logger.h"

const char LOG_LEVEL_INFO[] = "\033[0m";

static void reiniciar();
static void print(const char *level, const char *formato, va_list args);


void log_info(const char *formato, ...){
    va_list arg;
    va_start(arg, formato);
    print(LOG_LEVEL_INFO, formato, arg);
    va_end(arg);
}

static void print(const char level[], const char *formato, va_list args){
    printf("%s", level);
    vfprintf(stdout, formato, args);
    reiniciar();
}

static void reiniciar(){
    printf("%s", LOG_LEVEL_INFO);
}

