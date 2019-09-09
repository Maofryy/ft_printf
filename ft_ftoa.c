/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 09:33:55 by mbenhass          #+#    #+#             */
/*   Updated: 2019/09/09 12:49:17 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

float ft_round(float n, int after)
{
	float	fpart;
	float	sep;
	int		ipart;

	sep = (float)4/9;
	ipart = (n - (int)n);
	fpart = ipart * ft_power(10, after);
	if ((fpart - (int)fpart) > sep)
		fpart++;
	return ((float)ipart + fpart*ft_dpower(10, -after));
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

int	ft_itoa_d(int n, char *str, int d)
{
	int i;

	i = 0; 
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
#include <stdio.h>
void	ft_dtoa(float n, char *str, int after)
{
	int		ipart;
	double	fpart;
	int		i;

	ipart = (int)n;
	fpart = n - (float)ipart;
	i = ft_itoa_d(ipart, str, 0);
	if (after != 0)
	{
		str[i] = '.';
		printf("fpart : %.15f\n", (float)4/9);
		printf("power : %ld\n", ft_power(10, after));
		fpart = fpart * ft_power(10, after);
		printf("fpart : %f\n", fpart);
		ft_itoa_d( (int)fpart, str + i + 1, after);
	}
}
