#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - prints and input into the standard output
 * @format: the format string
 * Return: number of bytes printed
 */


int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0;  // To keep track of the number of characters printed

    while (*format != '\0') 
    {
        if (*format == '%') 
        {
            format++;  // Move past the '%'

            // Check for conversion specifiers
            switch (*format) 
            {
                case 'c':
                    count += _putchar(va_arg(args, int));
                    break;
                case 's': 
                {
                    const char *str = va_arg(args, const char *);
                    while (*str != '\0') 
                    {
                        count += _putchar(*str);
                        str++;
                    }
                    break;
                }
                case '%':
                    count += _putchar('%');
                    break;
                default:
                    // Unsupported conversion specifier, ignore
                    break;
            }
        } 
        else 
        {
            count += _putchar(*format);
        }

        format++;  // Move to the next character in the format string
    }

    va_end(args);

    return count;
}
