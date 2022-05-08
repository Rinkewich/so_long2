/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fardath <fardath@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 16:17:13 by fardath           #+#    #+#             */
/*   Updated: 2022/05/01 21:21:19 by fardath          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/get_next_line.h"

size_t	ft_strlen_g(const char *str)
{
	size_t	i;

	i = 0;
	while (*str != '\0')
	{
		i++;
		str++;
	}
	return (i);
}

void	*ft_memcpy_g(void *dst, const void *src, size_t n)
{
	if (!dst && !src)
		return (NULL);
	while (n--)
		((char *)dst)[n] = ((char *)src)[n];
	return (dst);
}

char	*ft_strdup_g(const char *s1)
{
	char	*scp;

	scp = (char *)malloc(ft_strlen_g(s1) + 1);
	if (scp == NULL)
		return (NULL);
	ft_memcpy_g(scp, s1, ft_strlen_g(s1) + 1);
	return (scp);
}

char	*ft_strjoin_g(char *s1, char *s2)
{
	char		*len;
	size_t		i;
	size_t		len_s1;
	size_t		len_s2;

	len_s1 = 0;
	len_s2 = 0;
	i = 0;
	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	len = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (len == NULL)
		return (NULL);
	while (s1[len_s1])
		len[i++] = ((char *)s1)[len_s1++];
	while (s2[len_s2])
		len[i++] = ((char *)s2)[len_s2++];
	len[i] = '\0';
	free(s1);
	return (len);
}

int	ft_strchr_g(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
