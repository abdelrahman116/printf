#ifndef MATH_H
#define MAYH_H
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#define BUFFER_SIZE 1024
int print_decimal(int num, char *buffer, int *count);
int print_unsigned_decimal(unsigned int num, char *buffer, int *count);
int _printf(const char * const format, ...);
int print_octal(unsigned int num, char *buffer, int *count);
int print_hexadecimal(unsigned int num, char *buffer, int *count, int uppercase);
void print_binary(unsigned int num, char *buffer, int *count);
#endif
