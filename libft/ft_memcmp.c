/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pragolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 14:45:16 by pragolan          #+#    #+#             */
/*   Updated: 2018/06/15 18:04:24 by pragolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t len)
{
	unsigned char	*temp;
	unsigned char	*temp1;
	size_t			index;

	temp = (unsigned char *)str1;
	temp1 = (unsigned char *)str2;
	index = 0;
	if (len == 0)
		return (0);
	while (index < len - 1)
	{
		if (temp[index] == temp1[index])
		{
			index++;
		}
		else
			return (temp[index] - temp1[index]);
	}
	return (temp[index] - temp1[index]);
}
