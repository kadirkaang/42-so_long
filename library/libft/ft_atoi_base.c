/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgoc <kgoc@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 15:27:48 by kgoc              #+#    #+#             */
/*   Updated: 2023/05/21 15:27:52 by kgoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_new_str(char *str, int base)
{
	char	*new;
	int		i;

	i = 0;
	while (ft_isdigit((int)str[i]))
		i++;
	new = malloc ((i + 1) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (str[i] >= 48 && str[i] < 48 + base)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static	char	*ft_new_str_2(char *str, int base)
{
	char	*new;
	int		i;

	i = 0;
	new = malloc (sizeof(char ) * (ft_strlen(str) + 1));
	if (!new)
		return (NULL);
	while ((str[i] >= 48 && str[i] <= '9')
		|| (str[i] >= 'a' && str[i] < 'a' + (base - 10)))
	{
		new[i] = str[i];
		i++;
	}
	if (!i)
	{
		while ((str[i] >= 48 && str[i] <= '9')
			|| (str[i] >= 'A' && str[i] < 'A' + (base - 10)))
		{
			new[i] = str[i];
			i++;
		}
	}
	new[i] = '\0';
	return (new);
}

static	int	ft_result(char *str, int base)
{
	int	i;
	int	result;
	int	base2;

	i = ft_strlen(str) - 1;
	result = 0;
	base2 = 1;
	while (i >= 0)
	{
		if (ft_isalpha(str[i]) && ft_is_capital(str[i]))
			result += ((str[i] - 'A' + 10) * base2);
		else if ((ft_isalpha(str[i]) && !ft_is_capital(str[i])))
			result += ((str[i] - 'a' + 10) * base2);
		else if (ft_isdigit((int)str[i]))
			result += (str[i] - 48) * base2;
		base2 *= base;
		i--;
	}
	return (result);
}

int	ft_atoi_base(char *str, int base)
{
	int		i;
	int		sign;
	char	*new;

	i = 0;
	sign = 1;
	while (ft_is_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (base >= 2 && base <= 10)
		new = ft_new_str(str + i, base);
	else if (base > 10 && base < 17)
		new = ft_new_str_2(str, base);
	else
		return (0);
	i = ft_result(new, base) * sign;
	free(new);
	return (i);
}
/*
int	main(void)
{
	ft_printf ("%d\n", ft_atoi_base ("-10", 2));
}
*/
