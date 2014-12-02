/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 10:40:14 by frcugy            #+#    #+#             */
/*   Updated: 2014/12/02 10:43:07 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		char_to_int(char ***tab, int ct, t_event e)
{
	int		**tob;
	int		*len;
	int		i;
	int		b;
	int		bob;

	i = 0;
	tob = (int**)malloc(sizeof(int*) * (ct + 1));
	len = cnt_len(tab, ct);
	while (tab[i])
	{
		bob = 0;
		b = 0;
		tob[i] = (int*)malloc(sizeof(int) * len[i]);
		while (tab[i][b])
		{
			bob++;
			tob[i][b] = ft_atoi(tab[i][b]);
			b++;
		}
		e.bobo += bob;
		len[i++] = bob;
	}
	start_print(tob, ct, len, e);
}

void		double_to_triple(char **tab, int ct, t_event e)
{
	char	***tab_final;
	int		i;

	i = 0;
	tab_final = (char***)malloc(sizeof(char**) * ct + 1);
	while (tab[i])
	{
		tab_final[i] = ft_strsplit(tab[i], ' ');
		i++;
	}
	tab_final[i] = NULL;
	char_to_int(tab_final, ct, e);
}
