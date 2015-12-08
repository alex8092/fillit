/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelauna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:32:03 by mdelauna          #+#    #+#             */
/*   Updated: 2015/12/08 18:54:30 by mdelauna         ###   ########.fr       */
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
}			        t_fillit;

/*
** Main.c
*/
int					ft_check_block(char **block, int i, int j);
int					ft_check_block_valid(char **block);
char				*ft_check_tetris(t_list *list);
int					ft_check_input(t_list *list);
int					ft_add_tetris(char ***tab, int i, t_list **l, char *line);
int					ft_read_file(char *file, t_list **l);
t_fillit			*ft_get_fillit(void);

/*
** search.c
*/
int					ft_nb_pieces(t_list *list);
void				ft_make_array_block(t_list *list);
void				ft_pick_up(void);
int					ft_found_size_tab(void);
int					ft_try_asm(t_block **array, int index);

#endif
