/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_mapet.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 21:16:04 by fardath           #+#    #+#             */
/*   Updated: 2022/05/02 21:10:01 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	mapet_height(char *file)
{
	int		height;
	int		fd;
	char	*str;

	height = 0;
	str = NULL;
	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	while (str != NULL)
	{
		height++;
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (height);
}

int	open_file_map(char *argv, t_game_map *map, int *height)
{
	int		fd;
	char	*str;
	int		i;

	str = NULL;
	i = 0;
	*height = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (0);
	map->map_data = (char **)malloc(sizeof(char *) * (mapet_height(argv) + 1));
	if (!(map->map_data))
		return (0);
	str = get_next_line(fd);
	while (str)
	{
		map->map_data[(*height)++] = ft_strdup(str);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	map->map_data[*height] = NULL;
	close(fd);
	return (1);
}

int	get_filename(char *argv)
{
	const char	*result;

	result = (const char *) &argv[(ft_strlen(argv) - 4)];
	if (ft_strncmp(result, ".ber", 4) == 0)
		return (1);
	else
		return (0);
}

int	get_map(int argc, char **argv, t_game_map *map)
{
	int	map_length;
	int	map_height;

	if (get_filename(argv[1]) || !map)
	{	
		if (!open_file_map(argv[1], map, &(map->map_height)))
		{
			free(map);
			map = NULL;
			error("Internal error");
			return (0);
		}
		if (check_map(map))
			return(1);
		error("Invalid map");
		free_map_data(map);
	}
	error("Invalid file name");
	map->map_data = NULL;
	free(map);
	map = NULL;
	return(0);
}
