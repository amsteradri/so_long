/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgutier <adgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:41:22 by adgutier          #+#    #+#             */
/*   Updated: 2023/03/12 14:41:22 by adgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_ext(void)
{
	ft_printf("\033[0;31mError\n\033[0m");
	ft_printf("\033[0;33mInvalid map extension\n\033[0m");
	exit(1);
}

void	error_path(void)
{
	ft_printf("\033[0;31mError\n\033[0m");
	ft_printf("\033[0;33mInvalid map no possible path\n\033[0m");
	exit(1);
}

void	end_game(t_map_values *map)
{
	ft_printf("\033[0;42mGAME ENDED\n\033[0m");
	free_vector(map->map, map->y);
	exit(1);
}

int	red_cross(t_map_values *map)
{
	mlx_destroy_window(map->mlx_ptr, map->win_ptr);
	exit(0);
	return (0);
}
