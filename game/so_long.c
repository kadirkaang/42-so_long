/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgoc <kgoc@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:57:26 by kgoc              #+#    #+#             */
/*   Updated: 2023/03/29 21:57:27 by kgoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	so_long(char *map_path)
{
	t_mlx	game;
	t_map	map;

	create_struct(&game);
	map.arr_map = read_map(map_path);
	map_size(&map);
	map.visited = read_map(map_path);
	check_map(&map);
	game.map = &map;
	game.mlx_ptr = mlx_init();
	add_path(&game);
	game.win_ptr = mlx_new_window(game.mlx_ptr, map.map_size[0] * 64,
			map.map_size[1] * 64, "PixelGame");
	create_map(&game);
	mlx_hook(game.win_ptr, 17, 0, ft_close, &game);
	mlx_hook(game.win_ptr, 2, 1L << 0, handle_key, &game);
	mlx_loop(game.mlx_ptr);
}
