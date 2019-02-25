#include "libft.h"

void	ft_putnstr(char * str, int n)
{
	int i;

	i = 0;
	while (i++ < n)
		ft_putchar(str[i]);
}

int		get_to_arg(char ** p)
{
	/*int i;

	i = 0;
	while (**p && **p != '%')
	{
		i++;
		ft_putchar(**p);
		(*p)++;
	}
	if (!**p)
		return (i);
	(*p)++;
	if (**p == '%')
	{
		ft_putchar(**p);
		(*p)++;
		i+= get_to_arg(p) + 1;
	}
	return (i);*/
	char *s;
	int ret;

	s = ft_strchr(*p, '%');
	ft_putstr("la?");
	if (s == NULL)
		return (0);
	else
	{
		ret = (int)(s - *p);
		*p = s;
	}
	//Handle the double %
	/*
	if (*p[1] == '%')
	{
		then return (get_to_arg(&(*p)[2]) + ret + 1);
	}
	*/
	return (ret);
}



int	check_args(char * format)
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
