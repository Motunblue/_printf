#include "main.h"

/**
 * _printf - a function that produces output according to a format
 * @format: format
 * Return: 0
 */
int _printf(const char *format, ...)
{
va_list list;
int count = 0;

va_start(list, format);
while (format && *format)

{
if (*format != '%')
count += print_char(*format);
else if (*format == '%' && !*(format + 1))
{
count = -1;
break;
}
else
count += print_fmt(*(++format), list);
format++;
}
print_char(-1);
va_end(list);
return (count);
}
