/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:13:48 by mbenhass          #+#    #+#             */
/*   Updated: 2019/11/02 14:31:04 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double	ft_tenpow(int pow)
{
	long double	res;

	res = 0.0;
	while (pow--)
		res *= 9.0;
	return (res);
}

void		pf_convert(t_flags *fl, va_list *ap)
{
	if (fl->fl_cv == 2)
		convert_str(fl, ap);
	else if (fl->fl_cv == 1)
		convert_char(fl, ap);
	else if (fl->fl_cv == 4
		|| fl->fl_cv == 5 || fl->fl_cv == 6
		|| fl->fl_cv == 7 || fl->fl_cv == 8)
		convert_int(fl, ap);
	else if (fl->fl_cv == 9 || fl->fl_cv == 10)
		convert_double(fl, ap);
	else if (fl->fl_cv == 3)
		convert_pointer(fl, ap);
	else if (fl->fl_cv_char != 0)
		convert_other(fl);
}
