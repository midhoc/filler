/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 04:50:15 by hmidoun           #+#    #+#             */
/*   Updated: 2019/11/29 01:23:44 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		fill_heat_x_y(t_filler *filler, int x, int y, int i)
{
	if (y - 1 >= 0 && x - 1 >= 0 &&
						filler->tab_map[(x - 1) * filler->y + y - 1] > i + 1)
		filler->tab_map[(x - 1) * filler->y + y - 1] = i + 1;
	if (y - 1 >= 0 && filler->tab_map[(x) * filler->y + y - 1] > i + 1)
		filler->tab_map[(x) * filler->y + y - 1] = i + 1;
	if (y - 1 >= 0 && x + 1 < filler->x &&
						filler->tab_map[(x + 1) * filler->y + y - 1] > i + 1)
		filler->tab_map[(x + 1) * filler->y + y - 1] = i + 1;
	if (x - 1 >= 0 && filler->tab_map[(x - 1) * filler->y + y] > i + 1)
		filler->tab_map[(x - 1) * filler->y + y] = i + 1;
	if (x + 1 < filler->x && filler->tab_map[(x + 1) * filler->y + y] > i + 1)
		filler->tab_map[(x + 1) * filler->y + y] = i + 1;
	if (y + 1 < filler->y && x - 1 >= 0 &&
						filler->tab_map[(x - 1) * filler->y + y + 1] > i + 1)
		filler->tab_map[(x - 1) * filler->y + y + 1] = i + 1;
	if (y + 1 < filler->y && filler->tab_map[(x) * filler->y + y + 1] > i + 1)
		filler->tab_map[(x) * filler->y + y + 1] = i + 1;
	if (y + 1 < filler->y && x + 1 < filler->x &&
						filler->tab_map[(x + 1) * filler->y + y + 1] > i + 1)
		filler->tab_map[(x + 1) * filler->y + y + 1] = i + 1;
}

void			fill_heat_map(t_filler *filler)
{
	int	i;
	int	x;
	int	y;

	i = -1;
	while (++i < filler->x && i < filler->y)
	{
		x = -1;
		while (++x < filler->x)
		{
			y = -1;
			while (++y < filler->y)
			{
				if (filler->tab_map[x * filler->y + y] == i)
					fill_heat_x_y(filler, x, y, i);
			}
		}
	}
}

int				get_origin(t_piece *piece)
{
	int	i;
	int	j;

	i = -1;
	piece->x_0 = piece->x;
	piece->y_0 = piece->y;
	piece->weidth = 0;
	piece->hight = 0;
	while (++i < piece->x)
	{
		j = -1;
		while (++j < piece->y)
		{
			if (piece->tab[i * piece->y + j] != '.')
				w_and_h(i, j, piece, 0);
		}
	}
	w_and_h(i, j, piece, 1);
	return (1);
}

void			w_and_h(int i, int j, t_piece *piece, int flag)
{
	if (flag)
	{
		piece->weidth -= piece->y_0;
		piece->hight -= piece->x_0;
		return ;
	}
	if (piece->x_0 > i)
		piece->x_0 = i;
	if (piece->y_0 > j)
		piece->y_0 = j;
	if (piece->weidth < j)
		piece->weidth = j;
	if (piece->hight < i)
		piece->hight = i;
}
