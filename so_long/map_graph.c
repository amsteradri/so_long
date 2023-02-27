/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_graph.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgutier <adgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:56:54 by adgutier          #+#    #+#             */
/*   Updated: 2023/02/22 19:37:48 by adgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void init_window(map_values *map)
// {
//     void *mlx_ptr;
//     void *win_ptr;
//     void *img_ptr;
//     int width, height;
//     int i;
//     int j;
    

//     // Inicializa la conexión con el servidor gráfico
//     mlx_ptr = mlx_init();

//     // Crea una ventana de 500 x 500 píxeles
//     win_ptr = mlx_new_window(mlx_ptr, (map->x * 20), 500, "Imagen de fondo");

//     // Carga la imagen desde el archivo XPM
//     i = 0;
//     j = 0;
//     while(j < 500)
//     {
//         i = 0;
//         while(i < (map->x * 20))
//         {
//             img_ptr = mlx_xpm_file_to_image(mlx_ptr, "foto.xpm", &width, &height);
//             mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, i, j);
//             i = i + 20;
//         }
//         j = j + 20;
//     }
//     // Muestra la imagen en la ventana
    
//     // Mostrar la ventana
//     mlx_loop(mlx_ptr);

//         //movidas minilibx
// }