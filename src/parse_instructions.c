/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: videsvau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 00:16:35 by videsvau          #+#    #+#             */
/*   Updated: 2017/10/23 02:25:19 by videsvau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/header.h"

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
			ins_push_back(m->first, &m->ins, xyz);
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
