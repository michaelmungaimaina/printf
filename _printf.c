#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_binary - implementation of %b binary conversion
 * @num: affected integers
 *
 * Return: either 1 or 0
 */

int print_binary(unsigned int num)


/**
 * _printf - prints character & string to std output
 * @format: c & s format specifier
 *
 * Return: count
 */

int _printf(const char * const format, ...)
{
	va_list args;
	va_start(args, format);

	int count = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
			{
				fprintf(stderr, "Error: incomplete format specifier\n");
				va_end(args);
				return (-1);
			}

			switch (*format)
			{
				case 'c':
					count += custom_putchar(va_arg(args, int));

					break;
				case 's':
					count += printf("%s", va_arg(args, char *));
					break;
				case '%':
					count += custom_putchar('%');

					break;
					case 'b':
					count += print_binary(va_arg(args, unsigned int));
					break;
				default:
					count += custom_putchar('%');
					count += custom_putchar(*format);
			}
		}
		else
		{
			count += custom_putchar(*format);
		}
		format++;
	}

	va_end(args);
	return (count);
}
