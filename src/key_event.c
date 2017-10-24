/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 09:47:22 by videsvau          #+#    #+#             */
/*   Updated: 2017/10/24 09:49:57 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

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
