#include "main.h"
unsigned int binary_to_uint(const char *b)
{
	int j;
	unsigned int val = 0;

	if (!b)
		return (0);

	for (j = 0; b[j]; j++)
	{
		if (b[j] < '0' || b[j] > '1')
			return (0);
		val = 2 * val + (b[j] - '0');
	}

	return (val);
}

