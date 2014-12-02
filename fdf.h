/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 17:05:24 by frcugy            #+#    #+#             */
/*   Updated: 2014/12/02 11:18:25 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define LARGEUR 1920
# define HAUTEUR 1080
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <stdio.h>

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_event
{
	void		*win;
	void		*mlx;
	char		**argv;
	int			bobo;
}				t_event;

void			begin_print(t_coord *coord, int ct, int *len, t_event e);
void			print_vert(t_coord a, t_coord b, void *mlx, void *win);
void			print_hori(t_coord a, t_coord b, void *mlx, void *win);
void			start_print(int **tab, int ct, int *len, t_event e);
int				*cnt_len(char ***tab, int ct);
void			char_to_int(char ***tab, int ct, t_event e);
void			double_to_triple(char **tab, int ct, t_event e);

#endif
