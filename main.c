/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:57:57 by mbenhass          #+#    #+#             */
/*   Updated: 2019/09/09 17:29:42 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main(int ac, char **av) {
	(void)ac;
	(void)av;

	//float n = 233.123456789;
	//float sep = 3.32444;
	//char str[] = "Hey this is a string";

	//void *p = &str;
	//float sep = (float)4/9;
	//ft_dtoa(sep, str, 6);
	//printf("printf ret : %.12f\n", sep);

	ft_putstr(ft_itoa((unsigned char)'H'));
	/*printf("Hey try this char : %c\n", *str);
	printf("Hey try this string : %s\n", str);
	printf("Hey try this pointer : %p\n", p);
	printf("Hey try this int : %d\n", (int)sep);
	printf("Hey try this float : %f\n", sep);
	printf("Hey try this an unsigned octet : %o\n", *str);
	printf("Hey try this an unsigned int : %u\n", (unsigned int)sep);
	printf("Hey try this an unsigned hexa int : %x\n", (unsigned int)sep);
	printf("Hey try this an unsigned HEXA int  : %X\n", (unsigned int)sep);
	
	ft_printf("ft :Hey try this char : %c\n", *str);
	ft_printf("ft :Hey try this string : %s\n", str);
	ft_printf("ft :Hey try this pointer : %p\n", p);
	ft_printf("ft :Hey try this int : %d\n", (int)sep);
	ft_printf("ft :Hey try this float : %f\n", sep);
	ft_printf("ft :Hey try this an unsigned octet : %o\n", *str);
	ft_printf("ft :Hey try this an unsigned int : %u\n", (unsigned int)sep);
	ft_printf("ft :Hey try this an unsigned hexa int : %x\n", (unsigned int)sep);
	ft_printf("ft :Hey try this an unsigned HEXA int  : %X\n", (unsigned int)sep);
	*/
	
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
