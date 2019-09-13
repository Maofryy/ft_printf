/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:49:41 by mbenhass          #+#    #+#             */
/*   Updated: 2019/09/09 17:51:56 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*read_fmt(t_flags fl)
{
	char *fmt[] = {"char", "char *", "void *", "int"};
	return (fmt[fl.fl_cv + 1]);
}

char	*print_char(char c)
{
	char *str;

	str = &c;
	str[1] = '\0';
	return (str);
}

char	*ret_str_float(t_flags fl, char *str, long double f)
{
	if (fl.fl_sc == 3)
		ft_dtoa((double)f, str, fl.fl_pr);
	else if (fl.fl_sc == 5)
		ft_dtoa((long double)f, str, fl.fl_pr);
	else if (fl.fl_sc == -1)
		ft_dtoa((float)f, str, fl.fl_pr);
	else
		return (NULL);//attention a retourner erreur et finir le prog si pas bon
				//mais de toute facon va y a voir la fonction check flags pour tout ca donc bon...
	return (str);
}

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

char	*print_arg(t_flags fl, char *str, va_list ap)
{
	if (fl.fl_cv == 1)//c: char
	{
		str = print_char((char)va_arg(ap, int));
		return (str);
	}
	else if (fl.fl_cv == 2)//s: string
	{
		str = (char *)va_arg(ap, char *);
		str[fl.fl_pr] = '\0'; //need to realloc	
		return (str);
	}
	else if (fl.fl_cv == 3)//p: pointer
	{	
		ft_ret_addr_str((void *)va_arg(ap, void *), str);
		return (str);
	}
	else if (fl.fl_cv == 4) //d: Int
	{
		free(str);
		str = ret_str_int(fl, str, (long long int)va_arg(ap, long long int));
		return (str);
	}
	else if (fl.fl_cv == 5) //o: Unsigned octal
	{
		free(str);
		str = ft_itoa_base((int)va_arg(ap, int), 8);
		return (str);
	}
	else if (fl.fl_cv == 6) //u: Unsigned decimal int
	{
		free(str);
		str = ft_itoa((unsigned int)va_arg(ap, unsigned int));
		return (str);
	}
	else if (fl.fl_cv == 7)//x: hexa lowercase
	{
		free(str);
		str = ft_itoa_base((unsigned int)va_arg(ap, unsigned int), 16);
		return (str);
	}
	else if (fl.fl_cv == 8)//x: hexa uppercase
	{
		free(str);
		str = ft_itoa_BASE((unsigned int)va_arg(ap, unsigned int), 16);
		return (str);
	}
	else if (fl.fl_cv == 9)//f: float need to malloc before or in the ftoa/dtoa function
	{
		free(str);
		str = ret_str_float(fl, str, va_arg(ap, double));
		return (str);
	}
	else
		return (NULL);
}

char	*check_int_pr(int pr, char *str)
{
	int i;

	i = ft_strlen(str);
	if (i < pr)
	{
		ft_reverse_str(str, i);
		while (i < pr)
			str[i++]='0';
		//add missing zeros
		ft_reverse_str(str, i);
	}
	str[i] = '\0';
	return (str);
}

char	*conv_arg(t_flags fl, va_list ap)
{
//	char	*fmt;

	//be careful and malloc correctly the void pointer
	//fmt = read_fmt(fl);
	//ft_putstr(print_arg(fl, ap));
	char *str;

	str = (char *)malloc(sizeof(char *)*30);
	str = print_arg(fl, str, ap);
	if (fl.fl_cv <= 8 || fl.fl_cv >= 4)
		str = check_int_pr(fl.fl_pr, str); 
	return (str);
}
