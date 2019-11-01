/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:13:48 by mbenhass          #+#    #+#             */
/*   Updated: 2019/09/09 16:42:21 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char hex_digit(int v) {
	if (v >= 0 && v < 10)
		return '0' + v;
	else
		return 'a' + v - 10; // <-- Here
}

void ft_ret_addr_str(void* p0, char *str)
{
	int i;
	intptr_t p = (intptr_t)p0;

	*(str++)='0';
	*(str++) = 'x';
	i = (sizeof(p) << 3) - 4;
	while ((hex_digit((p >> i) & 0xf) == '0'))
		i -= 4;
	while (i >= 0)
	{
		*(str++) = (hex_digit((p >> i) & 0xf));
		i -= 4;
	}
}

void pf_convert(t_flags *fl, va_list *ap)
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
