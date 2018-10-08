/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pragolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 12:44:59 by pragolan          #+#    #+#             */
/*   Updated: 2018/06/15 11:06:56 by pragolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str1, int c)
{
	while (*str1 != '\0' || c == 0)
	{
		if (*str1 == (unsigned char)c)
			return ((char *)str1);
		str1++;
	}
	return (NULL);
}
