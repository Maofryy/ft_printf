#include "libft.h"

t_flags		flags_init(void)
{
	t_flags	fl;
	int	*p;

	p = &fl.fl_sharp;
	while (p <= &fl.fl_cv)
	{
		*p = 0;
		p++;
	}
	return (fl);
}

#include <stdio.h>
void		flags_print(t_flags fl)
{
	int	*p;

	p = &fl.fl_sharp;
	while (p <= &fl.fl_cv)
	{
		printf("Character #%ld = %d \n", p - &fl.fl_sharp, *p);
		p++;
	}
}

t_flags		read_flags(const char * restrict * p)
{
	t_flags fl;

	fl = flags_init();
	while (is_format_flag(**p, &fl))
		(*p)++;
	if (IS_NUM((int)**p))
	{
		fl.fl_fw=ft_atoi(*p);
		while (IS_NUM((int)**p))
			(*p)++;
	}
	if (**p == '.')
	{
		(*p)++;
		fl.fl_pr=ft_atoi(*p);
		while (IS_NUM((int)**p))
			(*p)++;
	}
	if (is_conv_flag(*p, &fl))
		(*p)++;
	if (is_conv(**p, &fl))
		(*p)++;
	return (fl);
}
