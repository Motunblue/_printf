#include "main.h"

/**
 * print_ptr - Prints an address
 * @ptr: Address to print
 * Return: Number of characters printed
 */
int print_ptr(const void *ptr)
{
	int count = 0;
	unsigned long address = (unsigned long)ptr;

	count += print_char('0');
	count += print_char('x');

	count += print_hex(address, 'x');
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
		count += print_hex(n / base, base);
	count += print_char((n % base) + '0');
	return (count);
}

