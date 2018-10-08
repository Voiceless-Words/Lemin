/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pragolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 15:55:56 by pragolan          #+#    #+#             */
/*   Updated: 2018/06/12 12:45:29 by pragolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char *str1;

	if (!(str1 = (unsigned char *)malloc(size)))
		return (NULL);
	ft_memset(str1, 0, size);
	return ((void *)str1);
}
