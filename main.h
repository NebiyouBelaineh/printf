#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_arg(va_list print, const char *format);
int print_char(va_list print);
int print_string(va_list print);
int print_percent(va_list print);
int _print_int(va_list print);
int (*get_func(char))(va_list);
int print_binary(va_list print);

/**
* struct printing_func - struct data structure to store to point
* to functions to print arguments depending on the conversion specifiers
*
* @symbol: symbol of the conversion specifier
* @fun_pt: respective function to use for the conversion specifier
*/
typedef struct printing_func
{
	char symbol;

	int (*fun_pt)(va_list);
} prt_func;

#endif/*MAIN_H*/
