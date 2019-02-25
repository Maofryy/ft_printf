/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 09:53:23 by mbenhass          #+#    #+#             */
/*   Updated: 2019/02/20 09:53:21 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_format_flag(char c, t_flags *f)
{	
	const char str[] = "#0+- ";
	char *s;
	int		*p;

	p = &f->fl_sharp;

	s = ft_strchr(str, c);
	if (s == NULL)
		return (0);
	*(p + (int)(s - str)) = 1;
	return (1);
}

int		is_conv_flag(char *format, t_flags *f)
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

int		is_conv(char c, t_flags *f)
{
	const char str[] = "cspdouxXf";
	char *s;
	s = ft_strchr(str, c);
	if (s == NULL)
		return (0);
	if (c == 'i')
		f->fl_cv = 4;
	else
		f->fl_cv = s - str + 1;
	return (1);
}
