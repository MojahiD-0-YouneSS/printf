#include <stdio.h>
#include <stdarg.h>

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
                    count += putchar(va_arg(args, int));
                    break;
                case 's': 
                {
                    const char *str = va_arg(args, const char *);
                    while (*str != '\0') 
                    {
                        count += putchar(*str);
                        str++;
                    }
                    break;
                }
                case '%':
                    count += putchar('%');
                    break;
                default:
                    // Unsupported conversion specifier, ignore
                    break;
            }
        } 
        else 
        {
            count += putchar(*format);
        }

        format++;  // Move to the next character in the format string
    }

    va_end(args);

    return count;
}
