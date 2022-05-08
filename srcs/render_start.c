/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_start.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 19:01:58 by fardath           #+#    #+#             */
/*   Updated: 2022/05/08 21:26:09 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	put_to_tile(t_game_map *map, int x, int y)
{
	if (map->map_data[y][x] == WALL)
		mlx_put_image_to_window(map->mlx, map->win, map->wall,
			x * TILE_WIDTH, y * TILE_WIDTH);
	if (map->map_data[y][x] == EXIT)
		mlx_put_image_to_window(map->mlx, map->win, map->exit,
			x * TILE_WIDTH, y * TILE_WIDTH);
	if (map->map_data[y][x] == PLAYER)
		mlx_put_image_to_window(map->mlx, map->win, map->player,
			x * TILE_WIDTH,y * TILE_WIDTH);
	if (map->map_data[y][x] == FLOOR)
		mlx_put_image_to_window(map->mlx, map->win, map->floor,
			x * TILE_WIDTH, y * TILE_WIDTH);
	if (map->map_data[y][x] == COUNT)
		mlx_put_image_to_window(map->mlx, map->win, map->items,
			x * TILE_WIDTH, y * TILE_WIDTH);
}

void	put_image_to_map(t_game_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->map_height)
	{
		x = 0;
		while (x < map->map_length)
		{
			put_to_tile(map, x, y);
			x++;
		}
		y++;
	}
}

static void	take_image(t_game_map *map)
{
	int	x;

	x = TILE_WIDTH;
	map->player = mlx_xpm_file_to_image(map->mlx, PLAYER_XPM, &x, &x);
	map->items = mlx_xpm_file_to_image(map->mlx, COUNT_XPM, &x, &x);
	map->wall = mlx_xpm_file_to_image(map->mlx, WALL_XPM, &x, &x);
	map->floor = mlx_xpm_file_to_image(map->mlx, FLOOR_XPM, &x, &x);
	map->exit = mlx_xpm_file_to_image(map->mlx, EXIT_XPM, &x, &x);
}

int	rewrite_map(t_game_map *map)
{
	mlx_clear_window(map->mlx, map->win);
	put_image_to_map(map);
	return (0);
}

void	start_render(t_game_map *map)
{
	map->mlx = mlx_init();
	map->win = mlx_new_window(map->mlx, map->map_length * TILE_WIDTH,
			map->map_height * TILE_WIDTH, "so_long");
	take_image(map);
	put_image_to_map(map);
	//mlx_hook(map->win, 02, 0, key_hook, map);
	//mlx_hook(map->win, 17, 0, exit_hook, map);
	//mlx_loop_hook(map->mlx, rewrite_map, map);
	mlx_loop(map->mlx);
}
