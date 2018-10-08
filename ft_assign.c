/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pragolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 13:59:30 by pragolan          #+#    #+#             */
/*   Updated: 2018/09/27 15:49:54 by pragolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	ft_check_dup(t_main **ptr, int nbr_rooms)
{
	int i;
	int j;

	i = 1;
	while (i < nbr_rooms)
	{
		j = i;
		while (j > 0)
		{
			if ((*ptr)->rooms[j]->name == (*ptr)->rooms[j - 1]->name)
				return (0);
			j--;
		}
		i++;
	}
	return (1);
}

static int	ft_exist(char **temp1, int nbr_rooms, t_main **ptr)
{
	int i;
	int j;
	int k;

	k = 0;
	while (temp1[k])
	{
		i = 0;
		j = 0;
		while (i < nbr_rooms)
		{
			if (ft_strcmp(temp1[k], (*ptr)->rooms[i]->name) == 0)
				j++;
			i++;
		}
		if (j != 1)
			return (0);
		k++;
	}
	return (1);
}

static int	ft_check_rooms(t_rooms *ours, int nbr_rooms, t_main **ptr)
{
	char	**temp1;
	t_data	*dat;

	dat = ours->dat_h;
	if (ft_check_dup(ptr, nbr_rooms) == 0)
		return (0);
	while (dat)
	{
		temp1 = ft_strsplit(dat->data, '-');
		if (ft_strchr(dat->data, '-') != NULL && ft_strlength(temp1) == 2\
				&& temp1[0][0] != '#')
		{
			if (ft_exist(temp1, nbr_rooms, ptr) == 0)
				return (0);
		}
		ft_free(temp1);
		dat = dat->next;
	}
	return (1);
}

static void	ft_startend(t_main **ptr, t_data **dat, int *i, char **temp1)
{
	if (ft_strchr((*dat)->data, '#') != NULL)
	{
		if (ft_strcmp(ft_strchr((*dat)->data, '#'), "##start") == 0)
		{
			(*ptr)->rooms[*i]->flag = 1;
			*i = ft_return_i(ptr, temp1, dat, i);
		}
		else if (ft_strcmp(ft_strchr((*dat)->data, '#'), "##end") == 0)
		{
			(*ptr)->rooms[*i]->flag = 2;
			*i = ft_return_i(ptr, temp1, dat, i);
		}
	}
}

int			ft_assign(t_rooms *ours, int nbr_rooms, t_main **ptr)
{
	t_data	*dat;
	int		i;
	char	**temp1;

	temp1 = NULL;
	(*ptr) = (t_main *)ft_memalloc(sizeof(t_main));
	(*ptr)->rooms = (t_rooms **)ft_memalloc(sizeof(t_rooms *) * nbr_rooms);
	dat = ours->dat_h;
	(*ptr)->no_rms = nbr_rooms;
	i = -1;
	while (++i < nbr_rooms)
		(*ptr)->rooms[i] = (t_rooms *)ft_memalloc(sizeof(t_rooms));
	i = 0;
	while (dat)
	{
		if (ft_strchr(dat->data, '#') == NULL)
		{
			ft_return_ie(ptr, &dat, &i, temp1);
		}
		ft_startend(ptr, &dat, &i, temp1);
		dat = dat->next;
	}
	return (ft_check_rooms(ours, nbr_rooms, ptr) == 0 ? 0 : 1);
}
