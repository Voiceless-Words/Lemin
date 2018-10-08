/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pragolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 15:25:32 by pragolan          #+#    #+#             */
/*   Updated: 2018/09/24 17:50:49 by pragolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdio.h>

static int	ft_check_int(char **temp1)
{
	int		nbr;
	char	*temp;
	int		i;

	i = 1;
	if (ft_strlength(temp1) == 3)
	{
		while (i < 3)
		{
			nbr = ft_atoi(temp1[i]);
			temp = ft_itoa(nbr);
			if (ft_strcmp(temp1[i], temp) != 0)
			{
				free(temp);
				return (0);
			}
			free(temp);
			i++;
		}
	}
	else
		return (0);
	return (1);
}

static int	ft_xy(char **temp1)
{
	int		i;
	char	*temp;
	int		nbr1;

	i = 1;
	if (temp1[0][0] == '#' && ft_strlength(temp1) == 3)
	{
		while (temp1[i])
		{
			nbr1 = ft_atoi(temp1[i]);
			temp = ft_itoa(nbr1);
			if (ft_strcmp(temp1[i], temp) == 0)
				i++;
			else
			{
				free(temp);
				break ;
			}
			free(temp);
		}
		if (i == 3)
			ft_free(temp1);
	}
	return ((i == 3) ? 0 : 1);
}

static int	ft_check_xy(char **temp1, t_data *dat, int *nbr_rooms, int *link)
{
	if (temp1[0][0] != '#')
	{
		if (temp1[0][0] == 'L')
			return (0);
		if (ft_strlength(temp1) == 3)
		{
			if (ft_check_int(temp1) == 0)
				return (0);
			*nbr_rooms -= 1;
		}
	}
	if (ft_strlength(temp1) == 0)
		return (0);
	if (ft_xy(temp1) == 0)
		return (0);
	if (ft_strchr(dat->data, '-') != NULL && ft_strlength(temp1) == 1)
	{
		if (*nbr_rooms != 0)
			return (0);
		*link += 1;
	}
	return (1);
}

static int	ft_check_start(char **temp1, int *c_start, int *c_end, t_data *dat)
{
	if (temp1[0][0] == '#')
	{
		if (ft_strcmp(ft_strchr(dat->data, '#'), "##start") == 0)
		{
			temp1 = ft_find_room(temp1, dat);
			if (ft_check_int(temp1) == 0)
			{
				ft_free(temp1);
				return (0);
			}
			*c_start += 1;
		}
		else if (ft_strcmp(ft_strchr(dat->data, '#'), "##end") == 0)
		{
			temp1 = ft_find_room(temp1, dat);
			if (ft_check_int(temp1) == 0)
			{
				ft_free(temp1);
				return (0);
			}
			*c_end += 1;
		}
	}
	ft_free(temp1);
	return (1);
}

int			ft_check_valid(t_rooms *ours, int nbr_rooms)
{
	int		c_start;
	int		c_end;
	char	**temp1;
	int		link;
	t_data	*dat;

	link = 0;
	c_start = 0;
	c_end = 0;
	dat = ours->dat_h;
	while (dat)
	{
		temp1 = ft_strsplit(dat->data, ' ');
		if (ft_check_start(temp1, &c_start, &c_end, dat) == 0)
			return (0);
		temp1 = ft_strsplit(dat->data, ' ');
		if (ft_check_xy(temp1, dat, &nbr_rooms, &link) == 0)
		{
			ft_free(temp1);
			return (0);
		}
		ft_free(temp1);
		dat = dat->next;
	}
	return ((c_start == 1 && c_end == 1 && link >= 1) ? 1 : 0);
}
