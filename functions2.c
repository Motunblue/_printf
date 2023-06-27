#include "main.h"

/**
 * print_ptr - Prints an address
 * @ptr: Address to print
 * Return: Number of characters printed
 */
int print_ptr(const void *ptr)
{
	static int q;
	int count = 0;
	unsigned long address = (unsigned long)ptr;

	q = 0;

	if (q == 0)
	{
		count += print_char('0');
		count += print_char('x');
		q = 1;
	}

	if (address / 16 != 0)
		count += print_ptr((void *)(address / 16));
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
 * @base: Base of the interger
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
 * Description: This only handle bases less that 10
 * Return: count of interger printed
 */
int print_base(long m, int base)
{
	int count = 0;
	unsigned int n = (unsigned int)m;

	if (n / base != 0)
		count += print_base(n / base, base);
	count += print_char((n % base) + '0');
	return (count);
}

