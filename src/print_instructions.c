/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 06:50:10 by videsvau          #+#    #+#             */
/*   Updated: 2017/10/24 13:20:49 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void		draw_instructions(t_m *m, t_ins **ins)
{
	t_ins	*cp;
	t_l		line1;
	t_l		line2;
	int		xyz[3];

	get_pos(m, xyz);
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
	if (m->show_pos)
	{
		line1 = rotation(m->mat[xyz[0]][xyz[1]][xyz[2]], m);
		line2 = rotation(m->mat[m->curr_pos.z][m->curr_pos.x][m->curr_pos.y], m);
		draw_line(line1, line2, m);
		if (m->new_ins)
		{
			ins_push_back(1, &m->ins, xyz);
			xyz[0] = m->curr_pos.z;
			xyz[1] = m->curr_pos.x;
			xyz[2] = m->curr_pos.y;
			ins_push_back(0, &m->ins, xyz);
			m->new_ins = 0;
		}
	}
}

void		draw_points(t_m *m)
{
	int		i;
	int		j;
	int		k;
	t_l		line;

	gettimeofday(&g_time, NULL);
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
				if (m->mat[i][j][k].pos)
				{
					put_pixel(m, line.x + 1, line.y, 0x50f442);
					put_pixel(m, line.x - 1, line.y, 0x50f442);
					put_pixel(m, line.x, line.y + 1, 0x50f442);
					put_pixel(m, line.x, line.y - 1, 0x50f442);
				}
			}
		}
	}
	draw_instructions(m, &m->ins);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	gettimeofday(&g_time2, NULL);
	ft_putchar('\t');
	ft_putnbr(g_time2.tv_usec - g_time.tv_usec);
	ft_putchar('\n');
}
