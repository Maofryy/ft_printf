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
	uintptr_t p = (uintptr_t)p0;
	
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
