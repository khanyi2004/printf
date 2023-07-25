#include <stdio.h>
#include <stdarg.h>
#include "main.h"

int _printf(const char *format, ...) {
    va_list args;
    va_start(args, format);

    int charCount = 0;

    while (*format != '\0') {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'c':
                    charCount += putchar(va_arg(args, int));
                    break;
                case 's': {
                    const char *str = va_arg(args, const char *);
                    while (*str != '\0') {
                        charCount += putchar(*str);
                        str++;
                    }
                    break;
                }
                case '%':
                    charCount += putchar('%');
                    break;
                default:
                    charCount += putchar('%');
                    charCount += putchar(*format);
            }
        } else {
            charCount += putchar(*format);
        }
        format++;
    }

    va_end(args);
    return charCount;
}

int main() {
    int charCount = _printf("Printing characters: %c %c %c\n", 'A', 'B', 'C');
    charCount += _printf("Printing a string: %s\n", "Hello, World!");
    charCount += _printf("Printing a percentage sign: %%\n");
    printf("Total characters printed: %d\n", charCount);
    return 0;
}

