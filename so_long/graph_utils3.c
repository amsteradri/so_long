/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgutier <adgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:40:00 by adgutier          #+#    #+#             */
/*   Updated: 2023/03/12 14:40:00 by adgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_all(t_map_values *map)
{
	print_floor_on_map(map->mlx_ptr, map->win_ptr, map);
	print_obstacles_on_map(map->mlx_ptr, map->win_ptr, map);
	print_char_on_map(map->mlx_ptr, map->win_ptr, map);
	print_collec_on_map(map->mlx_ptr, map->win_ptr, map);
	print_exit_on_map(map->mlx_ptr, map->win_ptr, map);
}

void	print_moves(t_map_values *map)
{
	char	*moves_str;
	char	*moves;

	moves = ft_itoa(map->moves);
	moves_str = (char *)malloc(strlen("Moves:") + strlen(moves) + 1);
	if (moves_str)
	{
		strcpy(moves_str, "Moves:");
		strcat(moves_str, moves);
		mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 10, 0xFFFFFF, moves_str);
		free(moves_str);
	}
	else
	{
		printf("Error de asignación de memoria.\n");
	}
	free(moves);
}

int	is_valid_move(int fil, int col, t_map_values *map)
{
	if (fil < 0 || fil >= map->y || col < 0 || col >= map->x)
		return (0);
	if (map->map[fil][col] == '1')
		return (0);
	if (map->my_exit != 1 && map->map[fil][col] == 'E')
		return (0);
	return (1);
}

void	init_points(t_map_values *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < map->y)
	{
		j = 0;
		while (j < map->x)
		{
			if (map->map[i][j] == 'C')
			{
				map->total_points = map->total_points + 1;
			}
			j++;
		}
		i++;
	}
}

void	add_points(int fil, int col, t_map_values *map)
{
	if (map->map[fil][col] == 'C')
	{
		map->collected_points = map->collected_points + 1;
	}
	if (map->collected_points == map->total_points)
	{
		map->my_exit = 1;
	}
	if (map->map[fil][col] == 'E'
			&& (map->collected_points == map->total_points))
	{
		ft_printf("\n");
		ft_printf("..######...#######. ##........#######..##....##..######..\n");
		ft_printf(".##....##.##.....## ##.......##.....##.###...##.##....##.\n");
		ft_printf(".##.......##.....## ##.......##.....##.####..##.##.......\n");
		ft_printf("..######..##.....## ##.......##.....##.##.##.##.##...####\n");
		ft_printf(".......##.##.....## ##.......##.....##.##..####.##....##.\n");
		ft_printf(".##....##.##.....## ##.......##.....##.##...###.##....##.\n");
		ft_printf("..######...#######. ########..#######..##....##..######..\n");
		ft_printf("\n");
		end_game(map);
	}
}
