#include "libft.h"

#include <stdio.h>
int		get_to_arg(const char * restrict * p)
{
	int i;

	i = 0;
	while (**p && **p != '%')
	{
		if (!**p)
			return (i);
		i++;
		ft_putchar(**p);
		(*p)++;
	}
	(*p)++;
	if (**p == '%')
	{
		ft_putchar(**p);
		(*p)++;
		i+= get_to_arg(p) + 1;
	}
	return (i);
}

int	check_args(const char * restrict format)
{
	// Check if number of args is okay, use va_copy and count, cant do that with varidic function actually
	while (*format)
	{
		get_to_arg(&format);
		if (*++format == '%')
		{
			format++;
			continue;
		}
		//is format flags ?
		//is int / field width
		//is .int / precision 
		//is h,l,L , then is h or l, then ok
		//is cspdiouxXf ? strchr no null ?
	
		//if test fails, means not well formated and return 0.
	}
	return (1);
}
