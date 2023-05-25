/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgoc <kgoc@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:57:23 by kgoc              #+#    #+#             */
/*   Updated: 2023/03/29 21:57:25 by kgoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_wall(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->map_size[0])
	{
		if ((map->arr_map[0][i]) != '1')
			ft_error("Error : map wrong");
		if ((map->arr_map[map->map_size[1] - 1][i]) != '1')
			ft_error("Error : map wrong");
		i++;
	}
	while (i < map->map_size[1])
	{
		if ((map->arr_map[i][0]) != '1')
			ft_error("Error : map wrong");
		if ((map->arr_map[i][map->map_size[0] - 1]) != '1')
			ft_error("Error : map wrong");
		i++;
	}
}

int	check_obj(t_map *map, char obj)
{
	int	x;
	int	y;
	int	nbr;

	y = 0;
	nbr = 0;
	while (y < map->map_size[1])
	{
		x = 0;
		while (x < map->map_size[0])
		{
			if (map->arr_map[y][x] == obj)
				nbr++;
			x++;
		}
		y++;
	}
	return (nbr);
}

void	check_rectangular(t_map *map)
{
	int	len;
	int	y;

	len = ft_strlenn(map->arr_map[0]);
	y = 1;
	while (y < map->map_size[1])
	{
		if (len != ft_strlenn(map->arr_map[y]))
			ft_error("Error : map must be rectangular");
		y++;
	}
}

void	check_map_illegal(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->map_size[1])
	{
		x = 0;
		while (x < map->map_size[0])
		{
			if (!(map->arr_map[y][x] == 'E' || map->arr_map[y][x] == 'C'
					|| map->arr_map[y][x] == 'P' || map->arr_map[y][x] == '0'
					|| map->arr_map[y][x] == '1'))
				ft_error("Error : illegal object");
			x++;
		}
		y++;
	}
}

void	check_map(t_map *map)
{
	check_map_illegal(map);
	check_rectangular(map);
	check_wall(map);
	if (check_obj(map, 'P') != 1)
		ft_error("Error : Player must be one");
	if (check_obj(map, 'E') != 1)
		ft_error("Error : Exit must be one");
	if (check_obj(map, 'C') < 1)
		ft_error("Error : Coin must be at least one");
	ext_p_location(map);
	coin_location(map);
	is_played(map);
}
