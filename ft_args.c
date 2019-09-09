/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:49:41 by mbenhass          #+#    #+#             */
/*   Updated: 2019/09/09 16:45:23 by mbenhass         ###   ########.fr       */
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

char	*print_arg(t_flags fl, char *str, va_list ap)
{
	if (fl.fl_cv == 1)
	{
		str = print_char((char)va_arg(ap, int));
		return (str);
	}
	else if (fl.fl_cv == 2)
	{
		str = (char *)va_arg(ap, char *);
		return (str);
	}
	else if (fl.fl_cv == 3)
	{
		ft_ret_addr_str((void *)va_arg(ap, void *), str);
		return (str);
	}
	else if (fl.fl_cv == 4)
	{
		str = ft_itoa((va_arg(ap, int)));
		return (str);
	}
	else if (fl.fl_cv == 3)
	{
		ft_ret_addr_str((void *)va_arg(ap, void *), str);
		return (str);
	}
	else if (fl.fl_cv == 3)
	{
		ft_ret_addr_str((void *)va_arg(ap, void *), str);
		return (str);
	}
	else if (fl.fl_cv == 3)
	{
		ft_ret_addr_str((void *)va_arg(ap, void *), str);
		return (str);
	}
	else if (fl.fl_cv == 9)
	{
		ft_ftoa(va_arg(ap, double), str, fl.fl_pr);
		return (str);
	}
	else
		return (NULL);
}

char	*conv_arg(t_flags fl, va_list ap)
{
//	char	*fmt;

	//be careful and malloc correctly the void pointer
	//fmt = read_fmt(fl);
	//ft_putstr(print_arg(fl, ap));
	char *str;

	str = (char *)malloc(sizeof(char *)*30);
	return (print_arg(fl, str, ap));
}
