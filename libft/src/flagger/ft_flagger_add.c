/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagger_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelauna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:50:25 by mdelauna          #+#    #+#             */
/*   Updated: 2015/11/26 18:50:27 by mdelauna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_flagger.h"
#include "ft_common.h"

t_flagger	*ft_flagger_add(t_flagger *f, char s, const char *n, t_bool arg)
{
	t_flagopt	*opt;

	opt = (t_flagopt *)ft_memalloc(sizeof(t_flagopt));
	if (opt)
	{
		opt->short_name = s;
		opt->name = n;
		opt->name_len = (n) ? ft_strlen(n) : 0;
		opt->has_arg = arg;
		ft_vector_push(f->flags, (void *)opt);
	}
	return (f);
}
