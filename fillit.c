#include "fillit.h"

static int			ft_found_size_tab(int blocks)
{
	int				size;

	size = 1;
	while (size * size < blocks)
		++size;
	return (size);
}

t_fillit			*ft_get_fillit(void)
{
	static t_fillit	_instance;

	return (&_instance);
}

static void			ft_block_add_point(char c, t_block *pieces, int i, int j)
{
	if (c == '?')
	{
		pieces->points[pieces->n_pts][0] = j;
		pieces->points[pieces->n_pts][1] = i;
		pieces->n_pts++;
	}
}

t_list				*ft_free_list_item(t_list *item)
{
	int				i;
	t_list			*tmp;

	i = 0;
	if (item->content)
	{
		while (i < 4)
		{
			if (((char **)item->content)[i])
			free(((char **)item->content)[i]);
			++i;
		}
		free((char **)item->content);
	}
	tmp = item->next;
	free(item);
	return (tmp);
}

void				ft_make_array_block(t_list *list, int size)
{
	t_block			**arr;
	t_block			*item;
	int				n;
	int				i;
	int				j;

	ft_get_fillit()->blocks_size = size;
	arr = (t_block **)malloc(sizeof(t_block *) * size);
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
		arr[(size - 1 - n++)] = item;
		list = ft_free_list_item(list);
	}
	ft_free_list_item(list);
	ft_get_fillit()->blocks = arr;
	ft_get_fillit()->current_size = ft_found_size_tab(size * 4);
}