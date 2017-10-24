/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 01:56:31 by videsvau          #+#    #+#             */
/*   Updated: 2017/10/24 02:09:10 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void		get_pos(t_m *m, int *xyz)
{
	int		z;
	int		x;
	int		y;

	z = -1;
	while (++z < m->size)
	{
		x = -1;
		while (++x < m->size)
		{
			y = -1;
			while (++y < m->size)
			{
				if (m->mat[z][x][y].pos)
				{
					xyz[0] = z;
					xyz[1] = x;
					xyz[2] = y;
					break ;
				}
			}
		}
	}
}

void		move_z(int gap, t_m *m)
{
	int		xyz[3];

	get_pos(m, xyz);
	if (xyz[0] + gap > -1 && xyz[0] + gap < m->size)
	{
		m->mat[xyz[0]][xyz[1]][xyz[2]].pos = 0;
		m->mat[xyz[0] + gap][xyz[1]][xyz[2]].pos = 1;
	}
}

void		move_y(int gap, t_m *m)
{
	int		xyz[3];

	get_pos(m, xyz);
	if (xyz[2] + gap > -1 && xyz[2] + gap < m->size)
	{
		m->mat[xyz[0]][xyz[1]][xyz[2]].pos = 0;
		m->mat[xyz[0]][xyz[1]][xyz[2] + gap].pos = 1;
	}
}

void		move_x(int gap, t_m *m)
{
	int		xyz[3];

	get_pos(m, xyz);
	if (xyz[1] + gap > -1 && xyz[1] + gap < m->size)
	{
		m->mat[xyz[0]][xyz[1]][xyz[2]].pos = 0;
		m->mat[xyz[0]][xyz[1] + gap][xyz[2]].pos = 1;
	}
}
