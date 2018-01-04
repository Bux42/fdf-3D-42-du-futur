/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 00:07:48 by videsvau          #+#    #+#             */
/*   Updated: 2017/12/05 16:45:13 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void		remove_last_line(t_ins **ins)
{
	t_ins	*cp;
	t_ins	*save;

	save = NULL;
	if (!(*ins))
		return ;
	cp = (*ins);
	while (cp->next)
	{
		if (cp->next->start)
			save = cp;
		cp = cp->next;
	}
	if (save)
	{
		free_list(&save->next);
		save->next = NULL;
	}
	else if (cp)
		free_list(ins);
}

void		free_list(t_ins **ins)
{
	t_ins	*cp;
	t_ins	*tmp;

	cp = (*ins);
	while (cp)
	{
		tmp = cp;
		cp = cp->next;
		free(tmp);
	}
	(*ins) = NULL;
	free((*ins));
}

t_ins		*create_ins(int x, int y, int z, int first)
{
	t_ins	*tmp;

	if (!(tmp = (t_ins*)malloc(sizeof(t_ins))))
		return (NULL);
	tmp->x = x;
	tmp->y = y;
	tmp->z = z;
	tmp->start = first;
	tmp->next = NULL;
	return (tmp);
}

void		ins_push_back(int first, t_ins **ins, int *xyz)
{
	t_ins	*tmp;

	ft_putnbr(first);
	tmp = (*ins);
	if (!tmp)
		(*ins) = create_ins(xyz[0], xyz[1], xyz[2], first);
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = create_ins(xyz[0], xyz[1], xyz[2], first);
	}
}
