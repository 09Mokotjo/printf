#include <stdio.h>
#include <stdarg.h>
#include <ctype.h>

void print_rot13(char *str) {
    while (*str) {
        if (isalpha(*str)) {
            char base = isupper(*str) ? 'A' : 'a';
            *str = ((*str - base + 13) % 26) + base;
        }
        putchar(*str);
        str++;
    }
}

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int count = 0;

    while (*format != '\0') {
        if (*format == '%') {
            format++; // skip the '%'
            if (*format == 'c') {
                // Handle character specifier
                int c = va_arg(args, int);
                putchar(c);
                count++;
            } else if (*format == 's') {
                // Handle string specifier
                char *s = va_arg(args, char *);
                while (*s != '\0') {
                    putchar(*s);
                    s++;
                    count++;
                }
            } else if (*format == '%') {
                // Handle '%' specifier
                putchar('%');
                count++;
            } else if (*format == 'd' || *format == 'i') {
                // Handles decimal and integer specifiers
                int num = va_arg(args, int);
                printf("%d", num);
                count++;
            } else if (*format == 'R') {
                // Handles rot13 specifier
                char *str = va_arg(args, char *);
                print_rot13(str);
                count++;
            }
        } else {
            // Handles regular characters
            putchar(*format);
            count++;
        }

        format++;
    }

    va_end(args);

    return count;
}

int main(void) {
    _printf("%R\n", "Hello, World!");
    return 0;
}

