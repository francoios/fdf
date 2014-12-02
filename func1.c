/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 10:36:38 by frcugy            #+#    #+#             */
/*   Updated: 2014/12/02 10:50:42 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		print_hori(t_coord a, t_coord b, void *mlx, void *win)
{
	float	dir;
	float	p;
	float	i;
	int		j;
	float	tmp;

	tmp = b.y - a.y;
	dir = tmp / (b.x - a.x);
	p = a.y - (dir * a.x);
	i = a.x;
	while (i < b.x)
	{
		if (tmp == 0)
			j = a.y;
		else
			j = round(dir * i + p);
		mlx_pixel_put(mlx, win, i, j, 0xFFFFFF);
		i += 0.02;
	}
}

void		print_vert(t_coord a, t_coord b, void *mlx, void *win)
{
	float	dir;
	float	p;
	float	i;
	int		j;
	float	tmp;

	tmp = b.x - a.x;
	dir = (b.y - a.y) / tmp;
	p = a.y - (dir * a.x);
	i = a.y;
	while (i < b.y)
	{
		if (tmp == 0)
			j = a.x;
		else
			j = round((i - p) / dir);
		mlx_pixel_put(mlx, win, j, i, 0xFFFFFF);
		i += 0.02;
	}
}

void		begin_print(t_coord *coord, int ct, int *len, t_event e)
{
	int		tmp;
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (y < ct)
	{
		tmp = x;
		while (x + 1 <= len[y] + tmp && len[y] > 0)
		{
			print_hori(coord[x], coord[x + 1], e.mlx, e.win);
			if ((x - tmp) < len[y + 1])
			{
				if (coord[x].y > coord[x + len[y]].y && y < ct - 1)
					print_vert(coord[x + len[y]], coord[x], e.mlx, e.win);
				else
					print_vert(coord[x], coord[x + len[y]], e.mlx, e.win);
			}
			x++;
		}
		y++;
	}
}

void		start_print(int **tab, int ct, int *len, t_event e)
{
	t_coord	*coord;
	int		x;
	int		y;
	int		i;

	y = 0;
	i = 0;
	coord = (t_coord*)malloc(sizeof(t_coord) * e.bobo);
	while (tab[y] != NULL)
	{
		x = 0;
		while (x < len[y])
		{
			coord[i].x = (35 * x - 35 * y) + (LARGEUR / 2);
			coord[i].y = (20 * x + 20 * y) - (3 * tab[y][x]) + (HAUTEUR / 4);
			x++;
			i++;
		}
		y++;
	}
	begin_print(coord, ct, len, e);
}

int			*cnt_len(char ***tab, int ct)
{
	int		*len;
	int		i;
	int		b;
	int		bob;

	i = 0;
	len = (int*)malloc(sizeof(int) * (ct + 1));
	while (tab[i])
	{
		bob = 0;
		b = 0;
		while (tab[i][b])
		{
			bob++;
			b++;
		}
		len[i] = bob;
		i++;
	}
	i = 0;
	return (len);
}
