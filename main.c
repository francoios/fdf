/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 17:05:01 by frcugy            #+#    #+#             */
/*   Updated: 2014/12/02 10:45:31 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		call_fdf(t_event e)
{
	char	**tab;
	char	*line;
	int		i;
	int		b;
	int		fd;

	b = 0;
	i = 0;
	fd = open(e.argv[1], O_RDONLY);
	while (get_next_line(fd, &line))
		i++;
	close(fd);
	fd = open(e.argv[1], O_RDONLY);
	tab = (char**)malloc(sizeof(char*) * i + 1);
	while (get_next_line(fd, &line))
		tab[b++] = ft_strdup(line);
	tab[i] = NULL;
	double_to_triple(tab, i, e);
}

int			expose(t_event *e)
{
	call_fdf(*e);
	return (0);
}

int			key_hook(int key, t_event *e)
{
	e = e;
	if (key == 65307)
		exit(EXIT_SUCCESS);
	return (0);
}

int			main(int argc, char **argv)
{
	t_event e;

	e.bobo = 0;
	argc = argc;
	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, LARGEUR, HAUTEUR + 600, "FdF");
	e.argv = argv;
	mlx_key_hook(e.win, key_hook, &e);
	mlx_expose_hook(e.win, expose, &e);
	mlx_loop(e.mlx);
	return (0);
}
