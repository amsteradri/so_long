/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgutier <adgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:38:10 by adgutier          #+#    #+#             */
/*   Updated: 2023/03/12 14:38:10 by adgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_obstacles_on_map(void *mlx_ptr, void *win_ptr, t_map_values *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->y)
	{
		j = 0;
		while (j < map->x)
		{
			if (map->map[i][j] == '1')
			{
				if ((i + j) % 2 == 0)
				{
					draw_obstacle_one(mlx_ptr, win_ptr, j, i);
				}
				if ((i + j) % 2 == 1)
				{
					draw_obstacle_two(mlx_ptr, win_ptr, j, i);
				}
			}
			j++;
		}
		i++;
	}
}

void	print_floor_on_map(void *mlx_ptr, void *win_ptr, t_map_values *map)
{
	void	*img_ptr;
	int		width;
	int		height;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < map->y)
	{
		j = 0;
		while (j < map->x)
		{
			if (map->map[i][j] == '0')
			{
				img_ptr = mlx_xpm_file_to_image(mlx_ptr, "fondo2.xpm",
						&width, &height);
				mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr,
					j * 64, i * 64);
				mlx_destroy_image(mlx_ptr, img_ptr);
			}
			j++;
		}
		i++;
	}
}

void	print_collec_on_map(void *mlx_ptr, void *win_ptr, t_map_values *map)
{
	void	*img_ptr;
	int		width;
	int		height;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < map->y)
	{
		j = 0;
		while (j < map->x)
		{
			if (map->map[i][j] == 'C')
			{
				img_ptr = mlx_xpm_file_to_image(mlx_ptr,
						"collec1.xpm", &width, &height);
				mlx_put_image_to_window(mlx_ptr, win_ptr,
					img_ptr, j * 64, i * 64);
				mlx_destroy_image(mlx_ptr, img_ptr);
			}
			j++;
		}
		i++;
	}
}

void	print_char_on_map(void *mlx_ptr, void *win_ptr, t_map_values *map)
{
	void	*img_ptr;
	int		width;
	int		height;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < map->y)
	{
		j = 0;
		while (j < map->x)
		{
			if (map->map[i][j] == 'P')
			{
				img_ptr = mlx_xpm_file_to_image(mlx_ptr,
						"char/front.xpm", &width, &height);
				mlx_put_image_to_window(mlx_ptr, win_ptr,
					img_ptr, j * 64, i * 64);
				mlx_destroy_image(mlx_ptr, img_ptr);
			}
			j++;
		}
		i++;
	}
}

void	print_exit_on_map(void *mlx_ptr, void *win_ptr, t_map_values *map)
{
	void	*img_ptr;
	int		width;
	int		height;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < map->y)
	{
		j = 0;
		while (j < map->x)
		{
			if (map->map[i][j] == 'E')
			{
				img_ptr = mlx_xpm_file_to_image(mlx_ptr,
						"exit.xpm", &width, &height);
				mlx_put_image_to_window(mlx_ptr, win_ptr,
					img_ptr, j * 64, i * 64);
				mlx_destroy_image(mlx_ptr, img_ptr);
			}
				j++;
		}
		i++;
	}
}
