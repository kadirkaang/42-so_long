/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgoc <kgoc@student.42kocaeli.com.tr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 21:57:20 by kgoc              #+#    #+#             */
/*   Updated: 2023/03/29 21:57:21 by kgoc             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	is_played(t_map *map)
{
	int	i;

	i = 0;
	map->visited[map->player_loc[1]][map->player_loc[0]] = 'T';
	while (i < map->nbr_coin)
	{
		if (ft_bfs(map, map->coin_loc[i],
				(t_node){map->player_loc[0], map->player_loc[1]}) == -1)
			ft_error("Error : Game unplayed (coin)");
		i++;
	}
	if (ft_bfs(map, (t_node){map->ext_loc[0], map->ext_loc[1]},
		(t_node){map->player_loc[0], map->player_loc[1]}) == -1)
		ft_error("Error : Game unplayed (exit)");
}

void	fill_zero(t_map *map)
{
	t_node	index;

	index = (t_node){0, 0};
	while (index.y < map->map_size[1])
	{
		index.x = 0;
		while (index.x < map->map_size[0])
		{
			map->visited[index.y][index.x] = 'A';
			index.x++;
		}
		index.y++;
	}
}

int	ft_bfs(t_map *map, t_node dest, t_node start)
{
	t_node	*queue;
	t_node	current;
	int		front;
	int		rear;

	fill_zero(map);
	front = -1;
	rear = -1;
	queue = (t_node *)malloc(sizeof(t_node)
			* (map->map_size[0] * map->map_size[1]));
	if (!queue)
		return (0);
	queue[++rear] = start;
	while (front != rear)
	{
		current = queue[++front];
		if (current.x == dest.x && current.y == dest.y)
		{
			free(queue);
			return (1);
		}
		check_visited_map(map, queue, current, &rear);
	}
	free(queue);
	return (-1);
}

void	check_visited_map(t_map *map, t_node *queue, t_node current, int *rear)
{
	if (current.y - 1 >= 1 && map->arr_map[current.y - 1][current.x] != '1'
		&& map->visited[current.y - 1][current.x] != 'T')
	{
		map->visited[current.y - 1][current.x] = 'T';
		queue[++*rear] = (t_node){current.x, current.y - 1};
	}
	if (current.y + 1 >= 1 && map->arr_map[current.y + 1][current.x] != '1'
		&& map->visited[current.y + 1][current.x] != 'T')
	{
		map->visited[current.y + 1][current.x] = 'T';
		queue[++*rear] = (t_node){current.x, current.y + 1};
	}
	if (current.x + 1 >= 1 && map->arr_map[current.y][current.x + 1] != '1'
		&& map->visited[current.y][current.x + 1] != 'T')
	{
		map->visited[current.y][current.x + 1] = 'T';
		queue[++*rear] = (t_node){current.x + 1, current.y};
	}
	if (current.x - 1 >= 1 && map->arr_map[current.y][current.x - 1] != '1'
		&& map->visited[current.y][current.x - 1] != 'T')
	{
		map->visited[current.y][current.x - 1] = 'T';
		queue[++*rear] = (t_node){current.x - 1, current.y};
	}
}
