/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mapo_to.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:35:47 by fardath           #+#    #+#             */
/*   Updated: 2022/05/08 19:40:07 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"
void	win(t_game_map *map)
{
	map->steps++;
	printf("%d\nwin\n", map->steps);
	mlx_clear_window(map->mlx, map->win);
	exit (0);
}
static void	go_y(t_game_map *map, int dir)
{
	if (map->map_data[map->player_y - dir][map->player_x] != '1')
	{
		if (map->map_data[map->player_y - dir][map->player_x] == '0')
		{
			map->map_data[map->player_y - dir][map->player_x] = 'P';
			map->map_data[map->player_y][map->player_x] = '0';
		}
		if (map->map_data[map->player_y - dir][map->player_x] == 'C')
		{
			map->map_data[map->player_y - dir][map->player_x] = 'P';
			map->map_data[map->player_y][map->player_x] = '0';
			map->max_score--;
		}
		if (map->map_data[map->player_y - dir][map->player_x] == 'E' && map->max_score == 0)
			win(map);
		if (map->map_data[map->player_y - dir][map->player_x] != 'E')
			map->steps++;
		map->player_y--;
		printf("%d\n", map->steps);
	}
}

static void	go_x(t_game_map *map, int dir)
{
	if (map->map_data[map->player_y][map->player_x - dir] != '1')
	{
		if (map->map_data[map->player_y][map->player_x - dir] == '0')
		{
			map->map_data[map->player_y][map->player_x - dir] = 'P';
			map->map_data[map->player_y][map->player_x] = '0';
		}
		if (map->map_data[map->player_y][map->player_x - dir] == 'C')
		{
			map->map_data[map->player_y][map->player_x - dir] = 'P';
			map->map_data[map->player_y][map->player_x] = '0';
			map->max_score--;
		}
		if (map->map_data[map->player_y][map->player_x - dir] == 'E' && map->max_score == 0)
			win(map);
		if (map->map_data[map->player_y][map->player_x - dir] != 'E')
			map->steps++;
		map->player_x--;
		printf("%d\n", map->steps);
	}
}

int	exit_hook(t_game_map *map)
{
	free(map);
	exit (0);
}
int key_hook(int keycode, t_game_map *map)
{
	if (keycode == KEY_DOWN)
		go_y(map, -1);
	if (keycode == KEY_UP)
		go_y(map, 1);
	if (keycode == KEY_RIGHT)
		go_x(map, -1);
	if (keycode == KEY_LEFT)
		go_x(map, 1);
	return (0);
}