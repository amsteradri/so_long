/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_interpret.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgutier <adgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:50:39 by adgutier          #+#    #+#             */
/*   Updated: 2023/02/06 15:50:39 by adgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **read_map(char *fmap)
{
    int		fd;
    char	*line;
	char	*joined_lines;

	line = "";
	joined_lines = ft_strdup("");
	fd = open(fmap, O_RDONLY);
	if (fd < 0)
		default_error();
	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
			break ;
		joined_lines = ft_strjoin(joined_lines, line);
		free(line);
	}
	free(line);
	close(fd);
	if (joined_lines[0] == '\0')
		default_error();
	return (ft_split(joined_lines, '\n'));
}


int map_height(char **map)
{
    int i;
    
    i = 0;
    while(map[i] != NULL)
        i++;
    return(i);
}

void	hunt_letter(map_values *map)
{
	int	col;
	int	fil;

	fil = -1;
	while (map->y > ++fil)
	{
		col = -1;
		while (map->map[fil][++col])
		{
			if (map->map[fil][col] == 'P')
			{
				map->col_jp = col;
				map->fil_jp = fil;
			}
			else if (map->map[fil][col] == 'E')
			{
				map->col_fin = col;
				map->fil_fin = fil;
			}
		}
	}
	return ;
}


void init_vars(map_values *map)
{
    map->y = map_height(map->map);
    map->x = ft_strlen(map->map[0]);

}