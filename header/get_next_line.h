/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:11:00 by fardath           #+#    #+#             */
/*   Updated: 2022/05/08 20:46:13 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "so_long.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);
size_t	ft_strlen_g( const char *str);
void	*ft_memcpy_g(void *dst, const void *src, size_t n);
char	*ft_strdup_g(const char *s1);
char	*ft_strjoin_g(char *s1, char *s2);
int		ft_strchr_g(char *s);
char	*line_what_i_need(char *all_file);
char	*static_end(char *all_file);
char	*read_file_to_n(int fd, char *all_file);
#endif