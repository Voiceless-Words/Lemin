/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pragolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 12:03:53 by pragolan          #+#    #+#             */
/*   Updated: 2018/06/15 17:56:15 by pragolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned char	*temp;
	unsigned char	*temp2;

	temp = (unsigned char *)dest;
	temp2 = (unsigned char *)src;
	while (len)
	{
		(*temp++) = (*temp2++);
		len--;
	}
	return (dest);
}
