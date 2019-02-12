#include "libft.h"

int		get_to_arg(const char ** restrict p)
{
	int i;

	i = 0;
	while (*p && *p != '%')
	{
		i++;
		p++;
	}
	return (i);
}

