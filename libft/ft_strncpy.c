/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pragolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 11:26:48 by pragolan          #+#    #+#             */
/*   Updated: 2018/06/15 18:10:43 by pragolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t length)
{
	size_t i;

	i = 0;
	while (src[i] != '\0' && i < length)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < length)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
