#include "../../inc/calculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <mathx.h>

void menu()
{
    unsigned char mode;

    while (1)
    {
        puts("Choose the mode:");
        puts("\ta - Add");
        puts("\ts - Subtract");
        puts("\tm - Multiply");
        puts("\td - Divide");
        puts("\t% - Modulus");
        puts("\tq - Quit");

        if (scanf(" %c", &mode) != 1) {
            fprintf(stderr, "Error reading mode\n");
            exit(EXIT_FAILURE);
        }

        if (mode == 'q')
            break;
        else if (mode == 'a')
            printf("\tAdd: 2 + 2 = %d\n", mathx_add(2, 2));
        else if (mode == 's')
            printf("\tSubtract: 2 + 2 = %d\n", mathx_sub(2, 2));
        else if (mode == 'm')
            printf("\tMultiply: 2 + 2 = %d\n", mathx_mult(2, 2));
        else if (mode == 'd')
            printf("\tDivide: 2 + 2 = %d\n", mathx_div(2, 2));
        else if (mode == '%')
            puts("\tModulus:");
        else
            puts("\tInvalid mode. Please choose again.");
    }
}

