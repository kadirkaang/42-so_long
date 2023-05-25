/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgoc <kgoc@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:57:28 by kgoc              #+#    #+#             */
/*   Updated: 2023/03/29 22:00:01 by kgoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../library/libft/libft.h"
# include "../library/ft_printf/ft_printf.h"
# include "../library/mlx/mlx.h"

typedef struct s_node
{
	int	x;
	int	y;
}	t_node;

typedef struct s_map
{
	int		map_size[2];
	char	**arr_map;
	int		player_loc[2];
	int		nbr_coin;
	int		ext_loc[2];
	char	**visited;
	t_node	*coin_loc;
}	t_map;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*wall;
	void	*coin;
	void	*space;
	void	*ext;
	void	*player;
	int		counter;
	t_map	*map;
}	t_mlx;

void	so_long(char *map_path);
char	**read_map(char *map_path);
void	map_size(t_map *map);
void	add_path(t_mlx *game);
void	create_struct(t_mlx *game);
void	ext_p_location(t_map *map);
void	put_image(t_mlx *game, int x, int y);
void	create_map(t_mlx *game);
void	check_wall(t_map *map);
void	check_map(t_map *map);
void	check_rectangular(t_map *map);
int		check_obj(t_map *map, char obj);
void	create_out_of_space(t_mlx *game);
void	create_space(t_mlx *game);
int		handle_key(int key, t_mlx *game);
void	arg_check(int argc, char **argv);
void	ft_error(char *str);
void	coin_location(t_map *map);
int		ft_bfs(t_map *map, t_node dest, t_node start);
void	fill_zero(t_map *map);
int		ft_close(int keycode, t_mlx *param);
void	free_and_exit(t_mlx *game);
void	check_visited_map(t_map *map, t_node *queue, t_node current, int *rear);
void	is_played(t_map *map);

#endif