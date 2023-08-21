#include <stdio.h>
#include <stdarg.h>

int _printf'(const char * format)'
{
	int count = 0;
	va_list args;
	va_start (args, format);

	for (int i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				/* Handle 'c' conversion specifier*/
				int character = va_arg(args, int);
				putchar (character);
				count++;
				i++;
			}
			else if (format[i + 1] == 's')
			{
				/* Handle 's' conversion specifier*/
				char *string = va_arg(args, char *);
				for (int j = 0; string[j] != '\0'; j++)
				{
					putchar(string[j]);
					count++;
				}
				i++;
			}
			else if (format[i + 1] == '%')
			{
				/* Handle '%' conversion specifier*/
				putchar('%');
				count++;
				i++;
			}
		}
		else
		{
			 Print the character
			putchar(format[i]);
			count++;
}
}

va_end(args);

return count; /*  added  around expression being returned
		
}

