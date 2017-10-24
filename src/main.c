/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 20:14:19 by videsvau          #+#    #+#             */
/*   Updated: 2017/10/24 09:49:56 by videsvau         ###   ########.fr       */
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

	if (keycode > 82 && keycode < 89)
		move_cursor(keycode, m);
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
	draw_points(m);
	return (0);
}

int			expose_hook(t_m *m)
{
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
				parse_instructions(&mlx, fd);
				close(fd);
				g_sp = mlx.size / 2;
				init_window(&mlx);
			}
		}
	}
	return (1);
}
