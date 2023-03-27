#include "main.h"
#include <stdarg.h>
#include <unistd.h>

int _putchar(char c)
{
	return (write(1, &c, 1));
}

int _printf(const char *format, ...)
{
	int i;
	const char *p;

	int printed = 0;
	va_list args;

	va_start(args, format);

	for (p = format; *p != '\0'; p++)
	{
		if (*p == '%')
		{
			p++;
	switch (*p)
	{
		case 'c':
		{
			char value = (char) va_arg(args, int);

			_putchar(value);
			printed++;
			break;
		}
		case 's':
		{
			char *value = va_arg(args, char*);

			for (i = 0; value[i] != '\0'; i++)
			{
				_putchar(value[i]);
				printed++;
			}
			break;
		}
		case '%':
		{
			_putchar('%');
			printed++;
			break;
		}
		default:
		break;
	}
	}
	else
	{
		_putchar(*p);
		printed++;
	}
	}

		va_end(args);
	return (printed);
}
