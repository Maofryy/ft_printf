/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:57:57 by mbenhass          #+#    #+#             */
/*   Updated: 2019/09/09 17:52:58 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main(int ac, char **av) {
	(void)ac;
	(void)av;

	int n = 775805;
	float sep = 9147483.647;
	//char str[] = "Hey this is a string";

	//void *p = &str;
	//float sep = (float)4/9;
	//ft_dtoa(sep, str, 6);
	
	/*//------------BONUS TEST--------------------
	printf("Does this work : \033[0;32m%s\033[0m ?\n", "test");*/
	/* //------------IDENTIFIER TEST------------
	printf("Hey try this char : %c\n", *str);
	printf("Hey try this string : %s\n", str);
	printf("Hey try this pointer : %p\n", p);
	printf("Hey try this int : %d\n", (int)sep);
	printf("Hey try this float : %f\n", sep);
	printf("Hey try this an unsigned octet : %o\n", *str);
	printf("Hey try this an unsigned int : %u\n", (unsigned int)n);
	printf("Hey try this an unsigned hexa int : %x\n", (unsigned int)n);
	printf("Hey try this an unsigned HEXA int  : %X\n", (unsigned int)n);

	ft_printf("ft :Hey try this char : %c\n", *str);
	ft_printf("ft :Hey try this string : %s\n", str);
	ft_printf("ft :Hey try this pointer : %p\n", p);
	ft_printf("ft :Hey try this int : %d\n", (int)sep);
	ft_printf("ft :Hey try this float : %f\n", sep);
	ft_printf("ft :Hey try this an unsigned octet : %o\n", *str);
	ft_printf("ft :Hey try this an unsigned int : %u\n", (unsigned int)n);
	ft_printf("ft :Hey try this an unsigned hexa int : %x\n", (unsigned int)n);
	ft_printf("ft :Hey try this an unsigned HEXA int  : %X\n", (unsigned int)n);
	*/

	//---------------LENGTH TEST--------------	
	/*
	//printf("pr :Hey try this int : %d\n", (int)n);
	//printf("pr :Hey try this int : %hhd\n", (char)n);
	//ft_printf("ft :Hey try this int : %d\n", (int)n);
	printf("rl :Hey try this char size int : %hhd\n", (char)n);
	printf("rl :Hey try this int size int : %hd\n", (short int)n);
	printf("rl :Hey try this long size int : %ld\n", (long int)n);
	printf("rl :Hey try this long long size int : %lld\n", (long long int)n);
	printf("rl :Hey try this float : %f\n", (float)sep);
	printf("rl :Hey try this double size float : %lf\n", (double)sep);
	printf("rl :Hey try this long double size float : %Lf\n", (long double)sep);

	ft_printf("ft :Hey try this char size int : %hhd\n", (char)n);
	ft_printf("ft :Hey try this int size int : %hd\n", (short int)n);
	ft_printf("ft :Hey try this long size int : %ld\n", (long int)n);
	ft_printf("ft :Hey try this long long size int : %lld\n", (long long int)n);
	ft_printf("ft :Hey try this float : %f\n", (float)sep);
	ft_printf("ft :Hey try this double size float : %lf\n", (double)sep);
	ft_printf("ft :Hey try this long double size float : %Lf\n", (long double)sep);
	*/	

	//-----------------PRECISION TESTS-------------------------------
	/*
	printf("rl :Hey try this int : %d\n", n);
	printf("rl :Hey try this int with pr 15 : %.15d\n", n);
	printf("rl :Hey try this hexa int with pr 15 : %.15X\n", (unsigned)n);
	printf("rl :Hey try this string with pr 5 : %.5s\n", str);
	printf("rl :Hey try this float with pr 0 : %.f\n", sep);
	printf("rl :Hey try this float with pr 9 : %.9f\n", sep);

	ft_printf("ft :Hey try this int : %d\n", n);
	ft_printf("ft :Hey try this int with pr 15 : %.15d\n", n);
	ft_printf("ft :Hey try this hexa int with pr 15 : %.15X\n", (unsigned)n);
	ft_printf("ft :Hey try this string with pr 5 : %.5s\n", str);
	ft_printf("ft :Hey try this float with pr 0 : %.f\n", sep);
	ft_printf("ft :Hey try this float with pr 9 : %.9f\n", sep);
	*/	

	//-------------------WIDTH TESTS------------------------------------
	/*
	printf("rl :Hey try this float with fw 9 : %9d\n", n);
	printf("rl :Hey try this float with fw 9 - : %-9d\n", n);
	printf("rl :Hey try this float with fw 9 0 : %09d\n", n);
	printf("rl :Hey try this float with fw 3 0 : %03d\n", n);
	printf("rl :Hey try this float with fw 3 : %3d\n", n);
	ft_printf("ft :Hey try this float with fw 9 : %9d\n", n);
	ft_printf("ft :Hey try this float with fw 9 - : %-9d\n", n);
	ft_printf("ft :Hey try this float with fw 9 0 : %09d\n", n);
	ft_printf("ft :Hey try this float with fw 3 0 : %03d\n", n);
	ft_printf("ft :Hey try this float with fw 3 : %3d\n", n);
	*/

	//------------------FLAGS TESTS------------------------------

	printf("rl :Hey try this octal char : %#0o\n", (unsigned char)n);
	printf("rl :Hey try this lower hexa : %#x\n", (unsigned int)n);
	printf("rl :Hey try this upper hexa : %#X\n", (unsigned int)n);
	printf("rl :Hey try this float : %#.f\n", sep);
	ft_printf("ft :Hey try this octal char : %#0o\n", (unsigned char)n);
	ft_printf("ft :Hey try this lower hexa : %#x\n", (unsigned int)n);
	ft_printf("ft :Hey try this upper hexa : %#X\n", (unsigned int)n);
	ft_printf("ft :Hey try this float : %#.f\n", sep);
	
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
