/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmader <jmader@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:22:56 by jeanb             #+#    #+#             */
/*   Updated: 2025/02/17 15:02:18 by jmader           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(t_data));
	if (argc == 2)
	{
		if (!init_data(&data, argv[1]))
			clean_exit(&data, 1);
		init_window(&data);
		draw_map(&data);
		mlx_key_hook(data.win, handle_key, &data);
		mlx_hook(data.win, 17, 0, handle_close, &data);
		mlx_loop(data.mlx);
	}
	return (0);
}
