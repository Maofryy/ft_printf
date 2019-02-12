#include "libft.h"

#include <stdio.h>
int		get_to_arg(const char * restrict * p)
{
	int i;

	i = 0;
	while (**p && **p != '%')
	{
		ft_putchar(**p);
		(**p) ? i++ : 0;
		(*p)++;
	}
	(*p)++;
	if (**p == '%')
	{
		ft_putchar(**p);
		(*p)++;
		i+= get_to_arg(p) + 1;
	}
	printf("\nint ret : %d\n", **p);
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
