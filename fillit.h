/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelauna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:32:03 by mdelauna          #+#    #+#             */
/*   Updated: 2015/12/10 19:17:41 by mdelauna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"

# define N_BLOCKS	4

typedef struct		s_block
{
	int				points[4][2];
	int				n_pts;
	int				posx;
	int				posy;
	int				width;
	int				height;	
}					t_block;

typedef struct		s_fillit
{
	t_block			**blocks;
	int				blocks_size;
	int				current_size;
}			        t_fillit;

/*
** reader.c
*/
char				*ft_check_tetris(t_list *list);
int					ft_check_input(t_list *list);
int					ft_read_file(char *file, t_list **l);

/*
** fillit.c
*/
t_fillit			*ft_get_fillit(void);
void				ft_make_array_block(t_list *list, int size);
t_list				*ft_free_list_item(t_list *item);

/*
** block.c
*/
int					ft_block_has_collision(t_block **array, int current);

/*
** presearch.c
*/
void				ft_block_to_top_left(t_block **blocks, int size);

/*
** search.c
*/
void				ft_start_search(void);

#endif
