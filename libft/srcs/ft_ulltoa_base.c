#include "libft.h"
#include <stdio.h>

static char	ft_base_char(int n)
{
	if (n < 10)
		return (n + '0');
	return (n - 10 + 'a');
}

static char	ft_BASE_char(int n)
{
	if (n < 10)
		return (n + '0');
	return (n - 10 + 'A');
}

char		*ft_ulltoa_base(unsigned long long n, int base)
{
	unsigned int	value;
	int				count;
	char			*str;

	if (base < 2 || base > 36)
		return (NULL);
	value = (n < 0) ? -n : n;
	count = (n == 0 || (n < 0 && base == 10));
	while (value != 0)
	{
		value /= base;
		count++;
	}
	if (!(str = (char *)malloc(sizeof(*str) * (count + 1))))
		return (NULL);
	str[count] = '\0';
	value = (n < 0) ? -n : n;
	while (--count > 0)
	{
		str[count] = ft_base_char(value % base);
		value /= base;
	}
	*str = (n < 0 && base == 10 ? '-' : ft_base_char(value));
	return (str);
}

char		*ft_ulltoa_BASE(unsigned long long n, int base)
{
	unsigned int	value;
	int				count;
	char			*str;
	printf("\n hey : %lu\n", (unsigned long)n);

	if (base < 2 || base > 36)
		return (NULL);
	value = (n < 0) ? -n : n;
	count = (n == 0 || (n < 0 && base == 10));
	while (value != 0)
	{
		value /= base;
		count++;
	}
	if (!(str = (char *)malloc(sizeof(*str) * (count + 1))))
		return (NULL);
	str[count] = '\0';
	value = (n < 0) ? -n : n;
	while (--count > 0)
	{
		str[count] = ft_BASE_char(value % base);
		value /= base;
	}
	*str = (n < 0 && base == 10 ? '-' : ft_BASE_char(value));
	return (str);
}

char		*ft_ulltoa(unsigned long long n)
{
	return (ft_ulltoa_base(n, 10));
}
