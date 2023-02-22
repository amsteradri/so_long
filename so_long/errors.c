/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adgutier <adgutier@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:05:53 by adgutier          #+#    #+#             */
/*   Updated: 2023/02/02 17:05:53 by adgutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void error_agrs(int argc)
{
    if(argc == 1)
    {
        ft_printf("\033[0;31mError\n\033[0m");
        ft_printf("\033[0;31mNo input file given\n\033[0m");
        ft_printf("\033[0;33mTry this format:./so_long <mapa.ber>\n\033[0m");
        exit(1);
    }
    if(argc > 2)
    {
        ft_printf("\033[0;31mError\n\033[0m");
        ft_printf("\033[0;31mToo much arguments\n\033[0m");
        ft_printf("\033[0;33mTry this format:./so_long <mapa.ber>\n\033[0m");
        exit(1);
    }
}

void default_error(void)
{
    perror("\033[1;31mERROR:\033[0m");
	exit(1);
}

void error_rect(void)
{
    ft_printf("\033[0;31mError\n\033[0m");
    ft_printf("\033[0;33mTry using a rectangular map\n\033[0m");
    exit(1);
}

void error_walls(int n)
{
    if (n == 1)
    {
        ft_printf("\033[0;31mError\n\033[0m");
        ft_printf("\033[0;33mTry a map with walls in top\n\033[0m");
        exit(1);
    }
    if (n == 2)
    {
        ft_printf("\033[0;31mError\n\033[0m");
        ft_printf("\033[0;33mTry a map with walls in the sides\n\033[0m");
        exit(1);
    }
    if (n == 3)
    {
        ft_printf("\033[0;31mError\n\033[0m");
        ft_printf("\033[0;33mTry a map with walls in top\n\033[0m");
        exit(1);
    }
}

void error_char(void)
{
    ft_printf("\033[0;31mError\n\033[0m");
    ft_printf("\033[0;33mInvalid map components\n\033[0m");
    exit(1);
}

void error_ext(void)
{
    ft_printf("\033[0;31mError\n\033[0m");
    ft_printf("\033[0;33mInvalid map extension\n\033[0m");
    exit(1);
}