/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:57:57 by mbenhass          #+#    #+#             */
/*   Updated: 2019/09/09 12:24:20 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main(int ac, char **av) {
	(void)ac;
	(void)av;
	int i;

	char str[30];
	//float n = 233.123456789;
	float sep = (float)22/9;
	//float sep2 = (float)4/9;
	ft_dtoa(sep, str, 6);
	//printf("printf ret : %.12f\n", sep);
	i = ft_printf("Hey try this float : %#4.4s\n", "$float");
	
	//printf("%f", ft_fpower((float)10,-4));
	
	//i = ft_printf("0123%s%c%d","456", '7', 89);
	//ft_printf("This is %d int\n%%\n", 1);
	/*if (ac == 1)
		i = ft_printf("Insert a format and arg to print");
	else if (ac == 2)
		i = ft_printf(av[1]);
	else if (ac == 3)
		i = ft_printf(av[1], av[2]);
	else if (ac == 4)
		i = ft_printf(av[1], av[2], av[3]);
	else if (ac == 5)
		i = ft_printf(av[1], av[2], av[3], av[4]);
	else
		i = 0;*/
	return (0);
}
