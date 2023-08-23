#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>

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
				while (*thirdarg != '\0')
				{
					count += putchar(*thirdarg);
					thirdarg++;
				}
			}
			else if (*format == 'd' || *format == 'i')
			{
				j = va_arg(result, int);
				count += print_integer(j);
			}
			else if (*format == 'b')
			{
				count += handle_b(result);
			}
			else if (*format == 'u')
{
    unsigned int u_value = va_arg(result, unsigned int);
    print_unsigned(u_value, &count);
}
else if (*format == 'o')
{
    unsigned int o_value = va_arg(result, unsigned int);
    print_octal(o_value, &count);
}
else if (*format == 'x' || *format == 'X')
{
    unsigned int x_value = va_arg(result, unsigned int);
    char specifier = *format;
    print_hexadecimal(x_value, &count, specifier);
}
else if (*format == 'p')
{
    void *addr = va_arg(result, void *);
    print_address(addr, &count);
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
