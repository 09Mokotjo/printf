#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
/**
 * _printf - Function to print arguments in their given formats
 * @format: the input argument format
 *
 * Return: Always 0 success
 */

int _printf(const char *format, ...)
{
	int count, secondarg, j;
	char *thirdarg;

	va_list(result);
	va_start(result, format);

	for (count = 0; *format != '\0'; format++)
	{
		if (*format != '%')
		{
			putchar(*format);
			count++;
		}
		else
		{
			format++;
			if (*format == '%')
			{
				putchar('%');
				count++;
			}
			else if (*format == 'c')
			{
				secondarg = va_arg(result, int);
				putchar(secondarg);
				count++;
			}
			else if (*format == 's')
			{
				thirdarg = va_arg(result, char*);
				fputs(thirdarg, stdout);
				count += strlen(thirdarg);
			}
			else if (*format == 'd' || *format == 'i')
			{
				j = va_arg(result, int);
				printf("%d", j);
				count ++;
			}
			else
			{
				putchar('%');
				putchar(*format);
				count += 2;
			}

		}
	}
	va_end(result);
	return (count);
}
