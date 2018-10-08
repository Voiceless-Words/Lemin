/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pragolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 13:30:45 by pragolan          #+#    #+#             */
/*   Updated: 2018/06/15 11:04:31 by pragolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int		i;
	size_t	len;

	len = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0')
		dest[len++] = src[i++];
	dest[len] = '\0';
	return (dest);
}
