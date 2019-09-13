/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 14:51:19 by mbenhass          #+#    #+#             */
/*   Updated: 2018/11/21 12:18:21 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_len(long long int n)
{
	long long int		i;
	size_t	len;

	i = n;
	len = 1;
	if (n < 0)
	{
		i = -n;
		len++;
	}
	while (i >= 10)
	{
		i /= 10;
		len++;
	}
	return (len);
}

static char		*ft_catnbr(char *str, long long int n)
{
	char c[2];

	c[0] = '0' + n % 10;
	c[1] = '\0';
	if (n >= 10)
	{
		str = ft_catnbr(str, n / 10);
		str = ft_strcat(str, c);
	}
	else
		str = ft_strcat(str, c);
	return (str);
}

char			*ft_lltoa(long long int n)
{
	char	*str;

	if ((str = ft_strnew(get_len(n))) == NULL)
		return (NULL);
	if (n == -2147483648)
		return (ft_strcat(ft_itoa(-2147), ft_itoa(483648)));
	if (n < 0)
	{
		str = ft_strcat(str, "-");
		n = -n;
	}
	return (ft_catnbr(str, n));
}
