#ifndef TESTX
#define TESTX

#define _tx_(a, x, b) ((a x b) ? 1 : 0)

extern int testx_total;
extern int testx_total_success;
extern int testx_total_fail;

void testx(int is_valid, ...);
void testx_print_detail();

#endif