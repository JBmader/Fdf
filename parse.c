/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmader <jmader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:22:56 by jeanb             #+#    #+#             */
/*   Updated: 2025/02/17 10:30:28 by jmader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	count_words(char *str)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] && str[i] != '\n')
			count++;
		while (str[i] && str[i] != ' ')
			i++;
	}
	return (count);
}

int	parse_line(char *line, t_map *map, int y)
{
	char	**split;
	int		x;
	int		words;

	words = count_words(line);
	if (words != map->width)
		return (0);
	map->points[y] = malloc(sizeof(t_point) * map->width);
	if (!map->points[y])
		return (0);
	split = ft_split(line, ' ');
	if (!split)
		return (0);
	x = 0;
	while (x < map->width)
	{
		map->points[y][x].x = x * (800 / map->width);
		map->points[y][x].y = y * (800 / map->height);
		map->points[y][x].z = ft_atoi(split[x]) * 7;
		x++;
	}
	free_split(split);
	return (1);
}
