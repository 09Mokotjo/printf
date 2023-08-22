#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

/**
 * _printf - Function to print arguments in their given formats
 * @format: the input argument format
 *
 * Return: Always 0 success
 */

int _printf(const char *format, ...)
{
	int count = 0, secondarg;
	char *thirdarg;
	const char *ptr;
	va_list(result);
	va_start(result, format);

	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr != '%')
		{
			putchar(*ptr);
			count++;
		}
		else
		{
			ptr++;
			if (*ptr == '%')
			{
				putchar('%');
				count++;
			}
			else if (*ptr == 'c')
			{
				secondarg = va_arg(result, int);
				putchar(secondarg);
				count++;
			}
			else if (*ptr == 's')
			{
				thirdarg = va_arg(result, char*);
				fputs(thirdarg, stdout);
				count += strlen(thirdarg);
			}
		}
	}
	va_end(result);
	return (count);
}
