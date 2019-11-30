/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_board.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:01:38 by hmidoun           #+#    #+#             */
/*   Updated: 2019/11/29 01:25:59 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_line(t_filler *filler, char *line, int n_line)
{
	int		i;

	i = -1;
	while (++i < filler->y)
	{
		if (line[i + 4] == '.')
			filler->tab_map[n_line * filler->y + i] = 110;
		else if (line[i + 4] == 'O')
			filler->tab_map[n_line * filler->y + i] =
							(filler->p == 1 ? -1000000 : 0);
		else if (line[i + 4] == 'X')
			filler->tab_map[n_line * filler->y + i] =
							(filler->p == 2 ? -1000000 : 0);
		else
			break ;
		filler->tab[n_line * filler->y + i] = line[i + 4];
	}
	if (i == filler->y)
		return (1);
	return (0);
}

int		read_line(t_filler *filler, int n_line)
{
	char	*line;

	if (get_next_line(0, &line) <= 0)
		return (0);
	if (ft_strlen(line) == (unsigned long)(filler->y + 4) &&
		check_line(filler, line, n_line))
	{
		free(line);
		return (1);
	}
	free(line);
	return (0);
}

int		read_lines(t_filler *filler)
{
	int		i;
	char	*line;

	if (!(filler->tab))
	{
		if (!init_filler(filler))
			return (0);
	}
	else if (check_end(filler) == 0)
		return (0);
	if (get_next_line(0, &line) <= 0)
		return (0);
	free(line);
	i = -1;
	while (++i < filler->x)
	{
		if (!read_line(filler, i))
			return (0);
	}
	return (1);
}

int		init_filler(t_filler *filler)
{
	if (!get_tab_size(filler) || !filler->p || !filler->y || !filler->x)
		return (0);
	if (!(filler->tab = ft_strnew(sizeof(char) * filler->x * filler->y)))
		return (0);
	if (!(filler->tab_map = (int *)malloc(sizeof(int) * filler->x * filler->y)))
		return (0);
	return (1);
}

int		check_end(t_filler *filler)
{
	char	*line;

	if (get_next_line(0, &line) <= 0)
		return (0);
	if (ft_strstr(line, "== O fin:"))
	{
		free_filler(filler);
		free(line);
		return (0);
	}
	free(line);
	return (1);
}
