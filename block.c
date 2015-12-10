#include "fillit.h"

static int	ft_is_block_collide(t_block *current, t_block *test)
{
	int		i;
	int		j;
	int		c1;
	int		c2;

	i = -1;
	while (++i < N_BLOCKS)
	{
		j = -1;
		while (++j < N_BLOCKS)
		{
			c1 = current->points[i][0] + current->posx;
			c2 = current->points[i][1] + current->posy;
			if (c1 == test->points[j][0] + test->posx && \
				c2 == test->points[j][1] + test->posy)
				return (1);
		}
	}
	return (0);
}

int			ft_block_has_collision(t_block **blocks, int current)
{
	int		i;

	i = 0;
	while (i < current)
	{
		if (ft_is_block_collide(blocks[i], blocks[current]))
			return (1);
		++i;
	}
	return (0);
}