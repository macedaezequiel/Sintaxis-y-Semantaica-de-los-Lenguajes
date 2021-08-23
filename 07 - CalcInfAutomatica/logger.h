#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
extern int DEBUG;

void log_info(const char *formato, ...);
void log_error(const char *formato, ...);
void log_debug(const char *formato, ...);
void reiniciar();
void print(const char *level, const char *formato, va_list args);

