/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pragolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 17:31:41 by pragolan          #+#    #+#             */
/*   Updated: 2018/06/06 15:04:57 by pragolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	if (s == NULL)
		return (NULL);
	i = 0;
	if (!(str = (char *)ft_memalloc((len + 1) * sizeof(char))))
		return (NULL);
	else
	{
		while (len)
		{
			str[i] = s[start];
			i++;
			start++;
			len--;
		}
	}
	str[i] = '\0';
	return (str);
}
