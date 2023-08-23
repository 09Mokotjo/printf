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

<<<<<<< HEAD
int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;
    const char *current = format;

    while (*current != '\0') {
        if (*current == '%') {
            current++;
            switch (*current) {
                case 'c': {
                    char c = (char)va_arg(args, int);
                    putchar(c);
                    count++;
                    break;
                }
                case 's': {
                    char *s = va_arg(args, char *);
                    while (*s != '\0') {
                        putchar(*s);
                        s++;
                        count++;
                    }
                    break;
                }
                case '%': {
                    putchar('%');
                    count++;
                    break;
                }
                default:
                    // Handles the unsupported specifier by ignoring it
                    break;
            }
        } else {
            putchar(*current);
            count++;
        }
        current++;
    }

    va_end(args);
    return count;
}

int main() {
    _printf("Hello, %s! The character is %c and a %% sign.\n", "world", 'A');
    return 0;
=======
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
>>>>>>> 1291157b5a8337f15a33f291a9ef5325fdc2991f
}
