#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdlib.h>

char *intToBinaryString(int num)
{
	int temp = num;
	int binaryLength = 0;
	int index = binaryLength - 1;
	char *binaryStr = (char *)malloc(binaryLength + 1);

	if (num == 0)
	{
		return strdup("0");
	}

	while (temp > 0)
	{
		temp /= 2;
		binaryLength++;
	}

	if (binaryStr == NULL)
	{
		return NULL;
	}

	while (num > 0)
	{
		binaryStr[index] = (num % 2) + '0';
		num /= 2;
		index--;
	}
	binaryStr[binaryLength] = '\0';
	return (binaryStr);
}

/**
 * _printf - Function to print arguments in their given formats
 * @format: the input argument format
 *
 * Return: Always 0 success
 */

int _printf(const char *format, ...)
{
	int i, count = 0, j, k;
	char secondarg;
	char *thirdarg, str[20], *binaryStr;

	va_list(result);
	va_start(result, format);

	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
		{
			putchar(format[i]);
			count++;
		}
		else
		{
			i++;
			if (format[i] == '%')
			{
				putchar('%');
				count++;
			}
			else if (format[i] == 'c')
			{
				secondarg = va_arg(result, int);
				putchar(secondarg);
				count++;
			}
			else if (format[i] == 's')
			{
				thirdarg = va_arg(result, char*);
				fputs(thirdarg, stdout);
				count += strlen(thirdarg);
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				j = va_arg(result, int);
				sprintf(str, "%d", j);
				fputs(str, stdout);
				count += strlen(str);
			}
			else if (format[i] == 'b')
			{
				k = va_arg(result, int);
				binaryStr = intToBinaryString(k);
				if (binaryStr != NULL)
				{
					fputs(binaryStr, stdout);
					count += strlen(binaryStr);
					free(binaryStr);
				}
			}
			else
			{
				putchar('%');
				putchar(format[i]);
				count += 2;
			}
		}
	}
	va_end(result);
	return (count);
}
