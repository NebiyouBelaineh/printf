#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

int _printf(consit char *format, ...);
int _putchar(char c);
int print_char(va_list print, const char *format);

#endif/*MAIN_H*/
