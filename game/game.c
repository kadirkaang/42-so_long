/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgoc <kgoc@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:57:46 by kgoc              #+#    #+#             */
/*   Updated: 2023/05/21 12:21:22 by kgoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(char *map_path)
{
	int		fd;
	char	**result;
	char	*str;
	char	*tmp;

	fd = open(map_path, O_RDONLY);
	tmp = get_next_line(fd);
	str = (void *)0;
	while (ft_strlenn(tmp))
	{
		str = ft_str_merge(str, tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	free(tmp);
	result = ft_split(str, '\n');
	free(str);
	close(fd);
	return (result);
}

void	create_struct(t_mlx *game)
{
	game->coin = 0;
	game->ext = 0;
	game->mlx_ptr = 0;
	game->player = 0;
	game->space = 0;
	game->wall = 0;
	game->win_ptr = 0;
	game->map = 0;
	game->counter = 0;
}

void	add_path(t_mlx *game)
{
	int	widht;
	int	height;

	game->coin = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/collectible/0.xpm", &widht, &height);
	game->ext = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/exit/0.xpm", &widht, &height);
	game->wall = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/wall/0.xpm", &widht, &height);
	game->space = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/space/0.xpm", &widht, &height);
	game->player = mlx_xpm_file_to_image(game->mlx_ptr,
			"textures/player/0.xpm", &widht, &height);
}

void	put_image(t_mlx *game, int x, int y)
{
	if (game->map->arr_map[y][x] == '1')
		mlx_put_image_to_window(game->mlx_ptr,
			game->win_ptr, game->wall, x * 64, y * 64);
	if (game->map->arr_map[y][x] == 'C')
	{
		mlx_put_image_to_window(game->mlx_ptr,
			game->win_ptr, game->coin, x * 64, y * 64);
		game->map->nbr_coin++;
	}
	if (game->map->arr_map[y][x] == 'P')
	{
		mlx_put_image_to_window(game->mlx_ptr,
			game->win_ptr, game->player, x * 64, y * 64);
		game->map->player_loc[0] = x;
		game->map->player_loc[1] = y;
	}
}
