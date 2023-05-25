/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgoc <kgoc@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:30:41 by kgoc              #+#    #+#             */
/*   Updated: 2023/05/21 15:30:43 by kgoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	if (dest == src || !n)
		return (dest);
	if (src < dest)
	{
		while (n--)
		{
			*((unsigned char *) dest + n) = *((unsigned char *) src + n);
		}
		return (dest);
	}
	else
	{
		while (n--)
		{
			*((unsigned char *) dest + i) = *((unsigned char *)src + i);
			i++;
		}
	}
	return (dest);
}
