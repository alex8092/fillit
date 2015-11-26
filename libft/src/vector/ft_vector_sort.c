/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelauna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:53:26 by mdelauna          #+#    #+#             */
/*   Updated: 2015/11/26 18:53:29 by mdelauna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_common.h"

void	ft_vector_sort(t_vector *v, int (*cmp)())
{
	size_t	i;
	void	*ptr;

	if (v->size > 1 || !v->ptr)
		return ;
	i = 0;
	while (i < v->size - 1)
	{
		if (cmp(v->ptr[i], v->ptr[i + 1]) > 0)
		{
			ptr = v->ptr[i];
			v->ptr[i] = v->ptr[i + 1];
			v->ptr[i + 1] = ptr;
			i = 0;
		}
		else
			++i;
	}
}
