#include <stdio.h>
#include "struct.h"
double END_Timer(clock_t begin)
{
	clock_t end = clock();
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	return time_spent*1000;
}
int main()
{
    printf("*************************************************\n  welcome to our repository");

    return 0;
}
