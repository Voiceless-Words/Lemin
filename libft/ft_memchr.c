/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pragolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 16:18:08 by pragolan          #+#    #+#             */
/*   Updated: 2018/06/15 18:01:23 by pragolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char *temp;

	temp = (unsigned char *)str;
	while (n)
	{
		if (*temp == (unsigned char)c)
			return ((void *)temp);
		else
		{
			n--;
			temp++;
		}
	}
	return (NULL);
}
