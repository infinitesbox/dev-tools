#include <stdio.h>
#include <stdlib.h>
#include <mathx.h>

int main()
{
	puts("Mathx Lib.");

	printf("add: %d\n", mathx_add(1, 1));
	printf("sub: %d\n", mathx_sub(1, 1));
	printf("mult: %d\n", mathx_mult(2, 1));
	printf("div: %d\n", mathx_div(1, 1));
	printf("str: %d\n", mathx_length_str("mathx"));

	return 0;
}