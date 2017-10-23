/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 21:31:46 by videsvau          #+#    #+#             */
/*   Updated: 2017/10/23 02:26:59 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void		clean_img(t_m *m)
{
	int		i;
	int		j;

	i = -1;
	while (++i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
		{
			put_pixel(m, i, j , 0x000000);
		}
	}
}

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
			ft_putchar('1');
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
	int		color;
	t_l		line;

	i = -1;
	color = 0x444444;
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
				put_pixel(m, line.x, line.y, color);
			}
		}
	}
	draw_instructions(m, &m->ins);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
}

void		put_pixel(t_m *m, int x, int y, int color)
{
	if (x + 1 <= HEIGHT && y + 1 <= WIDTH && x >= 0 && y >= 0)
		*(unsigned *)(m->imga + m->sl * y + (m->bpp / 8) * x) = color;
}

void		init_bres(t_d *bres, t_l line1, t_l line2)
{
	bres->dx = abs(line2.x - line1.x);
	bres->dy = abs(line2.y - line1.y);
	bres->sx = line1.x < line2.x ? 1 : -1;
	bres->sy = line1.y < line2.y ? 1 : -1;
	bres->err = (bres->dx > bres->dy ? bres->dx : -bres->dy) / 2;
}

void		draw_line(t_l line1, t_l line2, t_m *m)
{
	init_bres(&m->bres, line1, line2);
	while (42)
	{
		put_pixel(m, line1.x, line1.y, 0xFFFFFF);
		if (line1.x == line2.x && line1.y == line2.y)
			break ;
		m->bres.e2 = m->bres.err;
		if (m->bres.e2 > -m->bres.dx)
		{
			m->bres.err -= m->bres.dy;
			line1.x += m->bres.sx;
		}
		if (m->bres.e2 < m->bres.dy)
		{
			m->bres.err += m->bres.dx;
			line1.y += m->bres.sy;
		}
	}
}
