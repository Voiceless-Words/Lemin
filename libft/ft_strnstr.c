/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pragolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 11:43:43 by pragolan          #+#    #+#             */
/*   Updated: 2018/06/15 17:05:26 by pragolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t i;
	size_t len_s2;

	len_s2 = ft_strlen(str2);
	i = 0;
	if (len < len_s2 && str1 != NULL)
		return (NULL);
	while (str1[i] != '\0' && len_s2 <= len)
	{
		if (ft_memcmp(str1 + i, str2, len_s2) == 0)
			return ((char *)str1 + i);
		i++;
		len--;
	}
	if (*str2 == '\0')
		return ((char *)str1);
	return (NULL);
}
