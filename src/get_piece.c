/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 16:06:49 by hmidoun           #+#    #+#             */
/*   Updated: 2019/11/29 01:22:42 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		check_p_line(t_piece *piece, char *line, int n_line)
{
	int		i;

	i = -1;
	while (++i < piece->y && (line[i] == '.' || line[i] == '*'))
		piece->tab[n_line * piece->y + i] = line[i];
	if (i == piece->y)
		return (1);
	return (0);
}

int		read_p_line(t_piece *piece, int n_line)
{
	char	*line;

	if (get_next_line(0, &line) <= 0)
		return (0);
	if (ft_strlen(line) == (unsigned long)(piece->y) &&
		check_p_line(piece, line, n_line))
	{
		free(line);
		return (1);
	}
	free(line);
	return (0);
}

int		read_p_lines(t_piece *piece)
{
	int	i;

	i = -1;
	while (++i < piece->x)
	{
		if (!read_p_line(piece, i))
			return (0);
	}
	return (1);
}

int		get_piece(t_piece *piece)
{
	if (get_piece_size(piece) && (piece->tab =
						(char *)malloc(sizeof(char) * piece->x * piece->y)))
	{
		if (read_p_lines(piece))
		{
			get_origin(piece);
			return (1);
		}
		free(piece->tab);
	}
	return (0);
}
