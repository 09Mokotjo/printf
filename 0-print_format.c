#include <stdio.h>
#include <stdarg.h>

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
}

