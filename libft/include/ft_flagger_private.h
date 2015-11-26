/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagger_private.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdelauna <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:46:35 by mdelauna          #+#    #+#             */
/*   Updated: 2015/11/26 18:46:59 by mdelauna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FLAGGER_PRIVATE_H
# define FT_FLAGGER_PRIVATE_H

# include "ft_flagger.h"

t_bool	ft_flagger_stop(t_flagger *f, const char *av);
t_bool	ft_flagger_parse_arg(t_flagger *f, const char **av);

#endif
