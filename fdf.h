/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmader <jmader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:22:56 by jeanb             #+#    #+#             */
/*   Updated: 2025/02/17 15:14:16 by jmader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "./minilibx-linux/mlx.h"

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
}	t_point;

typedef struct s_map
{
	t_point	**points;
	int		width;
	int		height;
}	t_map;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_map	*map;
	int		offset_x;
	int		offset_y;
	void	*img;
	char	*img_data;
	int		bpp;
	int		size_line;
	int		endian;
}	t_data;

typedef struct s_draw
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
}	t_draw;

/* init.c */
int		init_data(t_data *data, char *filename);
void	init_window(t_data *data);

/* events.c */
int		handle_key(int keycode, t_data *data);
int		handle_close(t_data *data);

/* map.c */
t_map	*read_map(char *filename);

/* utils.c */
void	free_split(char **split);
void	free_map(t_map *map);
void	clean_exit(t_data *data, int status);

/* parse.c */
int		parse_line(char *line, t_map *map, int y);

/* draw.c */
void	draw_map(t_data *data);

/* draw_utils.c */
void	iso(int *x, int *y, int z);
void	init_draw_params(t_draw *d, t_point *start, t_point *end);
void	update_line_pos(t_draw *d, int *x, int *y);
void	clear_image(t_data *data);

#endif