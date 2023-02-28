/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_graph.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgutier <adgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:56:54 by adgutier          #+#    #+#             */
/*   Updated: 2023/02/28 16:37:07 by adgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void init_window(map_values *map)
{
    void *mlx_ptr;
    void *win_ptr;
    void *img_ptr;
    int width;
    int height;
    int i;
    int j;
    
    //Inicializa la conexión con el servidor gráfico
    mlx_ptr = mlx_init();
    //Crea una ventana de 500 x 500 píxeles
    win_ptr = mlx_new_window(mlx_ptr, (map->x * 64), (map->y * 64 + 2), "juego");
    //Carga la imagen desde el archivo XPM
    i = 0;
    j = 0;
    while(j < (map->y * 64 + 2))
    {
        i = 0;
        while(i < (map->x * 64))
        {
            img_ptr = mlx_xpm_file_to_image(mlx_ptr, "fondo2.xpm", &width, &height);
            mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, i, j);
            i = i + 64;
        }
        j = j + 64;
    }
    print_obstacles_on_map(mlx_ptr, win_ptr, map);
    print_char_on_map(mlx_ptr, win_ptr, map);
    mlx_hook(win_ptr, 2, 1L << 0, move_character_up, map);


    //Muestra la imagen en la ventana
    //Mostrar la ventana
    mlx_loop(mlx_ptr);
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
                }
                if((i + j) % 2 == 1)
                {
                    img_ptr = mlx_xpm_file_to_image(mlx_ptr, "obs2.xpm", &width, &height);
                    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, j * 64, i * 64);
                }
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
            }
            j++;
        }
        i++;
    }
}

int move_character_up(int keycode, map_values *map)
{
    if (keycode == 13) // La tecla 'w' tiene el código 13
    {
        // Actualiza la posición del personaje en el mapa
        map->map[map->fil_jp][map->col_jp] = '0';
        map->fil_jp--;
        map->map[map->fil_jp][map->col_jp] = 'P';

        // Vuelve a imprimir el mapa con el personaje en su nueva posición
        void *mlx_ptr = mlx_init();
        void *win_ptr = mlx_new_window(mlx_ptr, (map->x * 64), (map->y * 64 + 2), "juego");
        print_obstacles_on_map(mlx_ptr, win_ptr, map);
        print_char_on_map(mlx_ptr, win_ptr, map);
        mlx_loop(mlx_ptr);
    }
    return (0);
}

