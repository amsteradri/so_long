/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgutier <adgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:29:07 by adgutier          #+#    #+#             */
/*   Updated: 2023/02/02 12:29:07 by adgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
#ifndef BUFF_SIZE
# define BUFF_SIZE BUFSIZ
#endif

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include <stdarg.h>
# include "libft/libft.h"
# include <fcntl.h>
#include <mlx.h>


typedef struct map_values
{
    char **map;
    int x;
    int y;
    int col_jp;
    int fil_jp;
    int col_fin;
    int fil_fin;
    int total_points;
    int collected_points;
    int moves;
    int my_exit;
    void *win_ptr;
    void *mlx_ptr;
    struct player *player;

}map_values;

typedef struct player
{
    int y;
    int x;
}player;


void    error_agrs(int argc);
void    default_error(void);
char    **read_map(char *fdmap);
int     map_height(char **map);
void    check_rect(map_values **map);
void	first_line(char *line, int err);
void    init_vars(map_values *map);
void    all_checks(map_values *map);
void    error_rect(void);
void    error_walls(int n);
void    error_char(void);
void    error_ext(void);
void    error_path(void);
void    end_game(void);
void    check_chars(map_values **map);
void	map_chars(char *line);
void    check_pec(map_values **map);
void    check_ext(char *map);
void	find_path(map_values *map);
void	hunt_letter(map_values *map);
void    init_points(map_values *map);
void    add_points(int fil, int col, map_values *map);
void    print_moves(map_values *map);

void init_window(map_values *map);
// void render_obs(map_values *map, void *mlx_ptr, void *win_ptr, void *img_ptr);
void print_obstacles_on_map(void *mlx_ptr, void *win_ptr, map_values *map);
void print_char_on_map(void *mlx_ptr, void *win_ptr, map_values *map);
void print_collectables_on_map(void *mlx_ptr, void *win_ptr, map_values *map);
void print_exit_on_map(void *mlx_ptr, void *win_ptr, map_values *map);
int move_character_up(int keycode, map_values *map);
void print_floor_on_map(void *mlx_ptr, void *win_ptr, map_values *map);
void render_all(map_values *map);
void print_map(map_values *map);
int move_character_up(int keycode, map_values *map);
int is_valid_move(int fil, int col, map_values *map);



#endif