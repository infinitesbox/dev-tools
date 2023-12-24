#include <stdio.h>
#include "testx.h"

int main(int argc, char **argv)
{
    testx(_tx_(1, ==, 2), "error\n");
    return (0);
}