/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 12:49:09 by videsvau          #+#    #+#             */
/*   Updated: 2017/10/24 12:54:26 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void		list_to_file(t_ins **ins)
{
	t_ins	*cp;

	cp = (*ins);
	while (cp)
	{
		if (cp->start)
			ft_putchar('\n');
		ft_putchar('[');
		ft_putnbr(cp->z);
		ft_putchar(',');
		ft_putnbr(cp->x);
		ft_putchar(',');
		ft_putnbr(cp->y);
		ft_putchar(']');
		if (cp->start)
			ft_putstr("=>");
		cp = cp->next;
	}
}
