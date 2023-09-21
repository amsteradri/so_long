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

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include <stdarg.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <mlx.h>

# ifndef BUFF_SIZE
#  define BUFF_SIZE BUFSIZ
# endif

typedef struct t_map_values
{
	char			**map;
	int				x;
	int				y;
	int				col_jp;
	int				fil_jp;
	int				col_fin;
	int				fil_fin;
	int				total_points;
	int				collected_points;
	int				moves;
	int				my_exit;
	void			*win_ptr;
	void			*mlx_ptr;
	struct player	*player;
}t_map_values;

typedef struct player
{
	int	y;
	int	x;
}t_player;

void	error_agrs(int argc);
void	default_error(void);
char	**read_map(char *fdmap);
int		map_height(char **map);
void	check_rect(t_map_values **map);
void	first_line(char *line, int err);
void	init_vars(t_map_values *map);
void	all_checks(t_map_values *map);
void	error_rect(void);
void	error_walls(int n);
void	error_char(void);
void	error_ext(void);
void	error_path(void);
void	end_game(t_map_values *map);
void	check_chars(t_map_values **map);
void	map_chars(char *line);
void	check_pec(t_map_values **map);
void	check_ext(char *map);
void	check_walls(t_map_values **map);
void	find_path(t_map_values *map);
void	hunt_letter(t_map_values *map);
void	init_points(t_map_values *map);
void	add_points(int fil, int col, t_map_values *map);
void	print_moves(t_map_values *map);
void	init_window(t_map_values *map);
void	create_window(t_map_values *map);
void	draw_background(t_map_values *map);
void	print_obstacles_on_map(void *mlx_ptr, void *win_ptr, t_map_values *map);
void	draw_obstacle_one(void *mlx_ptr, void *win_ptr, int x, int y);
void	draw_obstacle_two(void *mlx_ptr, void *win_ptr, int x, int y);
void	print_char_on_map(void *mlx_ptr, void *win_ptr, t_map_values *map);
void	print_collec_on_map(void *mlx_ptr, void *win_ptr, t_map_values *map);
void	print_exit_on_map(void *mlx_ptr, void *win_ptr, t_map_values *map);
int		move_character_up(int keycode, t_map_values *map);
void	print_floor_on_map(void *mlx_ptr, void *win_ptr, t_map_values *map);
void	render_all(t_map_values *map);
void	print_map(t_map_values *map);
int		move_character_up(int keycode, t_map_values *map);
int		is_valid_move(int fil, int col, t_map_values *map);
void	free_vector(char **vector, int count);
int		check_if_available(t_map_values *map, char **vector, int fil, int col);
int		red_cross(t_map_values *map);
#endif