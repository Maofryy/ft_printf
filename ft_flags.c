/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:48:59 by mbenhass          #+#    #+#             */
/*   Updated: 2019/09/09 14:17:50 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		flags_init(void)
{
	t_flags	fl;
	int	*p;

	p = &fl.fl_sharp;
	while (p <= &fl.fl_cv_sign)
	{
		*p = -1;
		p++;
	}
	return (fl);
}

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

t_flags		read_flags(char ** p)
{
	t_flags fl;

	fl = flags_init();
	while (is_format_flag(**p, &fl))
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
	if (is_conv_flag((char *)*p, &fl))
		(*p)++;
	if (fl.fl_sc == 1 || fl.fl_sc == 4)
		(*p)++;
	if (is_conv(**p, &fl))
		(*p)++;
	return (fl);
}
