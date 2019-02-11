#include "libft.h"

int ft_printf(const char * restrict format, ...)
{
	va_list ap;
	char c, *s;
	int d;

	va_start(ap, format);
	while (*format)
	{
		while (*format != '%') //or /0 ?
		{
			write(1, format, 1);
			format++;
		}
		format++; //Handle %% ?

		switch (*format++) {
			case 's':              /* string */
				s = va_arg(ap, char *);
				ft_putstr(s);
				break;
			case 'd':              /* int */
				d = va_arg(ap, int);
				ft_putnbr(d);
				break;
			case 'c':              /* char */
				/* need a cast here since va_arg only
				   takes fully promoted types */
				c = (char)va_arg(ap, int);
				write(1, &c, 1);
				break;
		}
	}
	va_end(ap);
	return (0);
}

//add a convert() same as atoi base

