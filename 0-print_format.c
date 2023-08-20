#include "main.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Function to print character according to input format
 * @format: The input format of the character
 *
 * Return: The printed character according to format
 */

int _printf(const char *format, ...)
{
	int i = 0;
	int count = 0;
	int str_len1;
	char secondarg;
	char *thirdarg;
	
	va_list result;
	va_start(result, format);

	for (i = 0; format && format[i]; i++)
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
				putchar("%");
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
				str_len1 = strlen(thirdarg);
				count += str_len1;
			}
		}
	}
	va_end(result);
	return (count);
}
