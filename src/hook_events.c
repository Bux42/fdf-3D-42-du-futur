/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 18:06:29 by videsvau          #+#    #+#             */
/*   Updated: 2017/10/27 18:14:07 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int			mouse_hook(int button, int x, int y, t_m *m)
{
	ft_putstr("Button:");
	ft_putnbr(button);
	ft_putstr(" x:");
	ft_putnbr(x);
	ft_putstr(" y:");
	ft_putnbr(y);
	ft_putchar(m->bpp);
	ft_putchar('\n');
	if (button == 6)
		m->roty++;
	if (button == 7)
		m->roty--;
	draw_points(m);
	return (0);
}

int			key_hook(int keycode, t_m *m)
{
	int		xyz[3];

	if (keycode > 122 && keycode < 127)
		rotate_matrice(keycode, m);
	if (keycode > 82 && keycode < 89)
		move_cursor(keycode, m);
	ft_putstr("\nKeycode:");
	ft_putnbr(keycode);
	ft_putchar('\n');
	if (keycode == 69 || keycode == 78 || keycode == 117 || keycode == 53)
		points_spacing(keycode, m);
	get_pos(m, xyz);
	if (keycode == 51)
		m->show_pos = 0;
	if (keycode == 1)
		m->new_ins = 1;
	if (keycode == 49)
	{
		m->show_pos = 1;
		m->curr_pos.z = xyz[0];
		m->curr_pos.x = xyz[1];
		m->curr_pos.y = xyz[2];
		m->curr_pos.pos = 0;
	}
	if (keycode == 75)
		if (m->shake > 0)
			m->shake--;
	if (keycode == 67)
		m->shake++;
	draw_points(m);
	if (keycode == 35)
		list_to_file(&m->ins);
	return (0);
}

int			expose_hook(t_m *m)
{
	ft_putendl("\tExpose Hook");
	draw_points(m);
	return (0);
}

int			loop_hook(t_m *m)
{
	mlx_hook(m->win, 2, (1L << 0), &key_hook, m);
	return (0);
}
