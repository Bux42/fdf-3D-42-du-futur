/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 20:13:50 by videsvau          #+#    #+#             */
/*   Updated: 2017/10/24 00:57:06 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

# define HEADER_H

# define WIDTH 1300
# define HEIGHT 1300

# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include <sys/time.h>

typedef struct		s_ins
{
	int				x;
	int				y;
	int				z;
	int				start;
	struct s_ins	*next;
}					t_ins;

typedef struct		s_mat
{
	int				x;
	int				y;
	int				z;
	int				pos;
}					t_mat;

typedef struct		s_l
{
	int				x;
	int				y;
	int				z;
	int				x1;
	int				y1;
	int				z1;
}					t_l;

typedef struct		s_d
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				err;
	int				e2;
}					t_d;

typedef struct		s_m
{
	char			*ptr;
	char			*win;
	char			*img;
	char			*imga;
	int				bpp;
	int				sl;
	int				endian;
	int				first;;
	int				decx;
	int				decy;
	int				size;
	int				rotx;
	int				roty;
	int				rotz;
	float			endx;
	float			endy;
	float			endz;
	struct s_ins	*ins;
	struct s_l		line;
	struct s_d		bres;
	struct s_mat	***mat;
}					t_m;

char				*g_path;
struct timeval		g_time;
struct timeval		g_time2;

void				get_pos(t_m *m, int *xyz);
void				move_x(int gap, t_m *m);
void				move_y(int gap, t_m *m);
void				move_z(int gap, t_m *m);

t_ins				*create_ins(int x, int y, int z, int first);
void				ins_push_back(int first, t_ins **ins, int *xyz);
void				free_list(t_ins **ins);

void				parse_instructions(t_m *m, int fd);
void				add_ins(char *str, t_m *m);
int					valid_position(int *xyz, int size);

int					g_sp;
void				allocate_matrice(t_m *m);
void				fill(t_m *m);
int					init_window(t_m *m);
int					mouse_hook(int button, int x, int y, t_m *m);
int					expose_hook(t_m *m);
int					key_hook(int keycode, t_m *m);

void				put_pixel(t_m *m, int x, int y, int color);
void				init_bres(t_d *bres, t_l line1, t_l line2);
void				get_center(t_m *m);
void				draw_line(t_l line1, t_l line2, t_m *m);
void				draw_points(t_m *m);
void				clean_img(t_m *m);

void				degree_to_rad(t_m *m);
t_l					rotation(t_mat mat, t_m *m);

#endif
