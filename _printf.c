#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
/**
 * _printf - prints formatted output to stdout
 * @format: a pointer to a string containing zero or more format specifiers
 * @...: optional arguments to be inserted into the format string
 * Return: the number of characters printed (excluding the null byte used to end
 */
int _printf(const char *format, ...)
{
int count = 0;
const char *c;
va_list args;
va_start(args, format);

if (format == NULL)
{
return (-1);
}

for (c = format; *c != '\0'; c++)
{
if (*c != '%')
{
write(STDOUT_FILENO, c, 1);
count++;
}
else
{
c++;
switch (*c)
{
case '%':
write(STDOUT_FILENO, "%", 1);
count++;
break;
case 'c':
{
char arg = va_arg(args, int);
write(STDOUT_FILENO, &arg, 1);
count++;
break;
}
case 's':
{
char *str = va_arg(args, char*);
while (*str != '\0')
{
write(STDOUT_FILENO, str, 1);
str++;
count++;
}
break;
}
default:
write(STDOUT_FILENO, "Error: Invalid format specifier\n", 32);
return (-1);
}
}
}

va_end(args);
return (count);
}

