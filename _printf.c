#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "main.h"
/**
 *  _printf - print anything
 * @format :array of characters(string) contains the formats of elements  printed
 *  Return:the number of characters printed
 */
int _printf(const char *format, ...)
{
int count = 0;
char c;
va_list args;
va_start(args, format);
if (format == NULL)
return (-1);
while ((c = *format) != '\0')
{
if (c != '%')
{
write(STDOUT_FILENO, &c, 1);
count++;
}
else
{
format++;
c = *format;
switch (c)
{
case '%':
 {
write(STDOUT_FILENO, "%", 1);
count++;
}
break;
case 'c':
{
char *arg = va_arg(args, char*);
write(STDOUT_FILENO, arg, 1);
count++;
}
break;
case 's':
{
char *str = va_arg(args, char*);
while (*str != '\0')
{
write(STDOUT_FILENO, str, 1);
str++;
count++;
}
}
break;
}
}
format++;
}
va_end(args);
return (count);
}

