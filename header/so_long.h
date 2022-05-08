/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 21:24:09 by fardath           #+#    #+#             */
/*   Updated: 2022/05/08 21:10:58 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef so_long_H
# define so_long_H

# include <mlx.h>
# include "../libft/libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

# define GAME_WON "You won!"
# define BLUE 0x008080

# define TILE_WIDTH 100

# define PLAYER 'P'
# define WALL '1'
# define EXIT 'E'
# define COUNT 'C'
# define FLOOR '0'

# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_LEFT 0
# define KEY_RIGHT 2
# define RESET 15
# define ESC 53

# define WALL_XPM "../sprait/wall.xpm"
# define PLAYER_XPM "../sprait/player.xpm"
# define FLOOR_XPM "../sprait/floor.xpm"
# define COUNT_XPM "../sprait/count.xpm"
# define EXIT_XPM "../sprait/exit.xpm"


typedef struct s_mapame_map
{
	int		map_height;
	int		map_length;
	int		player_x;
	int		player_y;
	int		game_score;
	int		max_score;
	char	**map_data;
	int		game_over;
	int		steps;
	void	*end_img;
	void	*wall;
	void	*exit;
	void	*player;
	void	*floor;
	void	*items;
	void	*enemy;
	int		*enemypos;
	void	*mlx;
	void	*win;
}	t_game_map;

int			get_map(int argc, char **argv, t_game_map *map);
int			get_filename(char *argv);
void		error(char *error_code);
int			open_file_map(char *argv, t_game_map *map, int *height);
int			get_height(char *file);
int			check_length(int *length, int height, char **map);
int			check_wall(int length, int height, char **map);
int			check_map(t_game_map *map);
int			check_player(t_game_map *map);
int			check_exit(t_game_map *map);
int			check_count(t_game_map *map);
int			check_sign(t_game_map *map);
void		free_map_data(t_game_map *map);
void		start_render(t_game_map *map);
void		put_image_to_map(t_game_map *map);
void		put_to_tile(t_game_map *map, int x, int y);
int 		key_hook(int keycode, t_game_map *map);
void		win(t_game_map *map);
int			exit_hook(t_game_map *map);
int			rewrite_map(t_game_map *map);
#endif