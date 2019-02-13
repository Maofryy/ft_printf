/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 09:53:23 by mbenhass          #+#    #+#             */
/*   Updated: 2019/02/13 11:02:19 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_format_flag(const char c, t_flags *f)
{
	if (c == '#')
		f->fl_sharp = 1;
	else if (c == '0')
		f->fl_zero = 1;
	else if (c == '+')
		f->fl_plus = 1;
	else if (c == '-')
		f->fl_minus = 1;
	else if (c == ' ')
		f->fl_space = 1;
	else
		return (0);
	return (1);
}

int		is_conv_flag(const char *restrict format, t_flags *f)
{
	if (*format == 'h')
	{
		if (*(format + 1) == 'h')
			f->fl_sc = 1;
		else
			f->fl_sc = 2;
	}
	else if (*format == 'l')
	{
		if (*(format + 1) == 'l')
			f->fl_sc = 4;
		else
			f->fl_sc = 3;
	}
	else if (*format == 'L')
		f->fl_sc = 5;
	else
		return (0);
	return (1);
}

int		is_conv(const char c, t_flags *f)
{
	if (c == 'c')
		f->fl_cv = 1;
	else if (c == 's')
		f->fl_cv = 2;
	else if (c == 'p')
		f->fl_cv = 3;
	else if (c == 'f')
		f->fl_cv = 4;
	else if (c == 'd')
		f->fl_cv = 5;
	else if (c == 'i')
		f->fl_cv = 6;
	else if (c == 'o')
		f->fl_cv = 7;
	else if (c == 'u')
		f->fl_cv = 8;
	else if (c == 'x')
		f->fl_cv = 9;
	else if (c == 'X')
		f->fl_cv = 10;
	else
		return (0);
	return (1);
}
