/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgoc <kgoc@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:31:26 by kgoc              #+#    #+#             */
/*   Updated: 2023/05/21 15:31:28 by kgoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *) malloc (sizeof(char) * (ft_strlen(str) + 1));
	if (!ptr)
		return (NULL);
	while (i < ft_strlen(str))
	{
		*((char *) ptr + i) = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
