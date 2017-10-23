/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 06:50:10 by videsvau          #+#    #+#             */
/*   Updated: 2017/10/23 06:56:30 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void		draw_instructions(t_m *m, t_ins **ins)
{
	t_ins	*cp;
	t_l		line1;
	t_l		line2;

	cp = (*ins);
	while (cp)
	{
		if (cp->start)
			line1 = rotation(m->mat[cp->x][cp->y][cp->z], m);
		else
		{
			line2 = rotation(m->mat[cp->x][cp->y][cp->z], m);
			draw_line(line1, line2, m);
		}
		cp = cp->next;
	}
}

void		draw_points(t_m *m)
{
	int		i;
	int		j;
	int		k;
	t_l		line;

	i = -1;
	clean_img(m);
	degree_to_rad(m);
	get_center(m);
	while (++i < m->size)
	{
		j = -1;
		while (++j < m->size)
		{
			k = -1;
			while (++k < m->size)
			{
				line = rotation(m->mat[i][j][k], m);
				put_pixel(m, line.x, line.y, 0x444444);
			}
		}
	}
	draw_instructions(m, &m->ins);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
}