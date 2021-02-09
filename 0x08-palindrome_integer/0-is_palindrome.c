#include "palindrome.h"

/**
 * is_palindrome - Validate is palindrome number
 *
 * @n: Number validate is palindrome
 *
 * Return: 1: is palindrome 0: FAILURE
 */

int is_palindrome(unsigned long n)
{
	unsigned long t = n, r = 0;
	int pal;

	pal = recursion(n, t, r);
	return (pal);
}

/**
 * recursion - recursion validate
 *
 * @n: Number validate is palindrome
 * @t: quantity of digit a number
 * @r: swap the number
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */

int recursion(unsigned long n, unsigned long t, unsigned long r)
{
	if (t != 0)
	{
		r = r * 10;
		r = r + t % 10;
		t = t / 10;
		if (recursion(n, t, r))
			return (1);
		return (0);
	}

	if (n == r)
		return (1);
	return (0);
}
