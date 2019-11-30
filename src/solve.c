/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 03:12:06 by hmidoun           #+#    #+#             */
/*   Updated: 2019/11/29 01:49:47 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		check(t_filler *filler, t_piece *piece, int x, int y)
{
	int	i;
	int	j;
	int	ret;

	i = -1;
	ret = 0;
	while (++i <= piece->hight)
	{
		j = -1;
		while (++j <= piece->weidth)
		{
			if (piece->tab[(i + piece->x_0) * piece->y +
								(j + piece->y_0)] == '*')
			{
				if (filler->tab_map[(x + i) * filler->y + (y + j)] == 0)
					return (0);
				ret += filler->tab_map[(x + i) * filler->y + (y + j)];
			}
		}
	}
	return (ret);
}

static int		help_sol(t_piece *piece, int x, int y, int ret1)
{
	piece->x_sol = x;
	piece->y_sol = y;
	return (ret1);
}

int				solve(t_filler *filler, t_piece *piece)
{
	int		x;
	int		y;
	int		ret;
	int		ret1;

	ret = 0;
	x = -1;
	piece->x_sol = 0;
	piece->y_sol = 0;
	while (++x < filler->x - piece->hight)
	{
		y = -1;
		while (++y < filler->y - piece->weidth)
		{
			ret1 = check(filler, piece, x, y);
			if (0 > ret1 && ret1 > -1000000 && ret >= ret1)
			{
				if (ret > ret1)
					ret = help_sol(piece, x, y, ret1);
				else if (filler->p == 1)
					help_sol(piece, x, y, ret1);
			}
		}
	}
	return (ret);
}

void			put_sol(t_piece *piece)
{
	ft_putnbr_fd(piece->x_sol - piece->x_0, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(piece->y_sol - piece->y_0, 1);
	ft_putchar_fd('\n', 1);
}
