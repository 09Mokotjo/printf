#include "holberton.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * _printf - printed output according to a format.
 * @format: The character string.
 *
 * Return: The number of characters printed (excluding  null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, j = 0, len = 0;
	char *str;

	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			j = i + 1;
			while (format[j] == ' ')
				j++;
			if (!format[j])
				return (-1);
			switch (format[j])
			{
				case 'c':
					len += _putchar(va_arg(args, int));
					break;
				case 's':
					str = va_arg(args, char *);
					if (!str)
						str = "(null)";
					len += _puts(str);
					break;
				case '%':
					len += _putchar('%');
					break;
				default:
					len += _putchar(format[i]);
					len += _putchar(format[j]);
			}
			i = j;
		}
		else
			len += _putchar(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}

