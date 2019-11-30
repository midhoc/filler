/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmidoun <hmidoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 12:13:50 by hmidoun           #+#    #+#             */
/*   Updated: 2019/11/29 02:11:31 by hmidoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"
# include "array.h"

typedef struct s_filler	t_filler;
struct	s_filler
{
	int				p;
	int				x;
	int				y;
	char			*tab;
	int				*tab_map;
};

typedef struct s_piece	t_piece;
struct	s_piece
{
	char			*tab;
	int				x;
	int				y;
	int				x_0;
	int				y_0;
	int				x_sol;
	int				y_sol;
	int				hight;
	int				weidth;
};

int		get_piece_size(t_piece *piece);
int		get_tab_size(t_filler *filler);
int		get_player(t_filler *filler);
void	get_x_y(char *str, int *x, int *y);
int		free_filler(t_filler *filler);

int		read_lines(t_filler *filler);
int		read_line(t_filler *filler, int n_line);
int		check_line(t_filler *filler, char *line, int n_line);
int		init_filler(t_filler *filler);
int		check_end(t_filler *filler);

int		check_p_line(t_piece *piece, char *line, int n_line);
int		read_p_line(t_piece *piece, int n_line);
int		read_p_lines(t_piece *piece);
int		get_piece(t_piece *piece);
int		get_piece(t_piece *piece);
int		get_origin(t_piece *piece);
void	w_and_h(int i, int j, t_piece *piece, int flag);

void	fill_heat_map(t_filler *filler);

int		solve(t_filler *filler, t_piece *piece);
void	put_sol(t_piece *piece);
#endif
