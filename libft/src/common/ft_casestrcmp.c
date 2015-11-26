/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_casestrcmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelauna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:48:02 by mdelauna          #+#    #+#             */
/*   Updated: 2015/11/26 18:48:04 by mdelauna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_common.h"

int		ft_casestrcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && ft_tolower(s1[i]) == ft_tolower(s2[i]))
		++i;
	return (ft_tolower(s2[i]) - ft_tolower(s1[i]));
}
