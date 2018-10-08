/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pragolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 11:03:39 by pragolan          #+#    #+#             */
/*   Updated: 2018/06/15 17:56:50 by pragolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t len)
{
	unsigned char	*temp2;
	unsigned char	*temp;
	size_t			i;

	temp = (unsigned char *)dest;
	temp2 = (unsigned char *)src;
	i = 0;
	while (len)
	{
		if (*temp2 != (unsigned char)c)
		{
			(*temp++) = (*temp2++);
			i++;
		}
		else
		{
			*temp = *temp2;
			i++;
			return ((dest + i));
		}
		len--;
	}
	return (NULL);
}
