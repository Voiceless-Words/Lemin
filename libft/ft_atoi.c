/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pragolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 09:59:49 by pragolan          #+#    #+#             */
/*   Updated: 2018/08/21 12:42:30 by pragolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	value;
	int		flag;

	flag = 1;
	value = 0;
	while (*str == ' ' || ((*str) >= 9 && (*str) <= 13))
		str++;
	if (*str == '-')
	{
		flag = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		value = ((value * 10) + (*str - '0'));
		str++;
		if (value < 0 && flag == -1)
			return (0);
		else if (value < 0 && flag == 1)
			return (-1);
	}
	return (value * flag);
}
