/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 09:47:22 by videsvau          #+#    #+#             */
/*   Updated: 2017/10/24 10:36:19 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void		points_spacing(int keycode, t_m *m)
{
	if (keycode == 69)
	{
		g_sp += 5;
		fill(m);
	}
	if (keycode == 78)
	{
		g_sp -= 5;
		fill(m);
	}
	if (keycode == 117)
		free_list(&m->ins);
	if (keycode == 53)
		exit(1);
}

void		rotate_matrice(int keycode, t_m *m)
{
	if (keycode == 126)
		m->rotx += 10;
	if (keycode == 125)
		m->rotx -= 10;
	if (keycode == 123)
		m->roty += 10;
	if (keycode == 124)
		m->roty -= 10;
	if (keycode == 116)
		m->rotz += 10;
	if (keycode == 121)
		m->rotz -= 10;
}

void		move_cursor(int keycode, t_m *m)
{
	if (keycode == 87)
		move_x(1, m);
	if (keycode == 84)
		move_x(-1, m);
	if (keycode == 83)
		move_y(-1, m);
	if (keycode == 85)
		move_y(1, m);
	if (keycode == 88)
		move_z(1, m);
	if (keycode == 86)
		move_z(-1, m);
}
