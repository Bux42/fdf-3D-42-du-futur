/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 20:14:19 by videsvau          #+#    #+#             */
/*   Updated: 2017/10/27 18:13:17 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int			init_window(t_m *m)
{
	if (!(m->ptr = mlx_init()))
		return (0);
	m->img = mlx_new_image(m->ptr, WIDTH, HEIGHT);
	m->imga = mlx_get_data_addr(m->img, &(m->bpp), &(m->sl), &(m->endian));
	m->win = mlx_new_window(m->ptr, WIDTH, HEIGHT, "fdf3D");
	mlx_mouse_hook(m->win, mouse_hook, m);
	mlx_expose_hook(m->win, expose_hook, m);
	allocate_matrice(m);
	fill(m);
	m->new_ins = 0;
	m->show_pos = 0;
	m->shake = 0;
	mlx_loop_hook(m->ptr, &loop_hook, m);
	mlx_loop(m->ptr);
	return (1);
}

int			main(int ac, char **av)
{
	t_m		mlx;
	int		fd;

	mlx.rotx = -10;
	mlx.roty = -180;
	mlx.rotz = 0;
	mlx.ins = NULL;
	if (ac > 2)
	{
		if ((fd = open(av[1], O_RDONLY)) != -1)
		{
			if (!av[2] || (mlx.size = ft_atoi(av[2])) < 3)
				mlx.size = 3;
			parse_instructions(&mlx, fd);
			close(fd);
			g_sp = mlx.size / 2;
			init_window(&mlx);
		}
	}
	else
		ft_putendl("Use: ./fdf3D [file_path] [3D Array Size]");
	return (1);
}
