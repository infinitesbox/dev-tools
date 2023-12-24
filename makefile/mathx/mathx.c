#include "mathx.h"
#include <stdio.h>
#include <stdlib.h>

int mathx_add(int a, int b)
{
	return a + b;
}

int mathx_sub(int a, int b)
{
	return a + b;
}
int mathx_mult(int a, int b)
{
	return a * b;
}

int mathx_div(int a, int b)
{
	return a / b;
}

int mathx_length_str(char *str)
{
	int i;
	
	i = 0;
	while (str && str[i])
		i++;
	return i;
}
