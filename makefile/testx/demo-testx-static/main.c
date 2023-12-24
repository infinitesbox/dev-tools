#include <stdio.h>
#include <stdlib.h>
#include <testx.h>

int main()
{
	puts("Testx Lib.");

	testx(_tx_(1, ==, 2), "Error: 1 == 2\n");
	testx(_tx_(2, !=, 2), "Error: 2 != 2\n");
	testx(_tx_(2, <, 2), "Error: 2 < 2\n");
	testx(_tx_(1, >, 2), "Error: 1 > 2\n");
	
	return 0;
}