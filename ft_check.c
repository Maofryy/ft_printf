/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 13:40:46 by mbenhass          #+#    #+#             */
/*   Updated: 2019/09/09 12:48:48 by mbenhass         ###   ########.fr       */
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

int		get_to_arg(char ** p)
{
	char *s;
	int ret;

	s = ft_strchr(*p, '%');
	//ft_putnstr(*p, (int)(s - *p));
	//Handle the double %
	if (s == NULL)
		return (-1);
	else if (s[1] == '%')
	{
		ft_putnstr(*p, (int)(s - *p + 1));
		*p = s + 2;
		return (get_to_arg(p));
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
