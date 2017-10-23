/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 00:16:35 by videsvau          #+#    #+#             */
/*   Updated: 2017/10/23 05:43:52 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int			valid_position(int *xyz, int size)
{
	int		bad;

	bad = 0;
	if (xyz[0] < size && xyz[0] > -1)
		bad++;
	if (xyz[1] < size && xyz[1] > -1)
		bad++;
	if (xyz[2] < size && xyz[2] > -1)
		bad++;
	if (bad == 3)
		return (1);
	ft_putstr("3D Array Size:");
	ft_putnbr(size);
	ft_putstr("\nx:");
	ft_putnbr(xyz[0]);
	ft_putstr(" y:");
	ft_putnbr(xyz[1]);
	ft_putstr(" z:");
	ft_putnbr(xyz[2]);
	ft_putendl("\nBad instructions, skipping");
	return (0);
}

void		add_ins(char *str, t_m *m)
{
	int		i;
	int		xyz[3];
	char	*match;

	i = 0;
	m->decx = 1;
	m->first = 1;
	while (str[i])
	{
		if (str[i] == '>')
			m->first = 0;
		if (str[i] == '[')
		{
			xyz[0] = ft_atoi(&str[i + 1]);
			match = &ft_strchr(&str[i + 1], ',')[1];
			xyz[1] = ft_atoi(match);
			match = &ft_strchr(&match[1], ',')[1];
			xyz[2] = ft_atoi(match);
			if (valid_position(xyz, m->size))
				ins_push_back(m->first, &m->ins, xyz);
			else if (m->first == 1)
				exit(1);
		}
		i++;
	}
}

void		parse_instructions(t_m *m, int fd)
{
	char		*str;
	int			ret;

	while ((ret = get_next_line(fd, &str)))
	{
		add_ins(str, m);
		free(str);
	}
	if (m->ins == NULL)
		ft_putendl("Something's fucky");
}
