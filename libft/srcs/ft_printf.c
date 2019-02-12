#include "libft.h"

int ft_printf(const char * restrict format, ...)
{
	va_list ap;
	char 	*s;
	char	*fmt;
	t_flags	fl;
	int	count;
	
	va_start(ap, format);
	count = 0;
	fl = flags_init();
	check_args(ap, format);
	while (*format)
	{
		count += get_to_arg(&format);
		fl = read_flags(&format);
		fmt = read_format(&format);
		s = conv_arg(fl, va_arg(ap, fmt));
		ft_putstr(s);
		count += ft_strlen(s);
	}
	va_end(ap);
	free_all(&s, &fmt, &fl);
	return (count);
}

//add a convert() same as atoi base

