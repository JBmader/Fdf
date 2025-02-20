/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmader <jmader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:22:56 by jeanb             #+#    #+#             */
/*   Updated: 2025/02/17 15:13:42 by jmader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	init_line_draw(t_point *start, t_point *end, int *coords)
{
	coords[0] = start->x;
	coords[1] = start->y;
	iso(&coords[0], &coords[1], start->z);
	iso(&end->x, &end->y, end->z);
}

static void	set_draw_dir(t_draw *d, int start_x, int start_y, t_point *end)
{
	d->dx = abs(end->x - start_x);
	d->dy = abs(end->y - start_y);
	if (start_x < end->x)
		d->sx = 1;
	else
		d->sx = -1;
	if (start_y < end->y)
		d->sy = 1;
	else
		d->sy = -1;
	if (d->dx > d->dy)
		d->err = d->dx / 2;
	else
		d->err = -d->dy / 2;
}

static void	put_pixel_to_image(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < 1920 && y >= 0 && y < 1080)
	{
		dst = data->img_data + (y * data->size_line + x * (data->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

static void	draw_line(t_data *data, t_point start, t_point end)
{
	t_draw	d;
	int		coords[2];

	start.x += data->offset_x;
	start.y += data->offset_y;
	end.x += data->offset_x;
	end.y += data->offset_y;
	init_line_draw(&start, &end, coords);
	set_draw_dir(&d, coords[0], coords[1], &end);
	while (1)
	{
		put_pixel_to_image(data, coords[0] + 400, coords[1] + 300, 0xFFFFFF);
		if (coords[0] == end.x && coords[1] == end.y)
			break ;
		update_line_pos(&d, &coords[0], &coords[1]);
	}
}

void	draw_map(t_data *data)
{
	int		x;
	int		y;

	clear_image(data);
	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			if (x < data->map->width - 1)
				draw_line(data, data->map->points[y][x],
					data->map->points[y][x + 1]);
			if (y < data->map->height - 1)
				draw_line(data, data->map->points[y][x],
					data->map->points[y + 1][x]);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}
