/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgoc <kgoc@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:30:38 by kgoc              #+#    #+#             */
/*   Updated: 2023/05/21 15:30:39 by kgoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, void const *src, size_t n)
{
	int	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	if (dest == src && !n)
		return (dest);
	while (n--)
	{
		*((unsigned char *) dest + i) = *((unsigned char *)src + i);
		i++;
	}
	return (dest);
}
