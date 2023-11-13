#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

/**
 * struct format - match the conversion specifiers for printf
 * @id: type char pointer of the specifier i.e (l, h) for (d, i, u, o, x, X)
 * @f: type pointer to function for the conversion specifier
 *
 */
typedef struct format
{
	char *id;
	int (*f)();
} call_match;

int _printf(const char *format, ...);
int _putchar(char c);
int print_int(va_list args);
int print_dec(va_list args);
int print_string(va_list args);
int print_char(va_list args);
int print_percent(void);
int _strlen(char *s);
int print_unsigned_int(va_list args);
int print_bin(va_list val);
int print_oct(va_list val);
int print_HEX(va_list val);
int print_hex(va_list val);
int _strlenp(const char *s);

#endif
