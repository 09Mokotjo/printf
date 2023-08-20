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
	int i, count, str_len1;
	int secondarg, nextarg;
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
                        nextarg = va_arg(result, int);
                        if (nextarg == '%')
                        {
                                putchar('%');
                                count++;
                        }
                        else if (nextarg == 'c')
                        {
                                secondarg = va_arg(result, int);
                                putchar(secondarg);
                                count++;
                        }
			else if (nextarg == 's')
                        {
                                thirdarg = va_arg(result, char*);
                                fputs(thirdarg, stdout);
                                str_len1 = strlen(thirdarg);
                                count += str_len1;
                        }
                        else
                        {
                                putchar('%');
                                count += 2;
                        }
		}
	}
	va_end(result);
	return (count);
}
