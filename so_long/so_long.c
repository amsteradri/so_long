/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgutier <adgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:26:47 by adgutier          #+#    #+#             */
/*   Updated: 2023/02/02 17:26:47 by adgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
// void leaks(void)
// 	{
// 	system("leaks -q so_long");
// 	}

int	main(int argc, char **argv)
{
	t_map_values	map;

	(void)argv;
	error_agrs(argc);
	check_ext(argv[1]);
	map.map = read_map(argv[1]);
	init_vars(&map);
	hunt_letter(&map);
	all_checks(&map);
	find_path(&map);
	init_points(&map);
	init_window(&map);
}
