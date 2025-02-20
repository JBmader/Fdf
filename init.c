/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmader <jmader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:22:56 by jeanb             #+#    #+#             */
/*   Updated: 2025/02/17 15:12:17 by jmader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	init_data(t_data *data, char *filename)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->win = NULL;
	data->map = read_map(filename);
	if (!data->map)
		return (0);
	data->offset_x = 0;
	data->offset_y = 0;
	data->img = mlx_new_image(data->mlx, 1920, 1080);
	if (!data->img)
		return (0);
	data->img_data = mlx_get_data_addr(data->img, &data->bpp, \
	&data->size_line, &data->endian);
	return (1);
}

void	init_window(t_data *data)
{
	data->win = mlx_new_window(data->mlx, 1920, 1080, "FdF");
	if (!data->win)
		clean_exit(data, 1);
}
