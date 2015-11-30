/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelauna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 09:10:00 by mdelauna          #+#    #+#             */
/*   Updated: 2015/11/30 19:52:17 by mdelauna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int						ft_nb_pieces(t_list *list)
{
	int					i;

	i = 0;
	while (list && list->content)
	{
		i++;
		list = list->next;
	}
	return (i);
}

static void				ft_block_add_point(char c, t_block *pieces, int i, int j)
{
	if (c == '#')
	{
		pieces->points[pieces->n_pts][0] = i;
		pieces->points[pieces->n_pts][1] = j;
		pieces->n_pts++;
	}
}

t_block					**ft_make_array_block(t_list *list)
{
	t_block				**array;
	t_block				*item;
	int					n;
	int					i;
	int					j;

	array = (t_block **)malloc(sizeof(t_block *) * ft_nb_pieces(list));
	n = 0;
	while (list && list->content)
	{
		item = (t_block *)ft_memalloc(sizeof(t_block));
		i = -1;
		while (++i < 4)
		{
			j = -1;
			while (++j < 4)
				ft_block_add_point(((char **)list->content)[i][j], item, i, j);
		}
		array[n++] = item;
		list = list->next;
	}
	return (array);
}

