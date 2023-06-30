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
int flag = 0;

va_start(list, format);

if (!format)
	return (-1);
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
	{
		flag = getflag(*(format + 1));
		if (flag)
			++format;
		count += print_fmt(*(++format), list, flag);
	}
format++;
}
print_char(-1);
va_end(list);
return (count);
}
