/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_store_link.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pragolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/07 13:12:54 by pragolan          #+#    #+#             */
/*   Updated: 2018/09/27 08:52:23 by pragolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		ft_space(int i, t_main **ptr)
{
	int j;

	j = 0;
	if ((*ptr)->rooms[i]->nbr_link != 0)
	{
		(*ptr)->rooms[i]->links = (t_rooms **)ft_memalloc(sizeof(t_rooms *)\
				* (*ptr)->rooms[i]->nbr_link);
	}
}

static int		ft_count(int i, t_main **ptr, char **temp1)
{
	int k;

	k = 0;
	if (ft_strcmp(temp1[0], temp1[1]) == 0)
		return (0);
	while (k < (*ptr)->no_rms)
	{
		if (ft_strcmp((*ptr)->rooms[k]->name, temp1[1]) == 0)
		{
			if ((*ptr)->rooms[i]->count == 0)
				ft_space(i, ptr);
			(*ptr)->rooms[i]->links[(*ptr)->rooms[i]->count] = (*ptr)->rooms[k];
			if ((*ptr)->rooms[k]->count == 0)
				ft_space(k, ptr);
			(*ptr)->rooms[k]->links[(*ptr)->rooms[k]->count] = (*ptr)->rooms[i];
			(*ptr)->rooms[k]->count += 1;
			(*ptr)->rooms[i]->count += 1;
		}
		k++;
	}
	return (1);
}

static int		ft_assign_link(t_rooms *ours, t_main **ptr)
{
	int		i;
	t_data	*dat;
	char	**temp1;

	i = 0;
	while (i < (*ptr)->no_rms)
	{
		dat = ours->dat_h;
		while (dat)
		{
			temp1 = ft_strsplit(dat->data, '-');
			if (ft_strchr(dat->data, '-') != NULL && ft_strlength(temp1) == 2\
					&& (ft_strcmp((*ptr)->rooms[i]->name, temp1[0]) == 0))
				if (ft_count(i, ptr, temp1) == 0)
				{
					ft_free(temp1);
					return (0);
				}
			ft_free(temp1);
			dat = dat->next;
		}
		i++;
	}
	return (1);
}

void			ft_store_link(t_rooms *ours, t_main **ptr, t_data *dat)
{
	int		i;
	char	**temp1;

	dat = ours->dat_h;
	while (dat)
	{
		i = 0;
		temp1 = ft_strsplit(dat->data, '-');
		if (ft_strchr(dat->data, '-') != NULL && ft_strlength(temp1) == 2\
				&& temp1[0][0] != '#')
		{
			while (i < (*ptr)->no_rms)
			{
				if (ft_strcmp((*ptr)->rooms[i]->name, temp1[0]) == 0\
						|| ft_strcmp((*ptr)->rooms[i]->name, temp1[1]) == 0)
					(*ptr)->rooms[i]->nbr_link += 1;
				i++;
			}
		}
		ft_free(temp1);
		dat = dat->next;
	}
	if (ft_assign_link(ours, ptr) == 0)
		return ;
	ft_find_path1(ours, ptr);
}
