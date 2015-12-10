#include "fillit.h"

static int		ft_add_tetris(char ***tab, int i, t_list **l, char **line)
{
	char		**tmp;

	tmp = *tab;
	if (ft_strlen(*line) == 0)
	{
		free(*line);
		line = NULL;
		if (i == 0)
		{
			ft_putstr_fd("error\n", 2);
			return (-1);
		}
		ft_lstadd(l, ft_lstnew(tmp, sizeof(tmp)));
		tmp = NULL;
		i = 0;
	}
	else
	{
		tmp[i] = ft_strdup(*line);
		free(*line);
		*line = NULL;
		++i;
	}
	*tab = tmp;
	return (i);
}

static int		ft_finish(char **tmp, int i, t_list **l, char *line)
{
	if (ft_add_tetris(&tmp, i, l, &line) != 0)
	{
		ft_putstr_fd("error\n", 2);
		return (0);
	}
	if (line)
		free(line);
	return (1);
}

static int		ft_error(void)
{
	ft_putstr_fd("error\n", 2);
	return (0);
}

int				ft_read_file(char *file, t_list **l)
{
	int			fd;
	char		*line;
	char		**tmp;
	int			i;

	tmp = NULL;
	i = 0;
	fd = open(file, O_RDONLY);
	if (fd != -1)
	{
		while (get_next_line(fd, &line) > 0)
		{
			if (!tmp)
				tmp = (char **)ft_memalloc(sizeof(*tmp) * 4);
			i = ft_add_tetris(&tmp, i, l, &line);
			if (i == -1)
				return (0);
		}
		close(fd);
		return (ft_finish(tmp, i, l, line));
	}
	else
		return (ft_error());
	return (1);
}