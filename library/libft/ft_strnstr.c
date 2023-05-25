/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgoc <kgoc@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:32:01 by kgoc              #+#    #+#             */
/*   Updated: 2023/05/21 15:32:02 by kgoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_check(const char *a, const char *b, size_t c, size_t n)
{
	size_t	i;
	int		j;

	i = 0;
	j = c;
	while ((i < c && a[i]) && i <= n)
	{
		if (a[i] == b[i])
			j--;
		i++;
	}
	return (j);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	k;
	size_t	i;

	if (!haystack)
		return (NULL);
	if (needle[0] == '\0')
		return ((char *)haystack);
	k = ft_strlen(needle);
	if (n == 0)
		return (NULL);
	i = 0;
	while (haystack[i] && n--)
	{
		if (!ft_check(haystack + i, needle, k, n))
			return ((char *) haystack + i);
		i++;
	}
	return (NULL);
}
