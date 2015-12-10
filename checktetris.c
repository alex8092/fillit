#include "fillit.h"

static int	ft_check_block(char **block, int i, int j)
{
	int		count;

	count = 1;
	block[i][j] = '?';
	if (j + 1 < 4 && block[i][j + 1] == '#')
		count += ft_check_block(block, i, j + 1);
	if (i - 1 > 0 && block[i - 1][j] == '#')
		count += ft_check_block(block, i - 1, j);
	if (j - 1 > 0 && block[i][j - 1] == '#')
		count += ft_check_block(block, i, j - 1);
	if (i + 1 < 4 && block[i + 1][j] == '#')
		count += ft_check_block(block, i + 1, j);
	return (count);
}

static int	ft_check_block_valid(char **block)
{
	int		i;
	int		j;

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

char		*ft_check_tetris(t_list *list)
{
	int		i;
	int		j;
	int		count;

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
					return ("error\n");
			}
		}
		if (count != 4)
			return ("error\n");
		if (ft_check_block_valid((char **)list->content) != 4)
			return ("error\n");
		list = list->next;
	}
	return (0);
}

int			ft_check_input(t_list *list)
{
	int		i;

	while (list && list->content)
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
		list = list->next;
	}
	return (0);
}