/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_rooms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pragolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 16:15:47 by pragolan          #+#    #+#             */
/*   Updated: 2018/09/10 09:46:27 by pragolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		ft_get_rooms(t_rooms *ours)
{
	int		nbr;
	char	**temp1;
	t_data	*dat;

	dat = ours->dat_h;
	nbr = 0;
	while (dat)
	{
		temp1 = ft_strsplit(dat->data, ' ');
		if (ft_strchr(dat->data, '#') == NULL)
		{
			if (ft_strlength(temp1) == 3)
				nbr++;
		}
		ft_free(temp1);
		dat = dat->next;
	}
	return (nbr);
}
