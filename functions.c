#include "main.h"

/**
 * print_char - write a character to a buffer
 * @c: The character to write
 *
 * Description: Writes a character to a buffer of 1024 bytes.
 * Prints the characters in the buffer when the buffer is full
 * or when the character to write is -1
 * Return: Always 1
 */
int print_char(char c)
{
	 static char buff[BUFF_SIZE];
	 static int i;

	if (c == -1 || i == (BUFF_SIZE - 1))
	{
		write(1, &buff, i);
		i = 0;
	}
	if (c != -1)
		buff[i++] = c;
	return (1);
}

/**
 * print_str - Prints a string
 * @s: string to print
 * Return: Number of elements in the string
 */
int print_str(char *s)
{
	int count = 0;

	if (s == NULL)
	{
		print_str("(null)");
		return (-1);
	}

	while (*s != '\0')
		count += print_char(*s++);
	return (count);
}

/**
 * print_int - Prints an interger
 * @base: base to print the interger in
 * @n: Interger to print
 * Description: This only handle bases less that 10
 * Return: count of interger printed
 */
int print_int(long n, int base)
{
	int count = 0;


	if (n < 0)
	{
		count += print_char('-');
		n = -n;
	}
	if (n / base != 0)
		count += print_int(n / base, base);
	count += print_char((n % base) + '0');
	return (count);
}

/**
 * print_hex - Prints integer an integer in hexadecimal
 * @n: Integer to print
 * @x: the character alx X or x
 * Return: count of interger printed
 */
int print_hex(long n, char x)
{
	int count = 0;


	if (n < 0)
	{
		count += print_char('-');
		n = -n;
	}
	if (n / 16 != 0)
		count += print_hex(n / 16, x);
	if ((n % 16) > 9)
	{
		count += print_char((n % 16) + x - 33);
	}
	else
		count += print_char((n % 16) + '0');
	return (count);
}

/**
 * print_S - Prints a string
 * @s: String to print
 * Description: Print the hexadecimal value of the string
 * if string is not a printable character
 * Return: count of character printed
 */
int print_S(char *s)
{
	int count = 0;

	while (*s != '\0')
	{
		if ((*s >= 0 && *s < 32) || (*s >= 127))
		{
			count += print_char('\\');
			count += print_char('x');
			if (*s < 16)
				count += print_char('0');
			count += print_hex(*s++, 'X');
		}
		else
		{
			count += print_char(*s++);
		}
	}

	return (count);
}
