/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgoc <kgoc@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:57:37 by kgoc              #+#    #+#             */
/*   Updated: 2023/05/21 15:01:01 by kgoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	arg_check(int argc, char **argv)
{
	if (argc == 1)
		ft_error("Error: no map");
	if (argc > 2)
		ft_error("Error: too many arguments");
	if (!ft_strnstr(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4))
		ft_error("Error: incorrect extension");
}

int	main(int argc, char **argv)
{
	arg_check(argc, argv);
	so_long(argv[1]);
	return (0);
}
