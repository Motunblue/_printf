#include "main.h"

/**
 * print_ptr - Prints an address
 * @ptr: Address to print
 * @q: The integer
 * Return: Number of characters printed
 */
int print_ptr(const void *ptr, int q)
{

	int count = 0;
	unsigned long address = (unsigned long)ptr;

	if (!ptr)
	{
		count += print_str("(nil)");
		return (count);
	}

	if (q == 1)
	{
		count += print_char('0');
		count += print_char('x');

	}

	if (address / 16 != 0)
		count += print_ptr((void *)(address / 16), 0);
	if ((address % 16) > 9)
	{
		count += print_char((address % 16) + 'x' - 33);
	}
	else
		count += print_char((address % 16) + '0');

	return (count);
}

/**
 * print_u - Prints a signed int
 * @n: Interger to print
 * @base: Base ofthe interger
 * Return: Number of character printed
 */
int print_u(int n, int base)
{
	int count = 0;

	unsigned int h = (unsigned int)n;

	if (n / base != 0)
		count += print_u(h / base, base);
	count += print_char((h % base) + '0');
	return (count);
}


/**
 * print_base - Prints an interger
 * @base: base to print the interger in
 * @m: Interger to print
 * @flag: handles the flag
 * Description: This only handle bases less that 10
 * Return: count of interger printed
 */
int print_base(long m, int base, char flag)
{
	int count = 0;
	unsigned int n = (unsigned int)m;

	if (flag && base == 8)
	{
	if (flag == '#')
		count += print_char('0');
	}

	if (n / base != 0)
		count += print_base(n / base, base, 0);
	count += print_char((n % base) + '0');
	return (count);
}

