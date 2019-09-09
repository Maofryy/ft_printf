/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:49:41 by mbenhass          #+#    #+#             */
/*   Updated: 2019/09/09 12:49:45 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*read_fmt(t_flags fl)
{
	char *fmt[] = {"char", "char *", "void *", "int"};
	return (fmt[fl.fl_cv + 1]);
}

char	*print_char(char c)
{
	char *str;

	str = &c;
	str[1] = '\0';
	return (str);
}

char	*print_arg(t_flags fl, va_list ap)
{
	if (fl.fl_cv == 1)
		return (print_char((char)va_arg(ap, int)));
	else if (fl.fl_cv == 2)
		return (va_arg(ap, char *));
	else if (fl.fl_cv == 3)
		return ((char *)va_arg(ap, void *));
	else if (fl.fl_cv == 4)
		return (ft_itoa((va_arg(ap, int))));
	else
		return (NULL);
}

char	*conv_arg(t_flags fl, va_list ap)
{
//	char	*fmt;

	//be careful and malloc correctly the void pointer
	//fmt = read_fmt(fl);
	//ft_putstr(print_arg(fl, ap));
	return (print_arg(fl, ap));
}
