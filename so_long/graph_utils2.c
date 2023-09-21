/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgutier <adgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 14:39:09 by adgutier          #+#    #+#             */
/*   Updated: 2023/03/12 14:39:09 by adgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_left(t_map_values *map)
{
	if (is_valid_move(map->fil_jp, map->col_jp - 1, map))
	{
		add_points(map->fil_jp, map->col_jp - 1, map);
		map->map[map->fil_jp][map->col_jp] = '0';
		map->col_jp--;
		map->map[map->fil_jp][map->col_jp] = 'P';
		map->moves = map->moves + 1;
	}
}

static void	move_up(t_map_values *map)
{
	if (is_valid_move(map->fil_jp - 1, map->col_jp, map))
	{
		add_points(map->fil_jp - 1, map->col_jp, map);
		map->map[map->fil_jp][map->col_jp] = '0';
		map->fil_jp--;
		map->map[map->fil_jp][map->col_jp] = 'P';
		map->moves = map->moves + 1;
	}
}

static void	move_right(t_map_values *map)
{
	if (is_valid_move(map->fil_jp, map->col_jp + 1, map))
	{
		add_points(map->fil_jp, map->col_jp + 1, map);
		map->map[map->fil_jp][map->col_jp] = '0';
		map->col_jp++;
		map->map[map->fil_jp][map->col_jp] = 'P';
		map->moves = map->moves + 1;
	}
}

static void	move_down(t_map_values *map)
{
	if (is_valid_move(map->fil_jp + 1, map->col_jp, map))
	{
		add_points(map->fil_jp + 1, map->col_jp, map);
		map->map[map->fil_jp][map->col_jp] = '0';
		map->fil_jp++;
		map->map[map->fil_jp][map->col_jp] = 'P';
		map->moves = map->moves + 1;
	}
}

int	move_character_up(int keycode, t_map_values *map)
{
	if (keycode == 0 || keycode == 123)
	{
		move_left(map);
	}
	else if (keycode == 13 || keycode == 126)
		move_up(map);
	else if (keycode == 2 || keycode == 124)
	{
		move_right(map);
	}
	else if (keycode == 1 || keycode == 125)
	{
		move_down(map);
	}
	else if (keycode == 53)
		end_game(map);
	render_all(map);
	print_moves(map);
	return (0);
}
