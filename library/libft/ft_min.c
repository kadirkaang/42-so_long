/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgoc <kgoc@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:30:49 by kgoc              #+#    #+#             */
/*   Updated: 2023/05/21 15:30:50 by kgoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_min(int *tab, int len)
{
	int	index;
	int	len2;
	int	total;

	total = len;
	len--;
	index = 0;
	len2 = len;
	while (len >= 0)
	{
		while (len2 >= 0)
		{
			if (tab[len] <= tab[len2])
				index++;
			if (index == total)
				return (tab[len]);
			len2--;
		}
		len2 = total - 1;
		len--;
		index = 0;
	}
	return (0);
}
