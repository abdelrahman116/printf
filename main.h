#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
int _putchar(char c);
void print_binary(unsigned int num);
int print_decimal(int num);
int print_unsigned_decimal(unsigned int num);
int print_octal(unsigned int num);
int print_hexadecimal(unsigned int num, int uppercase);
int _printf(const char * const format, ...);
#endif
