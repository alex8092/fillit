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

static int				ft_try_block(t_fillit *fil, int index, int size)
{
	t_block				*current;

	if (!(index < fil->blocks_size))
		return (1);
	current = fil->blocks[index];
	current->posx = 0;
	current->posy = 0;
	while (current->posy + current->height <= size)
	{
		current->posx = 0;
		while (current->posx + current->width <= size)
		{
			if (!ft_block_has_collision(fil->blocks, index))
			{
				if (ft_try_block(fil, index + 1, size))
					return (1);
			}
			++current->posx;
		}
		++current->posy;
	}
	return (0);
}

static char				ft_get_result_char(t_fillit *fil, int i, int j)
{
	int					current;
	int					index;
	t_block				*bcurrent;

	current = 0;
	while (current < fil->blocks_size)
	{
		bcurrent = fil->blocks[current];
		index = 0;
		while (index < N_BLOCKS)
		{
			if (bcurrent->points[index][0] + bcurrent->posx == i && \
				bcurrent->points[index][1] + bcurrent->posy == j)
				return ('A' + current);
			++index;
		}
		++current;
	}
	return ('.');
}	

static void				ft_print_result(t_fillit *fil, int size)
{
	int					i;
	int					j;
	char				c;

	j = -1;
	while (++j < size)
	{
		i = -1;
		while (++i < size)
		{
			c = ft_get_result_char(fil, i, j);
			write(1, &c, 1);
		}
		write(1, "\n", 1);
	}
}

void					ft_start_search(void)
{
	t_fillit			*fil;
	const int			blocks_size = ft_get_fillit()->blocks_size;
	int					current_size;

	fil = ft_get_fillit();
	ft_block_to_top_left(fil->blocks, blocks_size);
	current_size = fil->current_size;
	while (!ft_try_block(fil, 0, current_size))
		++current_size;
	ft_print_result(fil, current_size);
}