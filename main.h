#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>


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
	int (*fun_pt)();
} prt_func;

int _printf(const char *format, ...);
int _putchar(char c);
int print_arg(const char *format, va_list print, char buffer[],
		  int *buf_lenptr, int *buf_posptr, prt_func func_print[]);
int print_char(va_list print, char buffer[], int *buf_lenptr, int *buf_posptr);
int print_string(va_list print, char buffer[], int *buf_lenptr,
	int *buf_posptr);
int print_percent(va_list print);
int _print_int(va_list print, char buffer[], int *buf_lenptr, int *buf_posptr);
int get_func(char format, prt_func func_print[], char buffer[],
		     int *buf_lenptr, int *buf_posptr, va_list print);
int print_binary(va_list print);
void init_buffer(char buffer[]);
void buffer_write(char buffer[], int *buf_len, int *buf_pos);
int buffer_copy(char format, char buffer[], int *buf_lenptr, int *buf_posptr);
int print_num(int num, char buffer[], int *buf_lenptr, int *buf_posptr);
char *bin_convert(unsigned int num);


#endif/*MAIN_H*/
