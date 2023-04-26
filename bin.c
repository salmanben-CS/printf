#include <stdio.h>
#include "main.h"
/**
*bin - convert to binary
*@num: the unsigned int argument is converted to binary
*@n:pointer points on count
*Return:void
*/
void bin(int num, int *n)
{
int r;
if (num == 0)
return;
r = num % 2;
(*n)++;
bin(num / 2, n);
write_int(r);
}

