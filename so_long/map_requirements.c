/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_requirements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgutier <adgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:11:47 by adgutier          #+#    #+#             */
/*   Updated: 2023/03/16 13:15:23 by adgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_rect(t_map_values **map)
{
	int	aux;
	int	index;
	int	len;

	aux = 1;
	len = 1;
	if ((*map)->y >= (*map)->x)
		error_rect();
	while (aux++ < (*map)->y && len < (*map)->y)
	{
		index = ft_strlen((*map)->map[len]);
		if (len == (*map)->y - 1)
			index = ft_strlen((*map)->map[len]);
		if (index != (*map)->x)
			error_rect();
		len++;
	}
}

void	first_line(char *line, int err)
{
	int	i;

	i = -1;
	while (line[++i] != '\0' && line[i] != '\r')
	{
		if (line[i] != '1')
			error_walls(err);
	}
}

void	check_walls(t_map_values **map)
{
	int		i;
	int		aux;

	i = 1;
	aux = (*map)->y - 1;
	first_line((*map)->map[0], 1);
	while (i < aux)
	{
		if ((*map)->map[i][0] != '1')
			error_walls(2);
		if ((*map)->map[i][ft_strlen((*map)->map[i]) - 1] != '1')
			error_walls(2);
		i++;
	}
	first_line((*map)->map[map_height((*map)->map) - 1], 3);
}

void	check_chars(t_map_values **map)
{
	int	y;
	int	x;

	y = 0;
	while (y < (*map)->y)
	{
		x = 0;
		while ((*map)->map[y][x] != '\0' && (*map)->map[y][x] != '\r')
		{
			if ((*map)->map[y][x] != '0' && (*map)->map[y][x] != '1'
				&& (*map)->map[y][x] != 'P' && (*map)->map[y][x] != 'E'
				&& (*map)->map[y][x] != 'C' && (*map)->map[y][x] != 'Y')
				error_char();
			x++;
		}
		y++;
	}
}

void	check_pec(t_map_values **map)
{
	int	y;
	int	x;
	int	let[3];

	y = 0;
	while (y < (*map)->y)
	{
		x = 0;
		while (x < (*map)->x)
		{
			if ((*map)->map[y][x] == 'P')
				let[0] = 1;
			if ((*map)->map[y][x] == 'E')
				let[1] = 1;
			if ((*map)->map[y][x] == 'C')
				let[2] = 1;
			x++;
		}
		y++;
	}
	if (let[0] != 1 || let[1] != 1 || let[2] != 1)
		error_char();
}
