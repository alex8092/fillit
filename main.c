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

int								ft_check_block(char **block, int i, int j)
{
	int							count;

	count = 1;
	block[i][j] = '?';
	if (j < 3 && block[i][j + 1] == '#')
		count += ft_check_block(block, i, j + 1);
	if (i > 0 && block[i - 1][j] == '#')
		count += ft_check_block(block, i - 1, j);
	if (j > 0 && block[i][j - 1] == '#')
		count += ft_check_block(block, i, j - 1);
	if (i < 3 && block[i + 1][j] == '#')
		count += ft_check_block(block, i + 1, j);
	block[i][j] = '#';
	return (count);
}

int								ft_check_block_valid(char **block)
{
	int							i;
	int							j;

	i = 0;
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (block[i][j] == '#')
				return (ft_check_block(block, i, j));
			++i;
		}
		++j;
	}
	return (-1);
}

char							*ft_check_tetris(t_list *list)
{
	int							i;
	int							j;
	int							count;

	while (list && list->content)
	{
		count = 0;
		i = -1;
		while (++i < 4 && (j = -1) == -1)
		{
			while (++j < 4)
			{
				if (((char **)list->content)[i][j] == '#')
					count++;
				else if (((char **)list->content)[i][j] != '.')
					return ("Invalid Character\n");
			}
		}
		if (count != 4)
			return ("Tetris must occupy 4 of the 16 cases.\n");
		if (ft_check_block_valid((char **)list->content) != 4)
			return ("Invalid Tetriminos.\n");
		list = list->next;
	}
	return (0);
}

int								ft_check_input(t_list *list)
{
	int							i;

	while (list && list->content)
	{
		if (list->content != NULL)
		{
			i = 0;
			while (i < 4)
			{
				if (!((char **)list->content)[i]
						|| ft_strlen(((char **)list->content)[i]) < 4)
					return (1);
				i++;
			}
			if (i < 4)
				return (1);
		}
		list = list->next;
	}
	ft_putstr("File OK !\n");
	return (0);
}

int								ft_add_tetris(char ***tab, int i, t_list **l, \
	char *line)
{
	char						**tmp;

	tmp = *tab;
	if (ft_strlen(line) == 0)
	{
		if (i == 0)
		{
			ft_putstr_fd("Error: Two or more empty lines.\n", 2);
			return (-1);
		}
		ft_lstadd(l, ft_lstnew(tmp, sizeof(tmp)));
		tmp = NULL;
		i = 0;
	}
	else
	{
		tmp[i] = line;
		line = NULL;
		++i;
	}
	*tab = tmp;
	return (i);
}

int								ft_read_file(char *file, t_list **l)
{
	int							fd;
	char						*line;
	char						**tmp;
	int							i;

	tmp = NULL;
	i = 0;
	fd = open(file, O_RDONLY);
	if (fd != -1)
	{
		while (get_next_line(fd, &line))
		{
			if (!tmp)
				tmp = (char **)ft_memalloc(sizeof(*tmp) * 4);
			i = ft_add_tetris(&tmp, i, l, line);
			if (i == -1)
				return (0);
		}
	}
	else
	{
		ft_putstr_fd("Error: Can't open file.\n", 2);
		return (0);
	}
	return (1);
}

int								main(int ac, char **av)
{
	t_list						*list;
	char						*err;

	ft_bzero((void *)ft_get_fillit(), sizeof(t_fillit));
	if (ac < 2)
	{
		ft_putstr_fd("Usage: ./fillit <file>\n", 2);
		return (1);
	}
	else
	{
		list = ft_lstnew(NULL, 0);
		if (!ft_read_file(av[1], &list))
			return (1);
		if (ft_check_input(list) == 1)
		{
			ft_putstr_fd("Incorrect format.\n", 2);
			return (2);
		}
		if ((err = ft_check_tetris(list)))
		{
			ft_putstr_fd(err, 2);
			return (2);
		}
		ft_make_array_block(list);
		ft_get_fillit()->current_size = ft_found_size_tab();
		ft_pick_up();
	}
	return (0);
}
