/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:12:50 by fardath           #+#    #+#             */
/*   Updated: 2022/05/01 21:22:50 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/get_next_line.h"

char	*line_what_i_need(char *all_file)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	j = 0;
	while (all_file[i] && all_file[i] != '\n')
		i++;
	if (all_file[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = all_file[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*static_end(char *all_file)
{
	char	*del;
	size_t	i;
	size_t	j;

	i = 0;
	while (all_file[i] && all_file[i] != '\n')
		i++;
	if (all_file[i] == '\n')
		i++;
	del = (char *)malloc(sizeof(char) * (ft_strlen_g(all_file) - i) + 2);
	j = 0;
	while (all_file[i])
		del[j++] = all_file[i++];
	del[j] = '\0';
	free(all_file);
	return (del);
}

char	*read_file_to_n(int fd, char *all_file)
{
	char	res[BUFFER_SIZE + 1];
	int		len;

	len = 1;
	while (len && !ft_strchr_g(all_file))
	{
		len = read(fd, res, BUFFER_SIZE);
		if (len == -1)
			return (NULL);
		res[len] = '\0';
		all_file = ft_strjoin_g(all_file, res);
	}
	return (all_file);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*all_file[4500];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	all_file[fd] = read_file_to_n(fd, all_file[fd]);
	if (!all_file[fd])
		return (NULL);
	line = line_what_i_need(all_file[fd]);
	if (!ft_strlen_g(line))
	{
		free(line);
		if (all_file[fd])
		{
			free(all_file[fd]);
			all_file[fd] = NULL;
		}
		return (NULL);
	}
	all_file[fd] = static_end(all_file[fd]);
	return (line);
}
