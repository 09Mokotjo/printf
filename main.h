#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
int _printf(const char *format, ...);
int handle_d(int num);
int print_integer(int num);
int print_binary(unsigned int num);
int handle_b(va_list args);
int handle_i(int num);
#endif
