/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 13:40:46 by mbenhass          #+#    #+#             */
/*   Updated: 2019/09/25 10:36:39 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnstr(char * str, int n)
{
	int i;

	i = 0;
	while (i < n)
		ft_putchar(str[i++]);
}

int		ft_arg_error()
{
	ft_putstr("arg error");
	return (0);
}

int		get_to_arg(char ** p)
{
	char *s;
	int ret;

	s = ft_strchr(*p, '%');
	//ft_putnstr(*p, (int)(s - *p));
	//Handle the double %
	if (s + 1 == 0)
		return (ft_arg_error());
	if (s == NULL)
		return (-1);
	else if (s[1] == '%')
	{
		ft_putnstr(*p, (int)(s - *p + 1));
		*p = s + 2;
		return (get_to_arg(p) + 1);
	}
	else
	{
		ret = (int)(s - *p);
		*p = s + 1;
	}
	return (ret);
}



int	check_args(char * format)
{
	int ret;
	// Check if number of args is okay, use va_copy and count, cant do that with varidic function actually
	ret = 1;
	while (*format)
	{
		ret = get_to_arg(&format);
		ft_putstr("\nret = ");
		ft_putnbr(ret);
		ft_putchar('\n');
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
