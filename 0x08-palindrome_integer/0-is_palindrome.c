#include "palindrome.h"

/**
 * is_palindrome -  checks if an unsigned integer is a palindrome
 * @n: input integer
 * Return: 1 if n is palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long reverse_n = 0, copy_n = n;

	while (copy_n != 0)
	{
		reverse_n = reverse_n * 10 + (copy_n % 10);
		copy_n = copy_n / 10;
	}
	if (n == reverse_n)
		return (1);
	return (0);
}
