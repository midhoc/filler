/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_dim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 03:13:39 by hmidoun           #+#    #+#             */
/*   Updated: 2019/11/28 22:02:35 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_x_y(char *str, int *x, int *y)
{
	int	i;

	i = 0;
	while (!ft_isdigit(str[i]))
	{
		i++;
	}
	*x = ft_atoi(str + i);
	while (ft_isdigit(str[i]))
	{
		i++;
	}
	while (!ft_isdigit(str[i]))
	{
		i++;
	}
	*y = ft_atoi(str + i);
}

int		get_player(t_filler *filler)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "$$$ exec p1 :"))
			filler->p = 1;
		else if (ft_strstr(line, "$$$ exec p2 :"))
			filler->p = 2;
		free(line);
		if (filler->p)
			return (1);
	}
	return (0);
}

int		get_tab_size(t_filler *filler)
{
	char	*line;

	if (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "Plateau"))
		{
			get_x_y(line, &(filler->x), &(filler->y));
			free(line);
			return (1);
		}
		free(line);
	}
	return (0);
}

int		get_piece_size(t_piece *piece)
{
	char	*line;

	piece->x = 0;
	piece->y = 0;
	if (get_next_line(0, &line) > 0)
	{
		if (ft_strstr(line, "Piece"))
		{
			get_x_y(line, &(piece->x), &(piece->y));
			free(line);
			return (1);
		}
		free(line);
	}
	return (0);
}
