/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_room.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pragolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 17:40:26 by pragolan          #+#    #+#             */
/*   Updated: 2018/09/24 17:48:47 by pragolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char		**ft_find_room(char **temp1, t_data *dat)
{
	t_data *temp;

	temp = dat;
	while (temp1[0][0] == '#')
	{
		ft_free(temp1);
		temp = temp->next;
		temp1 = ft_strsplit(temp->data, ' ');
	}
	return (temp1);
}
