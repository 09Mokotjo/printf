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
	int i, count = 0, j;
	char secondarg;
	char *thirdarg, str[20];

	va_list(result);
	va_start(result, format);

	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
		{
			putchar(format[i]);
			count++;
		}
		else
		{
			i++;
			if (format[i] == '%')
			{
				putchar('%');
				count++;
			}
			else if (format[i] == 'c')
			{
				secondarg = va_arg(result, int);
				putchar(secondarg);
				count++;
			}
			else if (format[i] == 's')
			{
				thirdarg = va_arg(result, char*);
				fputs(thirdarg, stdout);
				count += strlen(thirdarg);
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				j = va_arg(result, int);
				sprintf(str, "%d", j);
				fputs(str, stdout);
				count += strlen(str);
			}
			else
			{
				putchar('%');
				putchar(format[i]);
				count += 2;
			}
		}
	}
	va_end(result);
	return (count);
}
