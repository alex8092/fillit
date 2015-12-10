/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelauna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:31:08 by mdelauna          #+#    #+#             */
/*   Updated: 2015/12/10 19:17:43 by mdelauna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int				ft_nb_pieces(t_list *list)
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

static int				ft_free_resources(t_list *list, t_fillit *fil)
{
	int					i;

	while (list)
		list = ft_free_list_item(list);
	if (fil->blocks)
	{
		i = 0;
		while (i < fil->blocks_size)
		{
			if (fil->blocks[i])
				free(fil->blocks[i]);
			++i;
		}
		free(fil->blocks);
	}
	return (1);
}

static int				ft_wrong_usage(void)
{
	ft_putstr_fd("usage: ./fillit <file>\n", 2);
	return (1);
}	

int						main(int ac, char **av)
{
	t_list				*list;
	char				*err;

	ft_bzero((void *)ft_get_fillit(), sizeof(t_fillit));
	if (ac == 2)
	{
		list = ft_lstnew(NULL, 0);
		if (!ft_read_file(av[1], &list))
			return (ft_free_resources(list, ft_get_fillit()));
		if (ft_check_input(list) == 1)
		{
			ft_putstr_fd("error\n", 2);
			return (ft_free_resources(list, ft_get_fillit()));
		}
		if ((err = ft_check_tetris(list)))
		{
			ft_putstr_fd(err, 2);
			return (ft_free_resources(list, ft_get_fillit()));
		}
		ft_make_array_block(list, ft_nb_pieces(list));
		list = 0;
		ft_start_search();
		return (ft_free_resources(list, ft_get_fillit()));
	}
	return (ft_wrong_usage());
}
