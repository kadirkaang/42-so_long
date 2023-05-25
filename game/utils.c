/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgoc <kgoc@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:57:17 by kgoc              #+#    #+#             */
/*   Updated: 2023/05/21 15:23:45 by kgoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(int keycode, t_mlx *game)
{
	exit(1);
	return (0);
}

void	ft_error(char *str)
{
	ft_printf("%s\n", str);
	exit(1);
}

void	free_and_exit(t_mlx *game)
{
	int	y;

	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	y = 0;
	while (y < game->map->map_size[1])
	{
		free(game->map->arr_map[y]);
		free(game->map->visited[y]);
		y++;
	}
	free(game->map->coin_loc);
	exit(1);
}

void	coin_location(t_map *map)
{
	int		i;
	t_node	index;

	map->nbr_coin = check_obj(map, 'C');
	map->coin_loc = (t_node *)malloc(sizeof(t_node) * map->nbr_coin);
	index = (t_node){0, 0};
	i = 0;
	while (index.y < map->map_size[1] && i < map->nbr_coin)
	{
		index.x = 0;
		while (index.x < map->map_size[0])
		{
			if (map->arr_map[index.y][index.x] == 'C')
				map->coin_loc[i++] = (t_node){index.x, index.y};
			index.x++;
		}
		index.y++;
	}
}
