/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pragolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 13:27:41 by pragolan          #+#    #+#             */
/*   Updated: 2018/06/05 14:42:30 by pragolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	int i;

	i = 0;
	while (str1[i] != '\0')
	{
		if (ft_memcmp(str1 + i, str2, ft_strlen(str2)) == 0)
			return ((char *)(str1 + i));
		i++;
	}
	if (*str1 == '\0' && *str2 == '\0')
		return ((char *)str1);
	return (NULL);
}
