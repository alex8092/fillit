/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagger_stop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelauna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:52:28 by mdelauna          #+#    #+#             */
/*   Updated: 2015/11/26 18:52:32 by mdelauna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_flagger_private.h"

t_bool	ft_flagger_stop(t_flagger *f, const char *av)
{
	if (av[0] == '-' && !av[1])
		return (true);
	else if (av[0] == '-' && av[1] == '-' && !av[2])
	{
		++f->cur_index;
		return (true);
	}
	else if (av[0] == '-')
		return (false);
	return (true);
}
