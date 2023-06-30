#include "main.h"

/**
 * print_r - Prints the custom specifier r
 * Strings are printed in reversed
 * @s: String to print
 * Return: count of string printed
 */

int print_r(char *s)
{
	int count = 0;
	int strcount = 0;
	int j = 0;

	if (s == NULL)
	{
		count += print_str("(nil)");
		return (count);
	}
	while (s[j])
	{
		j++;
		strcount++;
	}
	while (strcount)
		count += print_char(s[strcount-- - 1]);
	return (count);

}

/**
 * print_R - Prints the custom specifier R
 * ROT13 string is printed
 * @s: string to print
 * Return: count of strings printed
 */

int print_R(char *s)
{
	int count = 0;
	char c;

	if (s == NULL)
	{
		count += print_str("(nil)");
		return (count);
	}

	while ((c = *s++) != '\0')
	{
		if (c >= 'a' && c <= 'z')
			c = ((c - 'a' + 13) % 26) + 'a';
		else if (c >= 'A' && c <= 'Z')
			c = ((c - 'A' + 13) % 26) + 'A';
		count += print_char(c);
	}
	return (count);
}
