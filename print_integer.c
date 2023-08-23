#include <stdio.h>
#include <limits.h>
#include "main.h"

int print_integer(int num)
{
    int count = 0;
    int num_digits = 0;
    int temp, i, digit;
    char digits[12];

    if (num == 0)
    {
        count += putchar('0');
        return count;
    }

    if (num < 0)
    {
        count++;
        num_digits++;
    }

    temp = num < 0 ? -num : num;

    while (temp > 0)
    {
        digit = temp % 10;
        digits[num_digits++] = '0' + digit;
        temp /= 10;
    }

    if (num < 0)
    {
        count += putchar('-');
    }

    for (i = num_digits - 1; i >= 0; i--)
    {
        count += putchar(digits[i]);
    }

    return count;
}

