/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 21:51:47 by hmidoun           #+#    #+#             */
/*   Updated: 2019/11/30 14:05:00 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		free_filler(t_filler *filler)
{
	if (filler->tab)
	{
		free(filler->tab);
		filler->tab = NULL;
	}
	if (filler->tab_map)
	{
		free(filler->tab_map);
		filler->tab_map = NULL;
	}
	return (0);
}

void	init(t_filler *filler, t_piece *piece)
{
	filler->p = 0;
	filler->x = 0;
	filler->y = 0;
	filler->tab = NULL;
	filler->tab_map = NULL;
	piece->tab = NULL;
}

int		main(void)
{
	t_filler	filler;
	t_piece		piece;

	init(&filler, &piece);
	if (!get_player(&filler))
		return (0);
	while (1)
	{
		if (!read_lines(&filler))
			return (free_filler(&filler));
		fill_heat_map(&filler);
		if (!get_piece(&piece))
		{
			if (piece.tab)
				free(piece.tab);
			return (free_filler(&filler));
		}
		solve(&filler, &piece);
		put_sol(&piece);
		free(piece.tab);
		piece.tab = NULL;
	}
	return (0);
}
