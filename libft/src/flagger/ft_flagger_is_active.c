/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagger_is_active.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelauna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:51:29 by mdelauna          #+#    #+#             */
/*   Updated: 2015/11/26 18:51:32 by mdelauna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_flagger.h"

t_bool	ft_flagger_is_active(t_flagger *f, char c, const char *name)
{
	size_t		i;
	t_flagopt	*opt;

	i = 0;
	while (i < f->flags->size)
	{
		opt = (t_flagopt*)f->flags->ptr[i];
		if (name && opt->name && !ft_strcmp(name, opt->name))
			return (opt->active);
		if (c && opt->short_name == c)
			return (opt->active);
		++i;
	}
	return (false);
}
