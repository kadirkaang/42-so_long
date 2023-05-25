/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgoc <kgoc@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:29:26 by kgoc              #+#    #+#             */
/*   Updated: 2023/05/21 15:29:29 by kgoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_len(unsigned long long int nbr, int base)
{
	int	index;

	index = 0;
	if (nbr == 0)
		return (0);
	while (nbr)
	{
		nbr /= base;
		index++;
	}
	return (index - 1);
}

static	int	ft_write(char *str, int len)
{
	int	index;

	index = 0;
	while (index <= len)
		write (1, &str[index++], 1);
	free (str);
	return (len + 1);
}

int	ft_itoa_base(unsigned long long int nbr, int base, char format)
{
	int		len;
	char	*str;
	int		ret;

	len = ft_len(nbr, base);
	ret = len;
	if (nbr == 0)
	{
		write (1, "0", 1);
		return (1);
	}
	str = (char *) malloc (((len) + 20) * sizeof(char));
	if (!str)
		return (0);
	while (len >= 0 && nbr)
	{
		str[len] = (nbr % base) + 48;
		if (nbr % base > 9 && format == 'X')
			str[len] = ((nbr % base) - 10) + 'A';
		else if (nbr % base > 9 && format == 'x')
				str[len] = ((nbr % base) - 10) + 'a';
		len--;
		nbr /= base;
	}
	return (ft_write(str, ret));
}
