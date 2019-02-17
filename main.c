/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:57:57 by mbenhass          #+#    #+#             */
/*   Updated: 2019/02/13 11:54:12 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

int ft_printf(const char * restrict format, ...)
{
	va_list ap;
	char 	*s;
	t_flags	fl;
	int	count;

	va_start(ap, format);
	count = 0;
	/*if (check_args(format) != )
		return (die());*/
	while (*format)
	{
		count += get_to_arg(&format);
		if (!*format)
			break;
		ft_putstr("continuing");
		fl = read_flags(&format);
		s = conv_arg(fl, ap);
		ft_putstr(s);
		count += ft_strlen(s);
	}
	//va_end(ap);
	//free_all(&s, &fmt, &fl);
	return (count);
}

int main(int ac, char **av) {
	(void)ac;
	(void)av;
	int i;

	//i = ft_printf("test : %d %d %d", 2, 3, 7);
	i = ft_printf("HeyHeyheyi ");

	return (0);
}
