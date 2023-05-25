/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgoc <kgoc@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:31:22 by kgoc              #+#    #+#             */
/*   Updated: 2023/05/21 15:31:24 by kgoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		n;
	char	a;

	a = (unsigned char) c;
	n = ft_strlen (s) + 1;
	while (n--)
	{
		if (*s == a)
		{
			return ((char *)s);
		}
		s++;
	}
	return (NULL);
}
