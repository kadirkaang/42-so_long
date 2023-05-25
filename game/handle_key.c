/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgoc <kgoc@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:57:41 by kgoc              #+#    #+#             */
/*   Updated: 2023/03/29 21:57:43 by kgoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_mlx *game)
{
	int	x;
	int	y;

	x = game->map->player_loc[0];
	y = game->map->player_loc[1] - 1;
	if (game->map->arr_map[y][x] != '1')
	{
		if (game->map->arr_map[y][x] == 'E' && game->map->nbr_coin == 0)
			free_and_exit(game);
		game->map->arr_map[y + 1][x] = '0';
		game->map->arr_map[y][x] = 'P';
		game->counter++;
		create_map(game);
	}
}

void	move_down(t_mlx *game)
{
	int	x;
	int	y;

	x = game->map->player_loc[0];
	y = game->map->player_loc[1] + 1;
	if (game->map->arr_map[y][x] != '1')
	{
		if (game->map->arr_map[y][x] == 'E' && game->map->nbr_coin == 0)
			free_and_exit(game);
		game->map->arr_map[y - 1][x] = '0';
		game->map->arr_map[y][x] = 'P';
		game->counter++;
		create_map(game);
	}
}

void	move_left(t_mlx *game)
{
	int	x;
	int	y;

	x = game->map->player_loc[0] - 1;
	y = game->map->player_loc[1];
	if (game->map->arr_map[y][x] != '1')
	{
		if (game->map->arr_map[y][x] == 'E' && game->map->nbr_coin == 0)
			free_and_exit(game);
		game->map->arr_map[y][x + 1] = '0';
		game->map->arr_map[y][x] = 'P';
		game->counter++;
		create_map(game);
	}
}

void	move_right(t_mlx *game)
{
	int	x;
	int	y;

	x = game->map->player_loc[0] + 1;
	y = game->map->player_loc[1];
	if (game->map->arr_map[y][x] != '1')
	{
		if (game->map->arr_map[y][x] == 'E' && game->map->nbr_coin == 0)
			free_and_exit(game);
		game->map->arr_map[y][x - 1] = '0';
		game->map->arr_map[y][x] = 'P';
		game->counter++;
		create_map(game);
	}
}

int	handle_key(int key, t_mlx *game)
{
	if (key == 53)
		free_and_exit(game);
	if (key == 13)
		move_up(game);
	if (key == 0)
		move_left(game);
	if (key == 1)
		move_down(game);
	if (key == 2)
		move_right(game);
	return (0);
}
