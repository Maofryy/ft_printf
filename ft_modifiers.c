#include "ft_printf.h"
#include <stdio.h>

char	*ret_str_int(t_flags fl, char *str, long long int n)
{
	if (fl.fl_sc == 1)
		str = ft_itoa((char)n);
	else if (fl.fl_sc == 2)
		str = ft_itoa((short int)n);
	else if (fl.fl_sc == 3)
		str = ft_lltoa((long int)n);
	else if (fl.fl_sc == 4)
		str = ft_lltoa((long long int)n);
	else if (fl.fl_sc == -1)
		str = ft_itoa((int)n);
	else
		return (NULL);//return erreur plutot mais bon, to fix later
	return (str);
}

char	*ret_str_Xint(t_flags fl, char *str, unsigned long long int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	if (fl.fl_sc == 1)
		str = ft_ulltoa_BASE((unsigned char)n, 16);
	else if (fl.fl_sc == 2)
		str = ft_ulltoa_BASE((unsigned short int)n, 16);
	else if (fl.fl_sc == 3)
		str = ft_ulltoa_BASE((unsigned long int)n, 16);
	else if (fl.fl_sc == 4)
		str = ft_ulltoa_BASE((unsigned long long int)n, 16);
	else if (fl.fl_sc == -1)
		str = ft_ulltoa_BASE((unsigned int)n, 16);
	else
		return (NULL);//return erreur plutot mais bon, to fix later
	return (str);
}

char	*ret_str_xint(t_flags fl, char *str, unsigned long long int n)
{
	//if (n == 0)
	//	return (NULL);
	if (fl.fl_sc == 1)
		str = ft_ulltoa_base((unsigned char)n, 16);
	else if (fl.fl_sc == 2)
		str = ft_ulltoa_base((unsigned short int)n, 16);
	else if (fl.fl_sc == 3)
		str = ft_ulltoa_base((unsigned long int)n, 16);
	else if (fl.fl_sc == 4)
		str = ft_ulltoa_base((unsigned long long int)n, 16);
	else if (fl.fl_sc == -1)
		str = ft_ulltoa_base((unsigned int)n, 16);
	else
		return (NULL);//return erreur plutot mais bon, to fix later
	return (str);
}

char	*ret_str_uchar(t_flags fl, char *str, unsigned long long n)
{
	if (fl.fl_sc == 1)
		str = ft_ulltoa_base((unsigned char)n, 8);
	else if (fl.fl_sc == 2)
		str = ft_ulltoa_base((unsigned short int)n, 8);
	else if (fl.fl_sc == 3)
		str = ft_ulltoa_base((unsigned long int)n, 8);
	else if (fl.fl_sc == 4)
		str = ft_ulltoa_base((unsigned long long int)n, 8);
	else if (fl.fl_sc == -1)
		str = ft_ulltoa_base((unsigned int)n, 8);
	else
		return (NULL);//return erreur plutot mais bon, to fix later
	return (str);
}

char	*ret_str_uint(t_flags fl, char *str, unsigned long long int n)
{
	if (n == 0)	
		return (NULL);
	if (fl.fl_sc == 1)
		str = ft_ulltoa((unsigned char)n);
	else if (fl.fl_sc == 2)
		str = ft_ulltoa((unsigned short int)n);
	else if (fl.fl_sc == 3)
		str = ft_ulltoa((unsigned long int)n);
	else if (fl.fl_sc == 4)
		str = ft_ulltoa((unsigned long long int)n);
	else if (fl.fl_sc == -1)
		str = ft_ulltoa((unsigned int)n);
	else
		return (NULL);//return erreur plutot mais bon, to fix later
	return (str);
}
