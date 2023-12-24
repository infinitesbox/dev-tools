#include "../inc/calculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <testx.h>
#include <mathx.h>

int main(void)
{
	puts("Calculator Tests");
	puts("----------");

	int s = mathx_add(1, 2);
	testx(_tx_(s, ==, 3), "Error add.");

	int d = mathx_sub(1, 2);
	testx(_tx_(d, ==, -1), "Error sub.");

	int p = mathx_mult(1, 2);
	testx(_tx_(p, ==, 2), "Error mult.");

	int q = mathx_div(1, 2);
	testx(_tx_(q, ==, 0), "Error div.");

	return 0;
}