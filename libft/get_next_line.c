/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdeliere <vdeliere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 09:33:44 by vdeliere          #+#    #+#             */
/*   Updated: 2024/12/02 10:16:58 by vdeliere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract_line(char *basin_buffer)
{
	char	*temp;
	int		i;

	if (!basin_buffer || basin_buffer[0] == '\0')
		return (NULL);
	i = st_strlen(basin_buffer, 'n');
	temp = (char *)malloc((i + 2) * sizeof(char));
	if (!temp)
		return (free(basin_buffer), NULL);
	i = 0;
	while (basin_buffer[i] && basin_buffer[i] != '\n')
	{
		temp[i] = basin_buffer[i];
		i++;
	}
	if (basin_buffer[i] == '\n')
		temp[i++] = '\n';
	temp[i] = '\0';
	return (temp);
}

char	*obtain_remaining(char *basin_buffer)
{
	char	*temp;
	char	*newline_pos;
	int		len;
	int		i;

	newline_pos = st_strchr(basin_buffer, '\n');
	if (!newline_pos)
	{
		free(basin_buffer);
		return (NULL);
	}
	newline_pos++;
	len = st_strlen(newline_pos, '0');
	temp = (char *)malloc((len + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	i = 0;
	while (newline_pos[i])
	{
		temp[i] = newline_pos[i];
		i++;
	}
	temp[i] = '\0';
	free(basin_buffer);
	return (temp);
}

static char	*read_from_file(char *basin_buffer, int fd)
{
	int		bytes_read;
	char	*cup_buffer;

	cup_buffer = (char *)st_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!cup_buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, cup_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(cup_buffer);
			return (NULL);
		}
		cup_buffer[bytes_read] = '\0';
		basin_buffer = append_buffer(basin_buffer, cup_buffer);
		if (st_strchr(basin_buffer, '\n'))
			break ;
	}
	free (cup_buffer);
	return (basin_buffer);
}

char	*get_next_line(int fd)
{
	static char	*basin_buffer;
	char		*line;

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
	{
		if (basin_buffer)
			free (basin_buffer);
		return (NULL);
	}
	if (!basin_buffer)
		basin_buffer = st_calloc(1, sizeof (char));
	basin_buffer = read_from_file(basin_buffer, fd);
	if (!basin_buffer)
		return (free(basin_buffer), NULL);
	line = extract_line(basin_buffer);
	basin_buffer = obtain_remaining(basin_buffer);
	return (line);
}

/*
int	main(void)
{
	int	fd;
	char	*next_line;

	fd = open ("test.txt", O_RDONLY);
	if (fd == -1)
		return (1);
	while ((next_line = get_next_line(fd)))
	{
		printf("%s", next_line);
		free (next_line);
	}
	close(fd);
	return (0);
}*/
