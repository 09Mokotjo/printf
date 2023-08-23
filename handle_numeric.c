#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdint.h>

void print_unsigned(unsigned int num, int *count)
{
    unsigned int temp = num;
    int num_digits = 0;
    int i;
    char *digits;

    do {
        temp /= 10;
        num_digits++;
    } while (temp > 0);

    digits = (char *)malloc((num_digits + 1) * sizeof(char));
    if (digits == NULL) {
        return;
    }

    i = num_digits - 1;
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

    free(digits);
}

void print_octal(unsigned int num, int *count)
{
    int num_digits = 0;
    unsigned int temp = num;
    char *digits;
    int i;

    do {
        temp /= 8;
        num_digits++;
    } while (temp > 0);

    digits = (char *)malloc((num_digits + 1) * sizeof(char));
    if (digits == NULL) {
        return;
    }

    i = num_digits - 1;

    do {
        digits[i] = num % 8 + '0';
        num /= 8;
        i--;
    } while (num > 0);

    for (i = 0; i < num_digits; i++) {
        putchar(digits[i]);
        (*count)++;
    }

    free(digits);
}

void print_hexadecimal(unsigned int num, int *count, char specifier)
{
    char digits[16];
    int i = 0;

    while (num > 0) {
        int digit = num % 16;
        digits[i] = (digit < 10) ? (digit + '0') : (digit - 10 + ((specifier == 'x') ? 'a' : 'A'));
        num /= 16;
        i++;
    }

    for (i = i - 1; i >= 0; i--) {
        putchar(digits[i]);
        (*count)++;
    }
}

void print_address(void *addr, int *count)
{
    uintptr_t num = (uintptr_t)addr;

    int num_digits = 0;
    int i, remainder;
    char *digits;
    uintptr_t temp = num;

    do {
        temp /= 16;
        num_digits++;
    } while (temp > 0);

    digits = (char *)malloc((num_digits + 1) * sizeof(char));
    if (digits == NULL) {
        return;
    }

    i = num_digits - 1;

    do {
        remainder = num % 16;
        digits[i] = (remainder < 10) ? remainder + '0' : remainder - 10 + 'a';
        num /= 16;
        i--;
    } while (num > 0);

     putchar('0');
    putchar('x');
    *count += 2;

    for (i = 0; i < num_digits; i++) {
        putchar(digits[i]);
        (*count)++;
    }

    free(digits);
}
