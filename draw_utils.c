/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmader <jmader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:22:56 by jeanb             #+#    #+#             */
/*   Updated: 2025/02/17 15:13:57 by jmader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(int *x, int *y, int z)
{
	int	previous_x;
	int	previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

void	init_draw_params(t_draw *d, t_point *start, t_point *end)
{
	d->dx = abs(end->x - start->x);
	d->dy = abs(end->y - start->y);
	if (start->x < end->x)
		d->sx = 1;
	else
		d->sx = -1;
	if (start->y < end->y)
		d->sy = 1;
	else
		d->sy = -1;
	if (d->dx > d->dy)
		d->err = d->dx / 2;
	else
		d->err = -d->dy / 2;
}

void	update_line_pos(t_draw *d, int *x, int *y)
{
	d->e2 = d->err;
	if (d->e2 > -d->dx)
	{
		d->err -= d->dy;
		*x += d->sx;
	}
	if (d->e2 < d->dy)
	{
		d->err += d->dx;
		*y += d->sy;
	}
}

void	clear_image(t_data *data)
{
	ft_memset(data->img_data, 0, 1920 * 1080 * (data->bpp / 8));
}
