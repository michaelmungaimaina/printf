#include "main.h"
#include <stdarg.h>

/**
 * _printf - is a function that calls the correct prototype function to print.
 * @format: identifier to look for.
 * Return: the length of the string.
 */
int _printf(const char *format, ...)
{
	/** Conversion specifier and function pointer **/
	call_match m[] = {
		{"%i", print_int},
		{"%d", print_dec},
		{"%s", print_string},
		{"%c", print_char},
		{"%%", print_percent},
		{"%u", print_unsigned_int},
		{"%b", print_bin},
		{"%o", print_oct},
		{"%x", print_hex},
		{"%X", print_HEX},
		{"%S", non_printable_char},
		{"%p", print_pointer}
	};

	/** Holds variable arguments **/
	va_list args;
	int i = 0, j, len = 0;

	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);

Here:
	/** format processing **/
	while (format[i] != '\0')
	{
		j = 11;
		while (j >= 0)
		{
			if (m[j].id[0] == format[i] && m[j].id[1] == format[i + 1])
			{
				len += m[j].f(args);
				i = i + 2;
				goto Here;
			}
			j--;
		}
		/** default case **/
		_putchar(format[i]);
		len++;
		i++;
	}
	va_end(args);
	return (len);
}
