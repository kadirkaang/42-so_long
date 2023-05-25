/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgoc <kgoc@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:32:14 by kgoc              #+#    #+#             */
/*   Updated: 2023/05/21 15:32:15 by kgoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_sizer(char const *s, unsigned int start, size_t len)
{
	size_t	i;

	i = 0;
	while (s[start++] && len-- && s[i])
		i++;
	return (i + 1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	int		i;
	size_t	j;
	size_t	k;

	if (start >= ft_strlen(s) || len == 0 || ft_strlen(s) == 0)
		return (ft_strdup(""));
	if (s)
	{
		k = ft_sizer(s, start, len);
		i = 0;
		j = ft_strlen(s + start);
		substr = (char *) malloc (sizeof(char) * k);
		if (!s || !substr)
			return (NULL);
		while (len-- && j-- && s[i])
		{
			substr[i] = s[start];
			start++;
			i++;
		}
		substr[i] = '\0';
		return (substr);
	}
	return (NULL);
}
