#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * _printf - function my printf
 * @format: string with format to print
 *
 * Return: number of chars that print
 */

int _printf(const char *format, ...)
{
	va_list args;
	int length_of_string = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	length_of_string = _print_format(format, args);
	va_end(args);
	return (length_of_string);
}
