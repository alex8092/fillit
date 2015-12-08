/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelauna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 09:10:00 by mdelauna          #+#    #+#             */
/*   Updated: 2015/12/02 19:26:39 by mdelauna         ###   ########.fr       */
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

void	ft_make_array_block(t_list *list)
{
	t_block				**array;
	t_block				*item;
	int					n;
	int					i;
	int					j;

	ft_get_fillit()->blocks_size = ft_nb_pieces(list);
	array = (t_block **)malloc(sizeof(t_block *) * (ft_nb_pieces(list) + 1));
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
	array[n] = 0;
	ft_get_fillit()->blocks = array;
	//ft_get_fillit()->blocks_size = ft_nb_pieces(list);
}

void		ft_pick_up(void)
{
	int					index;
	t_block				**array;

	array = ft_get_fillit()->blocks;
	index = 0;
	while (array[index])
	{
		if (array[index]->points[array[index]->n_pts][1] != 0)
		{
			array[index]->n_pts = 0;
			while (array[index]->n_pts < 4)
			{
				array[index]->points[array[index]->n_pts][1] -=1;
				array[index]->n_pts++;
			}
		}
		index++;
	}
	ft_try_asm(array, 0);
}

int						ft_found_size_tab()
{
	int					index;
	int					blocks;
	int					size;
	t_block				**array;

	array = ft_get_fillit()->blocks;
	index = 0;
	size = 4;
	blocks = 0;
	while (array[index])
		index++;
	blocks = index * 4;
	while (size * size < blocks)
		size++;
	return (size);
}

int						ft_try_asm(t_block **array, int index)
{
	char				**tab;
	int					size;
	int					i;
	int					j;
	int					index2;

	size = ft_found_size_tab();
	i = 0;
	j = 0;
	index2 = index;
	tab = (char **)malloc(sizeof(char *) * size);
	while (index < size)
	{
		tab[index] = (char *)malloc(sizeof(char) * size);
		++index;
	}
	index = index2;
	array[index]->n_pts = 0;
	while (array[index]->n_pts < 4)
	{
		i = array[index]->points[array[index]->n_pts][0];
		j = array[index]->points[array[index]->n_pts][1];
		tab[i][j] = '#';
		array[index]->n_pts++;
	}
	array[index + 1]->n_pts = 0;
	while (array[index + 1]->n_pts < 4 && (index + 1) < ft_get_fillit()->blocks_size)
	{
		printf("%d %d %d %c\n", (index + 1), i, j, tab[i][j]);
		i = array[index + 1]->points[array[index + 1]->n_pts][0];
		j = array[index + 1]->points[array[index + 1]->n_pts][1];
		printf("%d")
		if (tab[i][j] != '#')
		{
			tab[i][j] = '#';
			array[index + 1]->n_pts++;
		}
		else
//			break ;
		{
			index++;
			array[index + 1]->n_pts = 0;
		}
	}

/*	if (index == ft_get_fillit()->blocks_size)
	{
		ft_try_asm(array, 1);
	}
*/
	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			printf("%c ", (tab[i][j]) ? tab[i][j] : '.');
			i++;
		}
		printf("\n");
		j++;
	}
	return (0);
}
