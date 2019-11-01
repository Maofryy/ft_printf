/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:48:59 by mbenhass          #+#    #+#             */
/*   Updated: 2019/09/25 11:22:25 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		flags_init(t_flags *fl)
{
	int	*p;

	p = &fl->fl_sharp;
	while (p <= &fl->fl_err)
	{
		*p = -1;
		p++;
	}
}

/*
#include <stdio.h>
void		flags_print(t_flags fl)
{
	int	*p;

	p = &fl.fl_sharp;
	printf("\n");
	while (p <= &fl.fl_cv_sign)
	{
		printf("Character #%ld = %d \n", p - &fl.fl_sharp, *p);
		p++;
	}
}
*/
t_flags			flags_err(t_flags *fl)
{
	fl->fl_err = -1;
	return (*fl);
}

#include <stdio.h>

t_flags		read_flags(char ** p)
{
	t_flags fl;

	flags_init(&fl);
	if (**p == 0)
		return (flags_err(&fl));
	while (is_format_flag(p, &fl))
		(*p)++;
	if (IS_NUM((int)**p))
	{
		fl.fl_fw=ft_atoi(*p);
		while (IS_NUM((int)**p))
			(*p)++;
	}
	if (**p == '.')
	{
		(*p)++;
		fl.fl_pr=ft_atoi(*p);
		while (IS_NUM((int)**p))
			(*p)++;
	}
	if (is_conv_flag(p, &fl))
		(*p)++;
	if (fl.fl_sc == 1 || fl.fl_sc == 4)
		(*p)++;
	if (is_conv(p, &fl))
		(*p)++;
	return (fl);
}

int			flags_parse(t_flags *fl, const char *str)
{
	const char	*start;

	start = str;
	flags_init(fl);
	while (is_format_flag((char **)&str, fl)
		|| is_conv_flag((char **)&str, fl)
		|| is_width_field((char **)&str, fl)
		|| is_precision_flag((char **)&str, fl))
		continue ;
		// ft_putchar(*str);
	fl->fl_cv_char = *str;
	is_conv((char **)&str, fl);
	return (int)(str - start);
}
