/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:23:26 by mbenhass          #+#    #+#             */
/*   Updated: 2019/09/16 12:21:03 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char * restrict format, ...)
{
	va_list ap;
	char 	*s;
	t_flags	fl;
	int	count;
	int ret;

	va_start(ap, format);
	count = 0;
	/*if (check_args(format) != )
	  return (die());*/
	while (*format)
	{
		if ((ret = get_to_arg((char **)&format)) == -1)
		{
			count += ft_strlen(format);
			ft_putstr((char *)format);
			return (count);
		}
		//ft_putstr(format);
		ft_putnstr((char *)format - ret - 1, ret);
		count += ret;
		if (!*format)
			break;
		fl = read_flags((char **)&format);
		//flags_print(fl);
		s = conv_arg(fl, ap);
		ft_putstr(s);
		count += ft_strlen(s);
	}
	va_end(ap);
	//free_all(&s, &fmt, &fl);
	return (count);
}
