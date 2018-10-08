/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pragolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 16:29:35 by pragolan          #+#    #+#             */
/*   Updated: 2018/06/19 10:27:23 by pragolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	len;
	size_t	len1;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s2);
	len1 = ft_strlen(s1);
	result = (char *)ft_memalloc(((len + len1) + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	else
	{
		ft_strcpy(result, s1);
		ft_strcat(result, s2);
	}
	return (result);
}
