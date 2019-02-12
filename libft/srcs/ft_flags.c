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
