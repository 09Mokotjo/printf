#include <stdio.h>
#include "main.h"

int print_binary(unsigned int num)
{
    int count = 0;
    char binary[32];
    int binary_length = 0;
    int i;

    if (num == 0)
    {
        count += putchar('0');
        return count;
    }


    while (num > 0)
    {
        binary[binary_length] = (num % 2) + '0';
        num /= 2;
        binary_length++;
    }

    for (i = binary_length - 1; i >= 0; i--)
    {
        count += putchar(binary[i]);
    }

    return count;
}

int handle_b(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    return print_binary(num);
}

