/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelauna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 09:10:00 by mdelauna          #+#    #+#             */
/*   Updated: 2015/12/10 19:17:40 by mdelauna         ###   ########.fr       */
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
		pieces->points[pieces->n_pts][0] = j;
		pieces->points[pieces->n_pts][1] = i;
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
}

void		ft_pick_up(void)
{
	int					index;
	t_block				**array;

	array = ft_get_fillit()->blocks;
	index = 0;
	while (array[index])
	{
		array[index]->n_pts = 0;
		if (array[index]->points[array[index]->n_pts][1] != 0)
		{
			array[index]->n_pts = 0;
			while (array[index]->n_pts < 4)
			{
				array[index]->points[array[index]->n_pts][1] -= 1;
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

int						ft_found_next_coord(t_block **array, int index,
											int i, int pts)
{
	if (array[index - 1]->points[pts][i]
			== array[index - 1]->points[pts - 1][i])
		return (0);
	else if (array[index - 1]->points[pts][i]
			< array[index - 1]->points[pts - 1][i])
		return (-1);
	else
		return (1);
}

void					ft_empty_case(char **tab, int *i, int *j, int size)
{
	*i = 0;
	*j = 0;
	while (*j < size && *i < size && ft_isalpha(tab[*i][*j]))
	{
		if (*i == size - 1)
		{
			*i = -1;
			(*j)++;
		}
		(*i)++;
	}
}

int						ft_try_asm(t_block **array, int index)
{
	char				**tab;
	char				**cpy;
	int					size;
	int					i;
	int					j;

	size = ft_found_size_tab();
	i = 0;
	j = 0;
	tab = (char **)malloc(sizeof(char *) * size);
	cpy = (char **)malloc(sizeof(char *) * size);
	while (index < size)
	{
		tab[index] = (char *)malloc(sizeof(char) * size);
		cpy[index] = (char *)malloc(sizeof(char) * size);
		++index;
	}
//	index -= 1;
	index = 0;
	array[index]->n_pts = 0;
	while (array[index]->n_pts < 4)
	{
		i = array[index]->points[array[index]->n_pts][0];
		j = array[index]->points[array[index]->n_pts][1];
		tab[i][j] = 'A' + (size - 1 - index);
		array[index]->n_pts++;
	}
	ft_empty_case(tab, &i, &j, size);
	printf("%d, %d\n", i, j);
	cpy = ft_strcpy_tab(cpy, tab);
	index = size;
	array[index - 1]->n_pts = 0;
	while (array[index - 1]->n_pts < 4 && (index - 1) < ft_get_fillit()->blocks_size)
	{
		i += ft_found_next_coord(array, index, 0, array[index - 1]->n_pts);
		j += ft_found_next_coord(array, index, 1, array[index - 1]->n_pts);
		if ((i < size && j < size) && !tab[i][j])
		{
			tab[i][j] = 'A' + ((size - 1) - (index - 1));
			array[index - 1]->n_pts++;
		}
		else
			break ;
/*		{
			index--;
			free(*tab);
			free(tab);
			ft_strcpy_tab(tab, cpy);
		}*/
	}

	ft_empty_case(tab, &i, &j, size);
	printf("%d, %d\n", i, j);
	cpy = ft_strcpy_tab(cpy, tab);
	index = 2;
	array[index - 1]->n_pts = 0;
	while (array[index - 1]->n_pts < 4 && (index - 1) < ft_get_fillit()->blocks_size)
	{
		i += ft_found_next_coord(array, index, 0, array[index - 1]->n_pts);
		j += ft_found_next_coord(array, index, 1, array[index - 1]->n_pts);
		if ((i < size && j < size) && !tab[i][j])
		{
			tab[i][j] = 'A' + ((size - 1) - (index - 1));
			array[index - 1]->n_pts++;
		}
		else
			break ;
	}

	ft_empty_case(tab, &i, &j, size);
	printf("%d, %d\n", i, j);
	cpy = ft_strcpy_tab(cpy, tab);
	index = size - 1;
	array[index - 1]->n_pts = 0;
	while (array[index - 1]->n_pts < 4 && (index - 1) < ft_get_fillit()->blocks_size)
	{
		i += ft_found_next_coord(array, index, 0, array[index - 1]->n_pts);
		j += ft_found_next_coord(array, index, 1, array[index - 1]->n_pts);
		if ((i < size && j < size) && !tab[i][j])
		{
			tab[i][j] = 'A' + ((size - 1) - (index - 1));
			array[index - 1]->n_pts++;
		}
		else
			break ;
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

char				**ft_strcpy_tab(char **dst, char **src)
{
	int				i;
	int				size;

	i = 0;
	size = ft_found_size_tab();
	while (i < size)
	{
		ft_strcpy(dst[i], src[i]);
		i++;
	}
	return (dst);
}
