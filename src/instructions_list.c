/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 00:07:48 by videsvau          #+#    #+#             */
/*   Updated: 2017/10/23 02:25:56 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

t_ins		*create_ins(int x, int y, int z, int first)
{
	t_ins	*tmp;

	if (!(tmp = (t_ins*)malloc(sizeof(t_ins))))
		return (NULL);
	tmp->x = x;
	tmp->y = y;
	ft_putstr("x: ");ft_putnbr(x);ft_putstr(" y:");ft_putnbr(y);ft_putstr(" z:");ft_putnbr(z);ft_putchar('\n');
	tmp->z = z;
	tmp->start = first;
	tmp->next = NULL;
	return (tmp);
}

void		ins_push_back(int first, t_ins **ins, int *xyz)
{
	t_ins	*tmp;

	tmp = (*ins);
	if (!tmp)
	{
		ft_putendl("Begining of the chain");
		(*ins) = create_ins(xyz[0], xyz[1], xyz[2], first);
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = create_ins(xyz[0], xyz[1], xyz[2], first);
	}
}
