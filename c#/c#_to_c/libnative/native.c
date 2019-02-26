#include "native.h"
#include <limits.h>

MODULE_API char* say_hello()
{
	return "Hello world!";
}

MODULE_API int32_t multiply(int32_t x, int32_t y)
{
	return x * y;
}

MODULE_API int32_t min(int32_t *array, int32_t len)
{
	int32_t min = INT_MAX;
	for (int32_t i = 0; i < len; ++i)
	{
		if (min > array[i])
		{
			min = array[i];
		}
	}

	return min;
}
