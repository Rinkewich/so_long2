/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 21:16:21 by fardath           #+#    #+#             */
/*   Updated: 2022/05/08 19:46:32 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	error(char *error_code)
{
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(error_code, 1);
	exit(1);
}

void free_map_data(t_game_map *map)
{
	int	count;

	count = 0;
	while (count <= map->map_height)
	{
		free(map->map_data[count]);
		count++;
	}
	free(map->map_data);
	map->map_data = NULL;
}