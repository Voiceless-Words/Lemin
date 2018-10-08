/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pragolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 13:23:28 by pragolan          #+#    #+#             */
/*   Updated: 2018/06/15 11:24:01 by pragolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str1, int c)
{
	size_t i;

	i = ft_strlen(str1);
	while (i > 0)
	{
		if (str1[i] == (unsigned char)c)
			return ((char *)(str1 + i));
		i--;
	}
	if (str1[0] == (unsigned char)c)
		return ((char *)(str1 + i));
	return (NULL);
}
