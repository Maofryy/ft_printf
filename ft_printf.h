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
# define STR_CONV "cspdouxXfF"
# define STR_FLAGS "#0+- "
# define BUFFER_SIZE 1024

typedef struct	s_buf
{
	char	*str;
	int	size;
	int pos;
}		t_buf;

typedef struct	s_intstuff
{
	int			neg;
	int			is_zero;
	int			can_expand;
	int			offset;
}				t_intstuff;

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
	t_buf buf;

}				t_flags;

int			ft_gprintf(const char *format, ...);
int			ft_printf(const char * restrict format, ...);
int			read_format(t_buf *pbuf, const char *str, va_list ap);
void		expand_buf(t_buf *pbuf);
int			flags_parse(t_flags *fl, const char *str);
void			flags_init(t_flags *fl);
void			flags_print(t_flags fl); //to remove

int			check_args(char * format);
int			get_to_arg(char **p);
int			is_format_flag(char **pstr, t_flags *fl);
int			is_conv_flag(char **pstr, t_flags *fl);
int		is_precision_flag(char **pstr, t_flags *fl);
int 	is_width_field(char **pstr, t_flags *fl);
int			is_conv(char **pstr, t_flags *fl);
char			*read_fmt(t_flags fl);
char			*print_args(t_flags fl, va_list ap);
char			*conv_arg(t_flags pl, va_list ap);


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

void		convert_str(t_flags *fl, va_list *ap);
void		convert_char(t_flags *fl, va_list *ap);
void pf_convert(t_flags *fl, va_list *ap);
char	pad_byte(t_flags *fl);
void	buf_pad(t_buf *buf, char pad, int width, int right_pad);
void	buf_prepend(char *s1, t_buf *buf);

int	wide_bytes_count(wint_t c);
int	wide_valid(wint_t c);
int	convert_wide_c(char *dst, wint_t c);
int	convert_wide_str(char *dst, wchar_t *str);
void	convert_other(t_flags *fl);
void	convert_pointer(t_flags *fl, va_list *ap);
void				convert_double(t_flags *fl, va_list *ap);
void		convert_int(t_flags *fl, va_list *ap);
int							intval_to_buf(t_flags *fl, va_list *ap);


int ft_positive_atoi(char **str);

#endif
