/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 12:21:15 by mbenhass          #+#    #+#             */
/*   Updated: 2019/02/04 15:01:22 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		die(char **line)
{
	if (!**line)
	{
		ft_strdel(line);
		return (0);
	}
	else
		return (1);
}

int				get_next_line(const int fd, char **line)
{
	static char	str[4096][BUFF_SIZE + 1];
	char		*buf;
	char		*cur;
	int			ret;

	buf = str[fd];
	if (fd < 0 || read(fd, buf, 0) < 0 || !line)
		return (-1);
	*line = ft_strnew(0);
	while (TRUE)
	{
		if ((cur = ft_strchr(buf, 10)))
		{
			*line = ft_strnjoinfree(*line, buf, cur - buf);
			ft_strncpy(buf, &buf[cur - buf + 1], BUFF_SIZE - (cur - buf));
			return (1);
		}
		*line = ft_strnjoinfree(*line, buf, BUFF_SIZE);
		ret = read(fd, str[fd], BUFF_SIZE);
		buf[ret] = '\0';
		if (!ret)
			return (die(line));
	}
}
