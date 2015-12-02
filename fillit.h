/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelauna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:32:03 by mdelauna          #+#    #+#             */
/*   Updated: 2015/12/02 19:32:17 by mdelauna         ###   ########.fr       */
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

typedef struct		s_block
{
	int				points[4][2];
	int				n_pts;
	int				posx;
	int				posy;
}					t_block;

typedef struct		s_fillit
{
	t_block			**blocks;
	int				blocks_size;
	int				current_size;
}

/*
** Main.c
*/
int					ft_check_block(char **block, int i, int j);
int					ft_check_block_valid(char **block);
char				*ft_check_tetris(t_list *list);
int					ft_check_input(t_list *list);
int					ft_add_tetris(char ***tab, int i, t_list **l, char *line);
int					ft_read_file(char *file, t_list **l);

/*
** search.c
*/
int					ft_nb_pieces(t_list *list);
t_block				**ft_make_array_block(t_list *list);
t_block				**ft_pick_up(t_block **array);
int					ft_found_size_tab(t_block **array);

#endif
