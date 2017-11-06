/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 19:40:55 by videsvau          #+#    #+#             */
/*   Updated: 2017/10/29 20:03:18 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

void		print_menu(t_m *m)
{
	char	*rotx;
	char	*roty;
	char	*rotz;

	rotx = ft_itoa(m->rotx);
	roty = ft_itoa(m->roty);
	rotz = ft_itoa(m->rotz);
	mlx_string_put(m->ptr, m->win, 10, 10, 0xFFFFFF, "Show points:");
	if (m->showdots == 1)
		mlx_string_put(m->ptr, m->win, 135, 10, 0x4ef442, "Yes");
	else
		mlx_string_put(m->ptr, m->win, 135, 10, 0x4ef442, "No");
	mlx_string_put(m->ptr, m->win, 10, 40, 0xFFFFFF, "Random Colors:");
	if (m->randcolor == 1)
		mlx_string_put(m->ptr, m->win, 155, 40, 0x4ef442, "No");
	else
		mlx_string_put(m->ptr, m->win, 155, 40, 0x4ef442, "Yes");
	mlx_string_put(m->ptr, m->win, 10, 70, 0xFFFFFF, "Rotation X:");
	mlx_string_put(m->ptr, m->win, 130, 70, 0xFFFFFF, rotx);
	mlx_string_put(m->ptr, m->win, 10, 100, 0xFFFFFF, "Rotation Y:");
	mlx_string_put(m->ptr, m->win, 130, 100, 0xFFFFFF, roty);
	mlx_string_put(m->ptr, m->win, 10, 130, 0xFFFFFF, "Rotation Z:");
	mlx_string_put(m->ptr, m->win, 130, 130, 0xFFFFFF, rotz);
	free(rotx);
}
