/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 15:52:52 by fardath           #+#    #+#             */
/*   Updated: 2022/05/08 20:28:15 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	check_count(t_game_map *map)
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
			if (map->map_data[y][x] == COUNT)
			{
				count++;
			}
			x++;
		}
		x = 0;
		y++;
	}
	map->max_score = count;
	return (count);
}

int check_sign(t_game_map *map)
{
	int	count;
	int	x;
	int	y;
	char c;

	count = 0;
	x = 0;
	y = 0;
	while (y < map->map_height)
	{
		while (x < map->map_length - 1)
		{
			c = map->map_data[y][x];
			if (c != COUNT && c != PLAYER && c != WALL && c != EXIT && c != FLOOR)
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