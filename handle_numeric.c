#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void print_unsigned(unsigned int num, int *count)
{
    unsigned int temp = num;
    int num_digits = 0;
    int i = num_digits - 1;
    char *digits;

    do {
        temp /= 10;
        num_digits++;
    } while (temp > 0);

    digits = (char *)malloc((num_digits + 1) * sizeof(char));
    if (digits == NULL) {
        return;
    }

    do {
        digits[i] = num % 10 + '0';
        num /= 10;
        i--;
    } while (num > 0);

    digits[num_digits] = '\0';

    for (i = 0; i < num_digits; i++) {
        putchar(digits[i]);
        (*count)++;
    }
}

void print_octal(unsigned int num, int *count)
{
    int printed = printf("%o", num);
    *count += printed;
}

void print_hexadecimal(unsigned int num, int *count, char specifier)
{
    int printed = printf(specifier == 'x' ? "%x" : "%X", num);
    *count += printed;
}
