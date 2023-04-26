#include <stdio.h>
#include <unistd.h>
#include "main.h"
/**
* write_int - write an integer
* @num:an integer value
* Return:return the length of the integer(d)
*/
int write_int(int num)
{
char buffer[100];
int length = sprintf(buffer, "%d", num);
write(STDOUT_FILENO, buffer, length);
return (length);
}

