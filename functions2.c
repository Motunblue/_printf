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
