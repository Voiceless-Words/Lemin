/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rooms.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pragolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 03:55:00 by pragolan          #+#    #+#             */
/*   Updated: 2018/09/23 04:31:10 by pragolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_rooms(char **temp1, int i, t_main **ptr)
{
	(*ptr)->rooms[i]->name = ft_strdup(temp1[0]);
	(*ptr)->rooms[i]->x = ft_atoi(temp1[1]);
	(*ptr)->rooms[i]->y = ft_atoi(temp1[2]);
	i++;
	return (i);
}
