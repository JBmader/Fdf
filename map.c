/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmader <jmader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:22:56 by jeanb             #+#    #+#             */
/*   Updated: 2025/02/17 17:24:35 by jmader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_words_in_line(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i] && line[i] != '\n')
	{
		while (line[i] && line[i] == ' ')
			i++;
		if (line[i] && line[i] != '\n')
			count++;
		while (line[i] && line[i] != ' ' && line[i] != '\n')
			i++;
	}
	return (count);
}

static int	get_map_width(char *filename)
{
	int		fd;
	int		width;
	char	buffer[8192];
	int		bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	width = 0;
	bytes_read = read(fd, buffer, 8192);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		width = count_words_in_line(buffer);
		if (width > 0)
			break ;
	}
	close(fd);
	return (width);
}

static int	get_map_height(char *filename)
{
	int		fd;
	int		height;
	char	buffer[1];

	height = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	while (read(fd, buffer, 1) > 0)
		if (buffer[0] == '\n')
			height++;
	close(fd);
	return (height);
}

static t_map	*init_map_struct(char *filename)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->width = get_map_width(filename);
	map->height = get_map_height(filename);
	if (map->height < 1 || map->width < 1)
	{
		free(map);
		return (NULL);
	}
	return (map);
}

t_map	*read_map(char *filename)
{
	int		fd;
	char	*line;
	t_map	*map;
	int		i;

	fd = open(filename, O_RDONLY);
	map = init_map_struct(filename);
	if (fd < 0 || !map)
		return (free(map), NULL);
	map->points = malloc(sizeof(t_point *) * map->height);
	if (!map->points)
		return (free_map(map), NULL);
	i = 0;
	while (i < (map->height))
	{
		line = get_next_line(fd);
		if (!line || !parse_line(line, map, i++))
		{
			free(line);
			return (free_map(map), NULL);
		}
		free(line);
	}
	close(fd);
	return (map);
}
