/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <vdeliere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:33:53 by vdeliere          #+#    #+#             */
/*   Updated: 2024/12/02 10:14:29 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*st_calloc(size_t nmemb, size_t size)
{
	size_t			total_size;
	size_t			i;
	unsigned char	*memory;

	if (size && nmemb > SIZE_MAX / size)
		return (NULL);
	total_size = nmemb * size;
	memory = (unsigned char *)malloc(total_size);
	if (!memory)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		memory[i] = 0;
		i++;
	}
	return ((void *)memory);
}

char	*st_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*st_strjoin(char const *s1, char const *s2)
{
	int		tot_size;
	int		i;
	int		j;
	char	*res;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	tot_size = st_strlen(s1, '0') + st_strlen(s2, '0') + 1;
	res = (char *)malloc(tot_size * sizeof(char));
	if (!res)
		return (NULL);
	while (s1[i] != '\0')
	{	
		res[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{	
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}

char	*append_buffer(char *basin_buffer, char *read_buffer)
{
	char	*temp;

	temp = st_strjoin(basin_buffer, read_buffer);
	free(basin_buffer);
	return (temp);
}

int	st_strlen(const char *s, char param)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (param == 'n')
	{
		while (s[i] && s[i] != '\n')
			i++;
	}
	else
	{
		while (s[i])
			i++;
	}
	return (i);
}
