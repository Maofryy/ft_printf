/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:27:03 by mbenhass          #+#    #+#             */
/*   Updated: 2019/09/25 10:39:45 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include "libft/includes/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdarg.h>
# define IS_NUM(x) (x >= '0' && x <= '9')
# define STR_CONV "cspdouxXf"
# define STR_FLAGS "#0+- "

typedef struct	s_flags
{
	int	fl_sharp;
	int	fl_zero;
	int	fl_plus;
	int	fl_minus;
	int	fl_space;
	int	fl_fw;
	int	fl_pr;
	int	fl_sc;
	int	fl_cv;
	int	fl_cv_sign;
	int	fl_err;
}				t_flags;

int			ft_printf(const char * restrict format, ...);
int			check_args(char * format);
int			get_to_arg(char **p);
int			is_format_flag(char c, t_flags *f);
int			is_conv_flag(char * format, t_flags *f);
int			is_conv(char c, t_flags *f);
char			*read_fmt(t_flags fl);
char			*print_args(t_flags fl, va_list ap);
char			*conv_arg(t_flags pl, va_list ap);
t_flags			flags_init(void);
t_flags			read_flags(char ** p);
void			flags_print(t_flags fl);
void			ft_putnstr(char *str, int n);
void			ft_ftoa(float n, char *str, int after);
void			ft_dtoa(long double n, char *str, int after);
void			ft_ret_addr_str(void *p, char *str);
void			ft_reverse_str(char *str, int len);

char			*ret_str_int(t_flags fl, char *str, long long int n);
char			*ret_str_uint(t_flags fl, char *str, unsigned long long n);
char			*ret_str_uchar(t_flags fl, char *str, unsigned long long n);
char			*ret_str_xint(t_flags fl, char *str, unsigned long long n);
char			*ret_str_Xint(t_flags fl, char *str, unsigned long long n);


#endif
