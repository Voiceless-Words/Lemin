/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pragolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 14:12:01 by pragolan          #+#    #+#             */
/*   Updated: 2018/09/27 08:56:50 by pragolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void		ft_initialize(t_rooms **ours)
{
	(*ours)->dat_h = NULL;
	(*ours)->flag = 0;
	(*ours)->x = 0;
	(*ours)->y = 0;
	(*ours)->count = 0;
	(*ours)->nbr_link = 0;
	(*ours)->ants = 0;
	(*ours)->name = NULL;
	(*ours)->visit = 0;
}

static int		ft_check_startend(char *line, int i)
{
	if (ft_strcmp(ft_strchr(line, '#'), "##start") == 0\
					|| ft_strcmp(ft_strchr(line, '#'), "##end") == 0)
		i = 0;
	else
	{
		if (ft_strchr(line, '#') != NULL)
		{
			if (ft_strcmp(ft_strchr(line, '#'), "##start") == 0\
					|| ft_strcmp(ft_strchr(line, '#'), "##end") == 0)
				i = 0;
		}
	}
	if (i == 0)
		return (0);
	return (1);
}

static void		ft_store_map(t_rooms *ours)
{
	char	*line;
	t_data	*temp;
	t_data	*dat;

	while (get_next_line(0, &line))
	{
		temp = ours->dat_h;
		dat = (t_data *)ft_memalloc(sizeof(t_data));
		dat->data = line;
		dat->next = NULL;
		if (ours->dat_h == NULL)
			ours->dat_h = dat;
		else
		{
			while (temp->next)
				temp = temp->next;
			temp->next = dat;
		}
	}
}

static int		ft_get_ants(t_rooms *ours)
{
	char	*temp;
	int		i;
	t_data	*dat;

	dat = ours->dat_h;
	i = 1;
	while (dat)
	{
		if (ft_strchr(dat->data, '#') != NULL)
			i = ft_check_startend(dat->data, i);
		else if (ft_strlen(dat->data) != 0)
		{
			ours->ants = ft_atoi(dat->data);
			temp = ft_itoa(ours->ants);
			if (ft_strcmp(temp, dat->data) != 0 || ours->ants == 0)
				i = 0;
			if (i == 0)
				return (i);
			free(temp);
			break ;
		}
		dat = dat->next;
	}
	return (ours->ants == 0 ? 0 : 1);
}

int				main(void)
{
	t_rooms	*ours;
	t_main	*ptr;
	int		nbr_rooms;
	t_data	*dat;

	dat = NULL;
	ours = (t_rooms *)ft_memalloc(sizeof(t_rooms));
	ft_initialize(&ours);
	ft_store_map(ours);
	if (ft_get_ants(ours) != 0)
	{
		if ((nbr_rooms = ft_get_rooms(ours)) >= 2)
		{
			if (ft_check_valid(ours, nbr_rooms))
			{
				if (ft_assign(ours, nbr_rooms, &ptr) == 0)
					return (0);
				else
					ft_store_link(ours, &ptr, dat);
			}
			else
				return (0);
		}
	}
	return (0);
}
