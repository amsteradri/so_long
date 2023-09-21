/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_graph.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgutier <adgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:56:54 by adgutier          #+#    #+#             */
/*   Updated: 2023/09/12 10:31:06 by adgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_window(t_map_values *map)
{
	map->mlx_ptr = mlx_init();
	map->win_ptr = mlx_new_window(map->mlx_ptr, (map->x * 64),
			(map->y * 64 + 2), "juego");
}

void	draw_background(t_map_values *map)
{
	void	*img_ptr;
	int		width;
	int		height;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < (map->y * 64 + 2))
	{
		i = 0;
		while (i < (map->x * 64))
		{
			img_ptr = mlx_xpm_file_to_image(map->mlx_ptr,
					"fondo2.xpm", &width, &height);
			mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, img_ptr, i, j);
			mlx_destroy_image(map->mlx_ptr, img_ptr);
			i = i + 64;
		}
		j = j + 64;
	}
}

void	init_window(t_map_values *map)
{
	create_window(map);
	draw_background(map);
	render_all(map);
	mlx_key_hook(map->win_ptr, move_character_up, map);
	mlx_hook(map->win_ptr, 17, 1L << 0, red_cross, map);
	mlx_loop(map->mlx_ptr);
}

void	draw_obstacle_one(void *mlx_ptr, void *win_ptr, int x, int y)
{
	void	*img_ptr;
	int		width;
	int		height;

	img_ptr = mlx_xpm_file_to_image(mlx_ptr, "obs1.xpm", &width, &height);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, x * 64, y * 64);
	mlx_destroy_image(mlx_ptr, img_ptr);
}

void	draw_obstacle_two(void *mlx_ptr, void *win_ptr, int x, int y)
{
	void	*img_ptr;
	int		width;
	int		height;

	img_ptr = mlx_xpm_file_to_image(mlx_ptr, "obs2.xpm", &width, &height);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, x * 64, y * 64);
	mlx_destroy_image(mlx_ptr, img_ptr);
}
