/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 00:16:35 by videsvau          #+#    #+#             */
/*   Updated: 2017/11/05 17:26:09 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

int			fix_positions(int *xyz, int size)
{
	if (xyz[0] >= size)
		xyz[0] = size - 1;
	if (xyz[0] < 0)
		xyz[0] = 1;
	if (xyz[1] >= size)
		xyz[1] = size - 1;
	if (xyz[1] < 0)
		xyz[1] = 1;
	if (xyz[2] >= size)
		xyz[2] = size - 1;
	if (xyz[2] < 0)
		xyz[2] = 1;
	return (1);
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
			xyz[0] = ft_atoi(&str[i + 1]) + 20;
			match = &ft_strchr(&str[i + 1], ',')[1];
			xyz[1] = ft_atoi(match) + 20;
			match = &ft_strchr(&match[1], ',')[1];
			xyz[2] = ft_atoi(match) + 20;
			if (fix_positions(xyz, m->size))
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
		ft_putendl("Is the map empty?");
}
