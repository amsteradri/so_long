/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_requirements3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgutier <adgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:58:02 by adgutier          #+#    #+#             */
/*   Updated: 2023/03/12 21:58:02 by adgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	all_checks(t_map_values *map)
{
	check_rect(&map);
	check_walls(&map);
	check_chars(&map);
	check_pec(&map);
}

void	free_vector(char **vector, int count)
{
	int	i;

	if (!vector || !(*vector))
		return ;
	i = -1;
	while (vector [++i])
		free(vector[i]);
	free(vector);
	if (count)
		count = 0;
}
