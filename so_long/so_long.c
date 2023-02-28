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


int main(int argc, char **argv)
{
    map_values map;
    //movidas minilibx
    //movidas minilibx


    (void)argv;
    error_agrs(argc);
    check_ext(argv[1]);
    map.map = read_map(argv[1]);
    init_vars(&map);
    hunt_letter(&map);
    // while (i < map.y) 
    // {
    //     int j = 0;
    //     while (j < map.x + 1)
    //     {
    //          printf("%d ", map.map[i][j++]);
    //     }
    //     printf("\n");
    //     i++;
    // }
    // int i = 0;
    // while(map.map[5][i])
    // {
    //     printf("%d\n", map.map[5][i]);
    //     i++;
    // }
    all_checks(&map);
    find_path(&map);
    //movidas minilibx
    init_window(&map);
    

}