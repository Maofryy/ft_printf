/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 13:40:46 by mbenhass          #+#    #+#             */
/*   Updated: 2019/08/26 14:29:35 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "libft.h"

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
	ft_putnstr(*p, (int)(s - *p));
	ft_putstr("\nDebug1\n");
	//Handle the double %
	if (s[1] == '%')
	{
		//ft_putnstr(*p, (int)(*p - s));
		*p = s + 2;
		return (get_to_arg(p));
	}
	if (s == NULL)
		return (0);
	else
	{
		ret = (int)(s - *p);
		*p = s;
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
