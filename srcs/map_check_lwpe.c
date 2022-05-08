/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_lwpe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:52:52 by fardath           #+#    #+#             */
/*   Updated: 2022/05/08 20:30:55 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	check_length(int *length, int height, char **map)
{
	int	l_length;
	int	h_height;

	h_height = height;
	l_length = 0;
	height--;
	*length = ft_strlen(map[height]);
	(*length)++;
	while (height--)
	{
		l_length = ft_strlen(map[height]);
		if (l_length != *length)
			return (0);
	}
	l_length--;
	if (l_length == h_height)
		return (0);
	return (1);
}

int	check_wall(int lenmapth, int height, char **map)
{
	int	i;

	i = 0;
	while (i < lenmapth - 1)
	{
		if (map[0][i] != WALL || map[height - 1][i] != WALL)
			return (0);
		i++;
	}
	i = 0;
	while (i < height)
	{
		if (map[i][0] != WALL || map[i][lenmapth - 2] != WALL)
			return (0);
		i++;
	}
	return (1);
}

int	check_player(t_game_map *map)
{
	int	count;
	int	x;
	int	y;

	count = 0;
	x = 0;
	y = 0;
	while (y < map->map_height)
	{
		while (x < map->map_length)
		{
			if (map->map_data[y][x] == PLAYER)
			{
				count++;
				map->player_x = x;
				map->player_y = y;
			}
			x++;
		}
		x = 0;
		y++;
	}
	if (count == 1)
		return (1);
	return (0);
}

int	check_exit(t_game_map *map)
{
	int	count;
	int	x;
	int	y;

	count = 0;
	x = 0;
	y = 0;
	while (y < map->map_height)
	{
		while (x < map->map_length)
		{
			if (map->map_data[y][x] == EXIT)
			{
				count++;
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (count);
}

int	check_map(t_game_map *map)
{
	if (!check_length((&map->map_length), map->map_height, map->map_data))
		return(0);
	if (!check_wall(map->map_length, map->map_height, map->map_data))
		return(0);
	if (!check_player(map))
		return(0);
	if (!check_exit(map))
		return(0);
	if (!check_count(map))
		return(0);
	if (check_sign(map))
		return(0);
	return (1);
}
