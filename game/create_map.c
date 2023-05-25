/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgoc <kgoc@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:57:13 by kgoc              #+#    #+#             */
/*   Updated: 2023/03/29 21:57:16 by kgoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ext_p_location(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->map_size[1])
	{
		x = 0;
		while (x < map->map_size[0])
		{
			if (map->arr_map[y][x] == 'E')
			{
				map->ext_loc[0] = x;
				map->ext_loc[1] = y;
			}
			if (map->arr_map[y][x] == 'P')
			{
				map->player_loc[0] = x;
				map->player_loc[1] = y;
			}
			x++;
		}
		y++;
	}
}

void	map_size(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map->arr_map[y] != (void *)0)
		y++;
	while (map->arr_map[0][x] != '\0')
		x++;
	map->map_size[0] = x;
	map->map_size[1] = y;
}

void	create_space(t_mlx *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->map_size[1])
	{
		x = 0;
		while (x < game->map->map_size[0])
		{
			if (game->map->arr_map[y][x] != '1')
				mlx_put_image_to_window(game->mlx_ptr,
					game->win_ptr, game->space, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

void	create_out_of_space(t_mlx *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map->map_size[1])
	{
		x = 0;
		while (x < game->map->map_size[0])
		{
			put_image(game, x, y);
			x++;
		}
		y++;
	}
}

void	create_map(t_mlx *game)
{
	char	*str_counter;

	game->map->nbr_coin = 0;
	create_space(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->ext, game->map->ext_loc[0] * 64, game->map->ext_loc[1] * 64);
	create_out_of_space(game);
	game->map->arr_map[game->map->ext_loc[1]][game->map->ext_loc[0]] = 'E';
	ft_printf("move : %d\n", game->counter);
	str_counter = ft_itoa(game->counter);
	mlx_string_put(game->mlx_ptr, game->win_ptr, 25,
		25, 0x00FF00, str_counter);
	free(str_counter);
}
