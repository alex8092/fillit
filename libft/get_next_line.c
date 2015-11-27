/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelauna <mdelauna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 10:17:29 by mdelauna          #+#    #+#             */
/*   Updated: 2015/03/06 11:09:41 by mdelauna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check(char *buffer1)
{
	int			i;

	i = 0;
	while (buffer1[i] != '\0')
	{
		if (buffer1[i] == '\n')
		{
			(buffer1)[i] = '\0';
			return (0);
		}
		i++;
	}
	return (1);
}

int		get_next_line(int const fd, char **line)
{
	static char	*buffer1 = "";
	char		*buffer2;
	int			size;

	size = BUFF_SIZE;
	if (size == 0)
		return (0);
	while (check(buffer1) && size == BUFF_SIZE)
	{
		buffer2 = (char *)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1));
		size = read(fd, buffer2, BUFF_SIZE);
		if (size == -1)
			return (-1);
		buffer1 = ft_strjoin(buffer1, buffer2);
		free(buffer2);
	}
	buffer2 = (char *)ft_memalloc(sizeof(char) * (ft_strlen(buffer1) + 1));
	ft_memcpy(buffer2, buffer1, ft_strlen(buffer1));
	buffer1 = buffer1 + ft_strlen(buffer2) + 1;
	*line = ft_strdup(buffer2);
	free(buffer2);
	if (size > 1 || (size == 0 && ft_strlen(*line) > 0))
		return (1);
	return (size);
}
