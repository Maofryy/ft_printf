/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 09:33:55 by mbenhass          #+#    #+#             */
/*   Updated: 2019/09/09 15:54:55 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long double ft_fround(long double n)
{
	long double		fpart;
	long double		sep;
	long long	ipart;

	sep = 0.455555555555555;
	ipart =(long long)n;
	fpart = n - ipart;
	if (fpart > sep)
		ipart++;
	return ((long double)ipart);
}

void ft_reverse_str(char *str, int len) 
{ 
	int i;
	int j;
	int temp;

	i = 0;
	j = len-1;
	while (i<j) 
	{ 
		temp = str[i]; 
		str[i] = str[j]; 
		str[j] = temp; 
		i++; j--; 
	} 
} 
#include <stdio.h>
int	ft_ltoa_d(long long n, char *str, int d)
{
	int i;

	i = 0;
	if (n == 0)
		str[i++] = '0';
	while (n) 
	{ 
		str[i++] = (n%10) + '0'; 
		n = n/10; 
	}
	while (i < d) 
		str[i++] = '0'; //Ce char depends des flags, donc peut etre passer le char a la fonction en lisant les flags 0-+# 
	ft_reverse_str(str, i);
	str[i] = '\0';
	return i;
}

void	ft_ftoa(float n, char *str, int after)
{
	long long	ipart;
	float		fpart;
	int		i;

	if (after == -1)
		after = 6;
	ipart = (long long)n;
	fpart = n - (float)ipart;
	i = ft_ltoa_d(ipart, str, 0);
	ft_putstr(str);
	ft_putchar('\n'); 
	if (after != 0)
	{
		str[i] = '.';
		fpart = fpart * ft_power(10, after);	
		fpart = ft_fround(fpart);
		ft_ltoa_d((long long)fpart, str + i - 1, after);
	}
}

void	ft_dtoa(long double n, char *str, int after)
{
	long long	ipart;
	long double	fpart;
	int		i;

	if (after == -1)
		after = 6;
	ipart = (long long)n;
	fpart = n - (long double)ipart;
	i = ft_ltoa_d(ipart, str, 0);
	if (after != 0)
	{
		str[i] = '.';
		fpart = fpart * ft_power(10, after);
		fpart = ft_fround(fpart);
		ft_ltoa_d((long long)fpart, str + i + 1, after);
	}
}
