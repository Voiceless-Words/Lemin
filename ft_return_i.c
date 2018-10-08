/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pragolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 17:59:20 by pragolan          #+#    #+#             */
/*   Updated: 2018/09/26 12:13:29 by pragolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_return_i(t_main **ptr, char **temp1, t_data **dat, int *i)
{
	*dat = (*dat)->next;
	temp1 = ft_strsplit((*dat)->data, ' ');
	while (temp1[0][0] == '#')
	{
		ft_free(temp1);
		*dat = (*dat)->next;
		temp1 = ft_strsplit((*dat)->data, ' ');
	}
	if (ft_strlength(temp1) == 3)
	{
		(*ptr)->rooms[*i]->name = ft_strdup(temp1[0]);
		(*ptr)->rooms[*i]->x = ft_atoi(temp1[1]);
		(*ptr)->rooms[*i]->y = ft_atoi(temp1[2]);
		*i += 1;
	}
	ft_free(temp1);
	return (*i);
}
