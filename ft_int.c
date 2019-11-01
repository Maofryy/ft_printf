#include "ft_printf.h"

int ft_positive_atoi(char **pstr)
{
  int ret;

  ret = 0;
  while ((*pstr)[0] >= '0' && (*pstr)[0] <= '9')
	{
		ret *= 10;
		ret += ((*pstr)[0] - '0');
		(*pstr)++;
	}
  return (ret);
}
