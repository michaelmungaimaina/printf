#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>
/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

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
int print_rot13(va_list val);
int print_reverse_string(va_list val);
int print_pointer(va_list val);
int non_printable_char(va_list val); 
int print_HEX_aux(unsigned int n);
int print_hex_aux(unsigned long int n);
int get_flags(const char *format, int *i);
int _strlenp(const char *s);

#endif
