/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 07:00:16 by videsvau          #+#    #+#             */
/*   Updated: 2017/10/27 09:23:08 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void		allocate_matrice(t_m *m)
{
	int		i;
	int		j;

	i = -1;
	if (!(m->mat = (t_mat***)malloc(sizeof(t_mat**) * m->size)))
		return ;
	while (++i < m->size)
		if (!(m->mat[i] = (t_mat**)malloc(sizeof(t_mat*) * m->size)))
			return ;
	i = -1;
	while (++i < m->size)
	{
		j = -1;
		while (++j < m->size)
			if (!(m->mat[i][j] = (t_mat*)malloc(sizeof(t_mat) * m->size)))
				return ;
	}
	ft_putendl("\tMap Allocated.");
}

void		fill(t_m *m)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	while (++i < m->size)
	{
		j = -1;
		while (++j < m->size)
		{
			k = -1;
			while (++k < m->size)
			{
				m->mat[i][j][k].x = j * g_sp;
				m->mat[i][j][k].y = k * g_sp;
				m->mat[i][j][k].z = i * g_sp;
				m->mat[i][j][k].pos = 0;
			}
		}
	}
	m->mat[m->size / 2][m->size / 2][m->size / 2].pos = 1;
	ft_putendl("\tMap Filled");
}
