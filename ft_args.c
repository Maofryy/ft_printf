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
		str = ret_str_uchar(fl, str, (unsigned long long)va_arg(ap, unsigned int));
		return (str);
	}
	else if (fl.fl_cv == 6) //u: Unsigned decimal int
	{
		free(str);
		str = ret_str_uint(fl, str, (unsigned long long)va_arg(ap, \
unsigned int));
		return (str);
	}
	else if (fl.fl_cv == 7)//x: hexa lowercase
	{
		free(str);
		str = ret_str_xint(fl, str, (unsigned long long)va_arg(ap, unsigned int));
		return (str);
	}
	else if (fl.fl_cv == 8)//x: hexa uppercase
	{
		free(str);
		str = ret_str_Xint(fl, str, (unsigned long long)va_arg(ap, unsigned int));
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

char	*check_fieldwidth(t_flags fl, char *str)
{
	int i;
	char c;

	i = ft_strlen(str);
	c = ' ';
	if (i < fl.fl_fw)
	{
		if (fl.fl_minus != 1)
			ft_reverse_str(str, i);
		if (fl.fl_zero == 1 && fl.fl_minus != 1)
			c = '0';
		while (i < fl.fl_fw)
			str[i++]=c;
		//add missing zeros
		if (fl.fl_minus != 1)
			ft_reverse_str(str, i);
	}
	str[i] = '\0';
	return (str);
}

char	*process_sharp(t_flags fl, char *str)
{
	int i;

	i = ft_strlen(str);
	if (fl.fl_cv == 5 && str[0] != '0')
	{
		ft_reverse_str(str, i);
		str[i++]='0';
		ft_reverse_str(str, i);
		str[i] = '\0';
	}
	else if (fl.fl_cv == 9 && fl.fl_pr == 0)
	{
		str[i] = '.';
		str[i + 1] = '\0';
	}
	else if (fl.fl_cv == 7 || fl.fl_cv == 8)
	{
		ft_reverse_str(str, i);
		if (fl.fl_cv == 7)
			str[i++] = 'x';
		else
			str[i++] = 'X';
		str[i++] = '0';
		ft_reverse_str(str, i);
		str[i]='\0';
	}
	return (str);
}

char	*process_sign_flags(t_flags fl, char *str)
{
	int i;

	i = ft_strlen(str);
	if (fl.fl_plus == 1)
	{
		if (fl.fl_cv_sign == 1)
		{
			ft_reverse_str(str, i);
			str[i++]='+';
			ft_reverse_str(str, i);
			str[i++]='\0';
		}
	}
	return (str);
}

char	*conv_arg(t_flags fl, va_list ap)
{
//	char	*fmt;

	//be careful and malloc correctly the void pointer
	//fmt = read_fmt(fl);
	//ft_putstr(print_arg(fl, ap));
	char	*str;

	str = (char *)malloc(sizeof(char *)*30);
	str = print_arg(fl, str, ap);
	if (fl.fl_cv <= 8 || fl.fl_cv >= 4)
		str = check_int_pr(fl.fl_pr, str);
	if (str[0] != '-')
		fl.fl_cv_sign = 1;
	str = check_fieldwidth(fl, str);
	if (fl.fl_sharp == 1)
		str = process_sharp(fl, str);
	str = process_sign_flags(fl, str);
	return (str);
}
