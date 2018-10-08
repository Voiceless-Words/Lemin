/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pragolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 09:53:37 by pragolan          #+#    #+#             */
/*   Updated: 2018/06/08 18:30:46 by pragolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *str)
{
	size_t	len;

	if (str == NULL)
		return (NULL);
	len = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t')
		str++;
	if (ft_strcmp(str, "") == 0)
		len = 0;
	else
		len = ft_strlen(str) - 1;
	while (str[len] == ' ' || str[len] == '\n' || str[len] == '\t')
		len--;
	return (ft_strsub(str, 0, len + 1));
}
