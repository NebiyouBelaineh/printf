#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_arg(va_list print, const char *format);
int _print_int(int num);

#endif/*MAIN_H*/
