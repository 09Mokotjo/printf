#include <stdio.h>
#include <stdarg.h>

void print_binary(unsigned int num)
{
    if (num > 1)
        print_binary(num / 2);

    putchar('0' + (num % 2));
}

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0;

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++; // skip the '%'
            if (*format == 'c')
            {
                // Handle character specifier
                int c = va_arg(args, int);
                putchar(c);
                count++;
            }
            else if (*format == 's')
            {
                // Handle string specifier
                char *s = va_arg(args, char *);
                while (*s != '\0')
                {
                    putchar(*s);
                    s++;
                    count++;
                }
            }
            else if (*format == '%')
            {
                // Handle '%' specifier
                putchar('%');
                count++;
            }
            else if (*format == 'd' || *format == 'i')
            {
                // Handle decimal and integer specifiers
                int num = va_arg(args, int);
                printf("%d", num);
                count++;
            }
            else if (*format == 'b')
            {
                // Handle binary specifier
                unsigned int num = va_arg(args, unsigned int);
                print_binary(num);
                count++;
            }
        }
        else
        {
            // Handle regular characters
            putchar(*format);
            count++;
        }

        format++;
    }

    va_end(args);

    return count;
}

int main(void)
{
    _printf("%b\n", 98);
    return 0;
}

