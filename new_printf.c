#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

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
		{
		    char c = va_arg(args, int);
                    count += write(1, &c, 1);
                    break;
		}
                case 's':
                {
                    const char *str = va_arg(args, const char *);
                    while (*str != '\0')
                    {
                        count += write(1, str, 1);
                        str++;
                    }
                    break;
                }
                case '%':
		{
                    char percent = '%';
                    count += write(1, &percent, 1);
                    break;
		}
                default:
                    // Unsupported conversion specifier, ignore
                    break;
            }
        }
        else
        {
            count += write(1, format, 1);
        }

        format++;  // Move to the next character in the format string
    }

    va_end(args);
    return count;
}
