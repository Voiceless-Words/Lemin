/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pragolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 13:01:14 by pragolan          #+#    #+#             */
/*   Updated: 2018/09/27 08:55:34 by pragolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		ft_print(t_rooms *ours)
{
	int i;
	int j;

	j = 1;
	i = 0;
	ours->path[ours->count] = NULL;
	while (j <= ours->ants)
	{
		i = 0;
		while (ours->path[i])
		{
			ft_putchar('L');
			ft_putnbr(j);
			ft_putchar('-');
			ft_putendl(ours->path[i++]);
		}
		j++;
	}
	exit(0);
}

static void		ft_path(int i, int j, t_rooms *ours, t_main **ptr)
{
	int		k;
	char	*temp;

	temp = (*ptr)->rooms[i]->links[j]->name;
	k = 0;
	if (ft_strcmp((*ptr)->rooms[0]->name, temp) != 0)
	{
		while (k < ours->count)
		{
			if (ft_strcmp((*ptr)->rooms[i]->name, ours->path[k]) == 0)
				ours->count = k + 1;
			k++;
		}
		if (ft_strcmp((*ptr)->rooms[0]->name, (*ptr)->rooms[i]->name) == 0)
			ours->count = 0;
		ours->path[ours->count] = ((*ptr)->rooms[i]->links[j]->name);
		ours->count++;
	}
}

static void		ft_return_r(t_main **ptr, char *temp, int *i, int *j)
{
	*i = 0;
	while (ft_strcmp(temp, (*ptr)->rooms[*i]->name) != 0\
			&& *i < (*ptr)->no_rms)
		*i += 1;
	*j = 0;
}

void			ft_recursive(t_main **ptr, t_rooms *ours, int i, int j)
{
	char	*temp;
	char	*temp2;

	if ((*ptr)->rooms[i]->links[j]->visit == 0\
			&& j < (*ptr)->rooms[i]->nbr_link)
	{
		ft_path(i, j, ours, ptr);
		(*ptr)->rooms[i]->links[j]->visit = 1;
		temp2 = (*ptr)->rooms[i]->name;
		if ((*ptr)->rooms[i]->links[j]->flag == 2)
			ft_print(ours);
		else
		{
			temp = (*ptr)->rooms[i]->links[j]->name;
			ft_return_r(ptr, temp, &i, &j);
			if (ft_strcmp(temp2, (*ptr)->rooms[i]->links[j]->name) == 0\
					&& j < (*ptr)->rooms[i]->nbr_link)
				j++;
			if (j < (*ptr)->rooms[i]->nbr_link)
				ft_recursive(ptr, ours, i, j);
		}
	}
	j++;
	if (j < (*ptr)->rooms[i]->nbr_link)
		ft_recursive(ptr, ours, i, j);
}

int				ft_find_path1(t_rooms *ours, t_main **ptr)
{
	int		i;
	int		j;
	t_rooms	*temp;

	i = 0;
	while ((*ptr)->rooms[i]->flag != 1)
		i++;
	temp = (*ptr)->rooms[i];
	(*ptr)->rooms[i] = (*ptr)->rooms[0];
	(*ptr)->rooms[0] = temp;
	i = 0;
	j = 0;
	ours->count = 0;
	ours->path = (char **)ft_memalloc(sizeof(char *) * (*ptr)->no_rms);
	while (j < (*ptr)->rooms[0]->nbr_link)
	{
		i = 0;
		ft_recursive(ptr, ours, i, j);
		j++;
	}
	return (0);
}
