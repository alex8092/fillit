/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelauna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 09:10:00 by mdelauna          #+#    #+#             */
/*   Updated: 2015/12/02 15:10:53 by mdelauna         ###   ########.fr       */
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

t_block					**ft_pick_up(t_block **array)
{
	int					index;

	index = 0;
	while (array[index])
	{
		if (array[index]->points[array->n_pts][1] != 0)
		{
			array->n_pts = 0;
			while (array[index]->points[array->n_pts])
			{
				array[index]->points[array->n_pts][1] -=1;
				array->n_pts++;
			}
		}
		index++;
	}
	return (array);
}

t_block					**ft_asm_block(t_block **array)
{
	int					index;

	index = 0;
	while (array[index])
	{
		while (array[index]->points[array->n_pts][0]
			== array[index + i]->points[array->n_pts][0] &&
			array[index]->points[array->n_pts][1]
			== array[index + i]->points[array->n_pts][1])
		{
			array->n_pts++;
		}
		if (array->n_pts > 2)
		{
			if (ft_try_asm(array[index], array[index + i], i, index) != NULL)
			{
				index++;
				i = 0;
			}
			else
				i++;
		}
	}
}

char					**ft_try_asm(t_block *array1, t_block *array2, int i, int index)
{
	int					x;
	int					y;
	char				**tab;

	while (array1->points)
	{
		x = array1->points[array->n_pts][0];
		y = array1->points[array->n_pts][1];
		tab[x][y] = 41 + index;
		array->n_pts++;
	}
	while (tab[x][y])
	{
		if (x < size)
			x++;
		else
			y++;
	}
	while (array2->points && x < size)
	{
		x += array2->points[array->n_pts][0];
		y += array2->points[array->n_pts][1];
		tab[x][y] = 41 + i;
		array->n_pts++;
	}
	if (x > size)
	{
		if ((tab = ft_try_asm_rev(array2, array1)) == NULL)
			return (NULL);
		else
			return (tab);
	}
	return (tab);
}

char				**ft_try_asm_rev(t_block *array2, t_block *array1, int i, int index)
{
	int					x;
	int					y;
	char				**tab;

	while (array2->points)
	{
		x = array2->points[array->n_pts][0];
		y = array2->points[array->n_pts][1];
		tab[x][y] = 41 + index;
		array->n_pts++;
	}
	while (tab[x][y])
	{
		if (x < size)
			x++;
		else
			y++;
	}
	while (array1->points && x < size)
	{
		x += array1->points[array->n_pts][0];
		y += array1->points[array->n_pts][1];
		tab[x][y] = 41 + i;
		array->n_pts++;
	}
	if (x > size)
		return (NULL);
	return (tab);
}
