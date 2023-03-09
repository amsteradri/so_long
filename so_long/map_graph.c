/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_graph.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgutier <adgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:56:54 by adgutier          #+#    #+#             */
/*   Updated: 2023/03/09 14:56:31 by adgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_window(map_values *map)
{
    void *img_ptr;
    int width;
    int height;
    int i;
    int j;
    
    //Inicializa la conexión con el servidor gráfico
    map->mlx_ptr = mlx_init();
    //Crea una ventana de 500 x 500 píxeles
    map->win_ptr = mlx_new_window(map->mlx_ptr, (map->x * 64), (map->y * 64 + 2), "juego");
    //Carga la imagen desde el archivo XPM
    i = 0;
    j = 0;
    while(j < (map->y * 64 + 2))
    {
        i = 0;
        while(i < (map->x * 64))
        {
            img_ptr = mlx_xpm_file_to_image(map->mlx_ptr, "fondo2.xpm", &width, &height);
            mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, img_ptr, i, j);
            mlx_destroy_image(map->mlx_ptr, img_ptr);
            i = i + 64;
        }
        j = j + 64;
    }
    print_obstacles_on_map(map->mlx_ptr, map->win_ptr, map);
    print_char_on_map(map->mlx_ptr, map->win_ptr, map);
    print_collectables_on_map(map->mlx_ptr, map->win_ptr, map);
    print_exit_on_map(map->mlx_ptr, map->win_ptr, map);

    // mlx_hook(win_ptr, 2, 1L<<0, move_character_up, map);
    mlx_key_hook(map->win_ptr, move_character_up, map);
    

    //Muestra la imagen en la ventana
    //Mostrar la ventana
    mlx_loop(map->mlx_ptr);
        //movidas minilibx
}

void print_obstacles_on_map(void *mlx_ptr, void *win_ptr, map_values *map)
{
    void *img_ptr;
    int width;
    int height;
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (i < map->y) 
    {
        j = 0;
        while (j < map->x) 
        {
            if (map->map[i][j] == '1') 
            {
                if((i + j) % 2 == 0)
                {
                    img_ptr = mlx_xpm_file_to_image(mlx_ptr, "obs1.xpm", &width, &height);
                    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, j * 64, i * 64);
                    mlx_destroy_image(mlx_ptr, img_ptr);
                }
                if((i + j) % 2 == 1)
                {
                    img_ptr = mlx_xpm_file_to_image(mlx_ptr, "obs2.xpm", &width, &height);
                    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, j * 64, i * 64);
                    mlx_destroy_image(mlx_ptr, img_ptr);
                }
            }
            j++;
        }
        i++;
    }
}

void print_floor_on_map(void *mlx_ptr, void *win_ptr, map_values *map)
{
    void *img_ptr;
    int width;
    int height;
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (i < map->y) 
    {
        j = 0;
        while (j < map->x) 
        {
            if (map->map[i][j] == '0') 
            {
                img_ptr = mlx_xpm_file_to_image(mlx_ptr, "fondo2.xpm", &width, &height);
                mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, j * 64, i * 64);
                mlx_destroy_image(mlx_ptr, img_ptr);
            }
            j++;
        }
        i++;
    }
}

void print_collectables_on_map(void *mlx_ptr, void *win_ptr, map_values *map)
{
    void *img_ptr;
    int width;
    int height;
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (i < map->y) 
    {
        j = 0;
        while (j < map->x) 
        {
            if (map->map[i][j] == 'C') 
            {
                img_ptr = mlx_xpm_file_to_image(mlx_ptr, "collec1.xpm", &width, &height);
                mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, j * 64, i * 64);
                mlx_destroy_image(mlx_ptr, img_ptr);
            }
            j++;
        }
        i++;
    }
}

void print_char_on_map(void *mlx_ptr, void *win_ptr, map_values *map)
{
    void *img_ptr;
    int width;
    int height;
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (i < map->y) 
    {
        j = 0;
        while (j < map->x) 
        {
            if (map->map[i][j] == 'P') 
            {
                img_ptr = mlx_xpm_file_to_image(mlx_ptr, "char/front.xpm", &width, &height);
                mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, j * 64, i * 64);
                mlx_destroy_image(mlx_ptr, img_ptr);
            }
            j++;
        }
        i++;
    }
}

void print_exit_on_map(void *mlx_ptr, void *win_ptr, map_values *map)
{
    void *img_ptr;
    int width;
    int height;
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (i < map->y) 
    {
        j = 0;
        while (j < map->x) 
        {
            if (map->map[i][j] == 'E') 
            {
                img_ptr = mlx_xpm_file_to_image(mlx_ptr, "exit.xpm", &width, &height);
                mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, j * 64, i * 64);
                mlx_destroy_image(mlx_ptr, img_ptr);
            }
            j++;
        }
        i++;
    }
}

static void move_left(map_values *map)
{
    if(is_valid_move(map->fil_jp, map->col_jp - 1, map))
    {
        add_points(map->fil_jp, map->col_jp - 1, map);
        map->map[map->fil_jp][map->col_jp] = '0';
        map->col_jp--;
        map->map[map->fil_jp][map->col_jp] = 'P';
        map->moves = map->moves + 1;
        // print_map(map);
    }
}

static void move_up(map_values *map)
{
    if(is_valid_move(map->fil_jp - 1, map->col_jp, map))
    {
        add_points(map->fil_jp - 1, map->col_jp, map);
        map->map[map->fil_jp][map->col_jp] = '0';
        map->fil_jp--;
        map->map[map->fil_jp][map->col_jp] = 'P';
        map->moves = map->moves + 1;
        // print_map(map);
    }
}

static void move_right(map_values *map)
{
    if(is_valid_move(map->fil_jp, map->col_jp + 1, map))
    {
        add_points(map->fil_jp, map->col_jp + 1, map);
        map->map[map->fil_jp][map->col_jp] = '0';
        map->col_jp++;
        map->map[map->fil_jp][map->col_jp] = 'P';
        map->moves = map->moves + 1;
        // print_map(map);
    }
}

static void move_down(map_values *map)
{
    if(is_valid_move(map->fil_jp + 1, map->col_jp, map))
    {
        add_points(map->fil_jp + 1, map->col_jp, map);
        map->map[map->fil_jp][map->col_jp] = '0';
        map->fil_jp++;
        map->map[map->fil_jp][map->col_jp] = 'P';
        map->moves = map->moves + 1;
        // print_map(map);
    }
}

int move_character_up(int keycode, map_values *map)
{
    if (keycode == 0 || keycode == 123)
    {
        move_left(map);
    }
    else if (keycode == 13 || keycode == 126)
    {
        move_up(map);
    }
    else if (keycode == 2 || keycode == 124)
    {
        move_right(map);
    }
    else if (keycode == 1 || keycode == 125)
    {
        move_down(map);
    }
    else if (keycode == 53)
        end_game();
    render_all(map);
    print_moves(map);
    return (0);
}

void render_all(map_values *map)
{
    print_floor_on_map(map->mlx_ptr, map->win_ptr, map);
    print_obstacles_on_map(map->mlx_ptr, map->win_ptr, map);
    print_char_on_map(map->mlx_ptr, map->win_ptr, map);
    print_exit_on_map(map->mlx_ptr, map->win_ptr, map);
}

void print_moves(map_values *map)
{
    char moves_str[32];
    sprintf(moves_str, "Moves: %d", map->moves);
    mlx_string_put(map->mlx_ptr, map->win_ptr, 10, 10, 0xFFFFFF, moves_str);
}

// void print_map(map_values *map)
// {

//     int i;
//     int j;

//     i = 0;
//     j = 0;
    
    
//     while (i < map->y) 
//     {
//         int j = 0;
//         while (j < map->x + 1)
//         {
//             ft_printf("%c ", map->map[i][j++]);
//         }
//         printf("\n");
//         i++;
//     }
//}

int is_valid_move(int fil, int col, map_values *map)
{
    if (fil < 0 || fil >= map->y || col < 0 || col >= map->x)
        return 0;
    if (map->map[fil][col] == '1')
        return 0;
    if(map->my_exit != 1 && map->map[fil][col] == 'E')
        return 0;
    return 1;
}

void init_points(map_values *map)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (i < map->y) 
    {
        j = 0;
        while (j < map->x) 
        {
            if (map->map[i][j] == 'C') 
            {
                map->total_points = map->total_points + 1;
            }
            j++;
        }
        i++;
    }
}

void add_points(int fil, int col, map_values *map)
{
    if (map->map[fil][col] == 'C')
    {
        map->collected_points = map->collected_points + 1;
        //printf("%d\n", map->collected_points);
    }
    if(map->collected_points == map->total_points)
    {
        map->my_exit = 1;
    }
    if (map->map[fil][col] == 'E' && (map->collected_points == map->total_points))
    {
        printf("\n");
        printf("..######...#######..........##........#######..##....##..######..\n");
        printf(".##....##.##.....##.........##.......##.....##.###...##.##....##.\n");
        printf(".##.......##.....##.........##.......##.....##.####..##.##.......\n");
        printf("..######..##.....##.........##.......##.....##.##.##.##.##...####\n");
        printf(".......##.##.....##.........##.......##.....##.##..####.##....##.\n");
        printf(".##....##.##.....##.........##.......##.....##.##...###.##....##.\n");
        printf("..######...#######..#######.########..#######..##....##..######..\n");
        printf("\n");
        end_game();
    }
}
