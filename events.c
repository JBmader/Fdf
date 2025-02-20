/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmader <jmader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:22:56 by jeanb             #+#    #+#             */
/*   Updated: 2025/02/17 15:08:58 by jmader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_key(int keycode, t_data *data)
{
	if (keycode == 65307)
		clean_exit(data, 0);
	if (keycode == 65361)
		data->offset_x += 10;
	if (keycode == 65362)
		data->offset_y += 10;
	if (keycode == 65363)
		data->offset_x -= 10;
	if (keycode == 65364)
		data->offset_y -= 10;
	draw_map(data);
	return (0);
}

int	handle_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}
