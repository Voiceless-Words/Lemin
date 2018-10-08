/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pragolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 12:15:36 by pragolan          #+#    #+#             */
/*   Updated: 2018/06/13 16:13:49 by pragolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	len;

	len = ft_strlen(dest);
	if (len > destsize)
		return (destsize + ft_strlen((char *)src));
	if (len < destsize)
		ft_strncat(dest, src, destsize - len - 1);
	return (len + ft_strlen((char *)src));
}
