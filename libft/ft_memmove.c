/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pragolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 14:13:11 by pragolan          #+#    #+#             */
/*   Updated: 2018/06/08 12:02:38 by pragolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char *temp;
	unsigned char *temp1;

	temp1 = (unsigned char *)src;
	temp = (unsigned char *)dest;
	if (temp > temp1)
	{
		while (len--)
			(temp[len]) = (temp1[len]);
	}
	else
		ft_memcpy(temp, temp1, len);
	return (dest);
}
