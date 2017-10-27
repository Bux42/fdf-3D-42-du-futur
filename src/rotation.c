/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 20:22:12 by videsvau          #+#    #+#             */
/*   Updated: 2017/10/27 09:27:12 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

t_l			rotation2(t_mat mat, t_m *m)
{
	t_l		line;

	line.x = mat.x;
	line.y = mat.y * cos(m->endx) + mat.z * -sin(m->endx);
	line.z = mat.y * sin(m->endx) + mat.z * cos(m->endx);
	line.x1 = line.x * cos(m->endy) + line.z * sin(m->endy);
	line.y1 = line.y;
	line.z1 = line.x * -sin(m->endy) + line.z * cos(m->endy);
	line.x = line.x1 * cos(m->endz) + line.y1 * -sin(m->endz);
	line.y = line.x1 * sin(m->endz) + line.y1 * cos(m->endz);
	line.z = line.z1;
	return (line);
}

void		get_center(t_m *m)
{
	int		center;
	t_mat	cp;
	t_l		line;

	center = m->size / 2;
	cp.x = m->mat[center][center][center].x;
	cp.y = m->mat[center][center][center].y;
	cp.z = m->mat[center][center][center].z;
	line = rotation2(cp, m);
	m->decx = (HEIGHT / 2) - line.x;
	m->decy = (WIDTH / 2) - line.y;
}

void		degree_to_rad(t_m *m)
{
	float	pi;

	pi = 3.1416;
	m->endx = m->rotx * (pi / 180);
	m->endy = m->roty * (pi / 180);
	m->endz = m->rotz * (pi / 180);
}

t_l			rotation(t_mat mat, t_m *m)
{
	t_l		line;

	line.x = mat.x;
	line.y = mat.y * cos(m->endx) + mat.z * -sin(m->endx);
	line.z = mat.y * sin(m->endx) + mat.z * cos(m->endx);
	line.x1 = line.x * cos(m->endy) + line.z * sin(m->endy);
	line.y1 = line.y;
	line.z1 = line.x * -sin(m->endy) + line.z * cos(m->endy);
	line.x = line.x1 * cos(m->endz) + line.y1 * -sin(m->endz);
	line.y = line.x1 * sin(m->endz) + line.y1 * cos(m->endz);
	line.z = line.z1;
	line.x += m->decx;
	line.y += m->decy;
	return (line);
}
