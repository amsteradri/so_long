/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_requirements2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgutier <adgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:57:26 by adgutier          #+#    #+#             */
/*   Updated: 2023/03/12 21:57:26 by adgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_ext(char *map)
{
	int	len;

	len = ft_strlen(map);
	if (map[len - 4] != '.' && map[len - 4] != 'b'
		&& map[len - 4] != 'e' && map[len - 4] != 'r')
		error_ext();
}

static char	**create_vector(int count, int len, t_map_values *map)
{
	char	**vector;
	int		y;
	int		x;

	y = -1;
	vector = ft_calloc(count + 1, sizeof(vector));
	while (count > ++y)
	{
		x = 0;
		vector[y] = ft_calloc(len + 1, sizeof(char));
		while (len > x)
			vector[y][x++] = '0';
	}
	vector[map->fil_jp][map->col_jp] = '1';
	return (vector);
}

int	check_if_available(t_map_values *map, char **vector, int fil, int col)
{
	if ((vector[col][fil] != '1')
		&& (map->map[col][fil] != '1')
		&& (vector[col + 1][fil] == '1' || vector[col - 1][fil] == '1'
		|| vector[col][fil + 1] == '1' || vector[col][fil - 1] == '1'))
	{
		if (map->map[col][fil] == 'E')
			return (1);
		else
			return (2);
	}
	return (0);
}

static char	**check_path(t_map_values *map, int col, int fil, int mod)
{
	char	**vector;

	vector = create_vector(map->y, map->x, map);
	while (mod > 0)
	{
		mod = 0;
		col = 0;
		while (map->y - 1 > ++col)
		{
			fil = 0;
			while (map->x - 1 > ++fil)
			{
				if (check_if_available(map, vector, fil, col) == 1)
						vector[col][fil] = '2';
				else if (check_if_available(map, vector, fil, col) == 2)
				{
					mod++;
					vector[col][fil] = '1';
				}
			}
		}
	}
	return (vector);
}

void	find_path(t_map_values *game)
{
	char	**vector;
	int		col;
	int		fil;

	col = 0;
	vector = check_path(game, 0, 0, 1);
	while (game->y - 1 > ++col)
	{
		fil = 0;
		while (game->x - 1 > ++fil)
		{
			if (game->map[col][fil] == 'E' || game->map[col][fil] == 'C')
			{
				if (vector[col][fil] == '0')
					error_path();
			}
		}
	}
	free_vector(vector, game->y);
}
