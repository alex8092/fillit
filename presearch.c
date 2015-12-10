#include "fillit.h"

static void			ft_block_to_up(t_block *block)
{
	block->n_pts = 0;
	while (block->n_pts < N_BLOCKS)
	{
		--block->points[block->n_pts][1];
		++block->n_pts;
	}
}

static void			ft_block_to_left(t_block *block)
{
	block->n_pts = 0;
	while (block->n_pts < N_BLOCKS)
	{
		--block->points[block->n_pts][0];
		++block->n_pts;
	}
}

static int			ft_test_move(t_block *block)
{
	int				i;
	int				j;

	i = block->points[0][0];
	j = block->points[0][1];
	block->n_pts = 0;
	while (block->n_pts < N_BLOCKS)
	{
		if (i > block->points[block->n_pts][0])
			i = block->points[block->n_pts][0];
		if (j > block->points[block->n_pts][1])
			j = block->points[block->n_pts][1];
		++block->n_pts;
	}
	if (i != 0)
		ft_block_to_left(block);
	if (j != 0)
		ft_block_to_up(block);
	return ((i != 0 || j != 0) ? 1 : 0);
}	

static void			ft_perform_border(t_block *block)
{
	int				width;
	int				height;

	width = 0;
	height = 0;
	block->n_pts = 0;
	while (block->n_pts < N_BLOCKS)
	{
		if (block->points[block->n_pts][0] > width)
			width = block->points[block->n_pts][0];
		if (block->points[block->n_pts][1] > height)
			height = block->points[block->n_pts][1];
		++block->n_pts;
	}
	block->width = width + 1;
	block->height = height + 1;
}

void				ft_block_to_top_left(t_block **blocks, int size)
{
	int				i;

	i = 0;
	while (i < size)
	{
		if (ft_test_move(blocks[i]))
			continue ;
		ft_perform_border(blocks[i]);
		++i;
	}
}