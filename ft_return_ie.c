/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_return_ie.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pragolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 12:22:48 by pragolan          #+#    #+#             */
/*   Updated: 2018/09/26 12:26:02 by pragolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			ft_return_ie(t_main **ptr, t_data **dat, int *i, char **temp1)
{
	temp1 = ft_strsplit((*dat)->data, ' ');
	if (ft_strlength(temp1) == 3)
	{
		(*ptr)->rooms[*i]->name = ft_strdup(temp1[0]);
		(*ptr)->rooms[*i]->x = ft_atoi(temp1[1]);
		(*ptr)->rooms[*i]->y = ft_atoi(temp1[2]);
		(*ptr)->rooms[*i]->flag = 0;
		*i += 1;
	}
	ft_free(temp1);
	return (1);
}
