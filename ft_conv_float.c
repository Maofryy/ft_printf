#include "ft_printf.h"

static long double	ft_tenpow(int pow)
{
	long double	res;

	res = 1.0;
	while (pow--)
		res *= 10.0;
	return (res);
}

static int			double_precision(t_flags *fl)
{
	char	*tmp;

	if (fl->fl_pr < 0)
		fl->fl_pr = 6;
	if (fl->fl_pr != 0)
	{
		if (!(tmp = (char *)malloc(fl->buf.size + fl->fl_pr + 1)))
			return (0);
		ft_memcpy(tmp, fl->buf.str, fl->buf.size);
		free(fl->buf.str);
		tmp[fl->buf.size] = '.';
		fl->buf.str = tmp;
		fl->buf.size += fl->fl_pr + 1;
	}
  else if (fl->fl_sharp == 1)
  {
    if (!(tmp = (char *)malloc(fl->buf.size + fl->fl_pr + 1)))
			return (0);
    ft_memcpy(tmp, fl->buf.str, fl->buf.size);
		free(fl->buf.str);
		tmp[fl->buf.size] = '.';
		fl->buf.str = tmp;
		fl->buf.size ++;
  }
	return (1);
}

static void	prepend_stuff(t_flags *fl, t_intstuff *vars)
{
	/*if (vars->neg)
		buf_prepend("-", &(fl->buf));
	else */if (fl->fl_plus == 1 && vars->neg == 0)
		buf_prepend("+", &(fl->buf));
	else if (fl->fl_space == 1)
    buf_prepend(" ", &(fl->buf));
  if (!(fl->buf.str))
		exit(1);
  if (fl->fl_fw > fl->buf.size)
  {
    if (fl->fl_zero == 1 && fl->fl_minus != 1)
      buf_pad(&(fl->buf), '0', fl->fl_fw, 0);
    else
      buf_pad(&(fl->buf), ' ', fl->fl_fw, fl->fl_minus == 1);
  }
  if (!(fl->buf.str))
    exit(1);
}

// Need to handle plus and space or minus shit flags
#include <stdio.h>
void				convert_double(t_flags *fl, va_list *ap)
{
	long double	value;
	int			i;
  t_intstuff vars;

  if (fl->fl_sc == 5)
    value = va_arg(*ap, long double);
  else
		value = va_arg(*ap, double);
  vars.neg = ((long long)value < 0) ? 1 : 0;
  vars.is_zero = fl->buf.size == 0
    || (fl->buf.size == 1 && (fl->buf.str)[0] == '0');
  if (!(fl->buf.str = ft_lltoa((long long)value)))
		exit(1);
  fl->buf.size = ft_strlen(fl->buf.str);
	if (!double_precision(fl))
		exit(1);
	value -= (long long)value;
	if (value < 0)
		value = -value;
	value *= ft_tenpow(fl->fl_pr + 1);
	if ((unsigned long long)value % 10 >= 5)
		value += 1;
	i = fl->buf.size;
	while (i > (fl->buf.size - fl->fl_pr))
	{
		value /= 10.0;
		(fl->buf.str)[i - 1] = (((unsigned long long)value % 10) + '0');
		i--;
	}
  prepend_stuff(fl, &vars);
}
