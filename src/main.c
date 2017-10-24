/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 20:14:19 by videsvau          #+#    #+#             */
/*   Updated: 2017/10/24 04:23:50 by videsvau         ###   ########.fr       */
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
	if (keycode == 53)
		exit(1);
	ft_putstr("\nKeycode:");
	ft_putnbr(keycode);
	ft_putchar('\n');
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
	get_pos(m, xyz);
	if (keycode == 1)
		m->add_ins = 1;
	ft_putstr("Cursor Position: Z=");ft_putnbr(xyz[0]);ft_putstr(" X:");ft_putnbr(xyz[1]);ft_putstr(" Y:");ft_putnbr(xyz[2]);
	if (keycode == 49)
	{
		current_mat = m->mat[xyz[0]][xyz[1]][xyz[2]];
		sp_line = 1;
	}
	if (keycode == 51)
		sp_line = 0;
	ft_putstr("Rot_X:");ft_putnbr(m->rotx);ft_putstr(" Rox_Y:");ft_putnbr(m->roty);ft_putstr(" Rot_Z:");ft_putnbr(m->rotz);ft_putchar('\n');
	draw_points(m);
	return (0);
}

int			expose_hook(t_m *m)
{
	int		fd;

	if ((fd = open(g_path, O_RDONLY)) != -1)
	{
		free_list(&m->ins);
		parse_instructions(m, fd);
		close(fd);
	}
	ft_putendl(g_path);
	ft_putendl("\tExpose Hook");
	draw_points(m);
	return (0);
}

int			init_window(t_m *m)
{
	if (!(m->ptr = mlx_init()))
		return (0);
	m->img = mlx_new_image(m->ptr, WIDTH, HEIGHT);
	m->imga = mlx_get_data_addr(m->img, &(m->bpp), &(m->sl), &(m->endian));
	m->win = mlx_new_window(m->ptr, WIDTH, HEIGHT, "fdf3D");
	mlx_mouse_hook(m->win, mouse_hook, m);
	mlx_key_hook(m->win, key_hook, m);
	mlx_expose_hook(m->win, expose_hook, m);
	allocate_matrice(m);
	fill(m);
	sp_line = 0;
	m->add_ins = 1;
	mlx_loop(m->ptr);
	return (1);
}

int			main(int ac, char **av)
{
	t_m		mlx;
	int		fd;

	mlx.rotx = 0;
	mlx.roty = 0;
	mlx.rotz = 0;
	mlx.ins = NULL;
	if (ac > 1)
	{
		ft_putendl("Use: ./fdf3D file [file_path] [3D Array Size] (map should fit for the size)");
		if (ft_strcmp(av[1], "file") == 0)
		{
			if ((fd = open(av[2], O_RDONLY)) != -1)
			{
				mlx.size = ft_atoi(av[3]);
				g_path = ft_strdup(av[2]);
				parse_instructions(&mlx, fd);
				close(fd);
				g_sp = mlx.size / 2;
				init_window(&mlx);
			}
		}
	}
	return (1);
}
