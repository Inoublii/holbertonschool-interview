#include <stdlib.h>
#include <stdio.h>

#include "palindrome.h"

/**
 * is_palindrome - Checks if  palindrome
 * @n: Number to be checked
 * Returns: return 1 if n is a palindrome or 0
 */

int is_palindrome(unsigned long n)
{
	unsigned long r = 0, on, re;

	on = n;
	while (n != 0)
	{
		re = n % 10;
		r = r * 10 + re;
		n /= 10;
	}
	if (on == r)
		return (1);
	return (0);
}
