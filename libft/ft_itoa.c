/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pragolan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 15:00:15 by pragolan          #+#    #+#             */
/*   Updated: 2018/06/06 15:12:46 by pragolan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strsize(int n)
{
	int col;

	col = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = ((-1) * n);
		++col;
	}
	while (n > 0)
	{
		n = (n / 10);
		++col;
	}
	return (col);
}

char		*ft_itoa(int n)
{
	int		col;
	int		j;
	char	*str1;

	col = ft_strsize(n);
	if (!(str1 = (char *)ft_memalloc((col + 1) * sizeof(char))))
		return (NULL);
	if (n == 0)
		return (ft_strcpy(str1, "0"));
	if (n == -2147483648)
		return (ft_strcpy(str1, "-2147483648"));
	if (n < 0)
	{
		str1[0] = '-';
		n = ((-1) * n);
	}
	j = col;
	while (n > 0)
	{
		str1[col - 1] = ((n % 10) + '0');
		n = n / 10;
		col--;
	}
	str1[j] = '\0';
	return (str1);
}
