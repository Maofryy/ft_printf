/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 16:57:57 by mbenhass          #+#    #+#             */
/*   Updated: 2019/02/05 14:00:40 by mbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

int main(int ac, char **av) {
	(void)ac;
	(void)av;
	t_flags fl;
	fl = flags_init();
	flags_print(fl);
	fl.fl_sharp = 1;
	ft_putchar('\n');
	flags_print(fl);

	return (0);
}

