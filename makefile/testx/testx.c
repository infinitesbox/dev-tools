#include "testx.h"
#include <stdio.h>
#include <stdarg.h>

int testx_total = 0;
int testx_total_success = 0;
int testx_total_fail = 0;

void testx(int is_valid, ...)
{
    va_list args;
    char *error;

    if (!is_valid) 
    {   
        va_start(args, is_valid);
        error = va_arg(args, char *);
        vprintf("  ---> ", args);
        vprintf(error, args);
        vprintf("\n", args);
        va_end(args);
        testx_total_fail++;
    }
    else
        testx_total_success++;
    testx_total++;
    testx_print_detail();
}

void testx_print_detail()
{
    printf("TOTAL Tests: %d, \033[32mSUCCESS: %d\033[0m, \033[31mFAIL: %d\033[0m\n", testx_total, 
        testx_total_success, testx_total_fail);

}