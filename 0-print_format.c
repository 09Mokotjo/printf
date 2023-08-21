#include <stdio.h>
#include <stdarg.h>

int _printf'(const char * format)'
{
	int count = 0;
	va_list args;
	va_start (args, format);

	for (int i = 0; format[i] != '\0'; i++)
	{
<<<<<<< HEAD
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
=======
		if (format[i] != '%')
                {
                        putchar(format[i]);
                        count++;
                }
                else
                {
			i++;
                        nextarg = format[i];
                        if (nextarg == '%')
                        {
                                putchar('%');
                                count++;
                        }
                        else if (nextarg == 'c')
                        {
                                secondarg = va_arg(result, int);
                                putchar(secondarg);
                                count++;
                        }
			else if (nextarg == 's')
                        {
                                thirdarg = va_arg(result, char*);
                                fputs(thirdarg, stdout);
                                str_len1 = strlen(thirdarg);
                                count += str_len1;
                        }
                        else if (nextarg == 'r')
                        {
                                printf("%%r");
                                count ++;
                        }
>>>>>>> 9320f2c936efd4db57e49b9f1583013b84ae1a46
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

