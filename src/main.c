/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 20:14:19 by videsvau          #+#    #+#             */
/*   Updated: 2017/10/25 01:53:08 by videsvau         ###   ########.fr       */
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
	if (keycode == 4)
	{
	}
	if (keycode == 49)
	{
		m->show_pos = 1;
		ft_putnbr(xyz[0]);ft_putchar(' ');
		ft_putnbr(xyz[1]);ft_putchar(' ');
		ft_putnbr(xyz[2]);ft_putchar('\n');
		m->curr_pos.z = xyz[0];
		m->curr_pos.x = xyz[1];
		m->curr_pos.y = xyz[2];
		m->curr_pos.pos = 0;
	}
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
	mlx_hook(m->win, 2, 1L << 0,  &key_hook, m);
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
	m->new_ins = 0;
	m->show_pos = 0;
	mlx_loop_hook(m->ptr, &loop_hook, m);
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
