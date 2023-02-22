/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_requiremets.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgutier <adgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 10:11:47 by adgutier          #+#    #+#             */
/*   Updated: 2023/02/19 15:43:11 by adgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_rect(map_values **map)
{
    int aux;
    int index;
    int len;

    aux = 1;
    len = 1;
    if((*map)->y >= (*map)->x)
        error_rect();
    while(aux++ < (*map)->y && len < (*map)->y)
    {
		
        index = ft_strlen((*map)->map[len]) - 1;
		if(len == (*map)->y - 1)
			index = ft_strlen((*map)->map[len]);
        if(index != (*map)->x)
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


void check_walls(map_values **map)
{
	int		i;
	int 	aux;

	
	i = 1;
	aux = (*map)->y - 1;
	first_line((*map)->map[0], 1);
	while(i < aux)
	{
		if ((*map)->map[i][0] != '1' ||
			(*map)->map[i][ft_strlen((*map)->map[i]) - 2] != '1')
				error_walls(2);
				//printf("ult:%d", (*map)->map[i][ft_strlen((*map)->map[i]) - 1]);
		i++;
	}
	first_line((*map)->map[map_height((*map)->map) - 1], 3);
}

// void	map_chars(char *line)
// {
// 	int	i;

// 	i = -1;
// 	while (line[++i] != '\0' && line[i] != '\r')
// 	{
// 		if (line[i] != '0' || line[i] != '1' || line[i] != 'C' || line[i] != 'E' || line[i] != 'P')
// 			printf("%d ", line[i]);
// 			//error_char();
// 	}
// }

void check_chars(map_values **map)
{
	int y;
	int x;
	
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

void check_pec(map_values **map)
{
	int y;
	int x;
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

void check_ext(char *map)
{
	int len;

	len = ft_strlen(map);
	if(map[len - 4] != '.' && map[len - 4] != 'b' && map[len - 4] != 'e' && map[len - 4] != 'r')
		error_ext();
	
	
}

void all_checks(map_values *map)
{
    check_rect(&map);
	check_walls(&map);
	check_chars(&map);
	check_pec(&map);
	
}