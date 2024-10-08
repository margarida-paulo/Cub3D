/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:37:00 by plashkar          #+#    #+#             */
/*   Updated: 2024/09/26 13:26:14 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	test_print_2d_map_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		ft_printf(arr[i]);
		ft_printf("\n");
		i++;
	}
}

void	test_print_map_struct_data(t_map *map)
{
	ft_printf("the start of the map is: %d\n", map->map_start);
	ft_printf("The player x: %d y: %d and angle: %d\n", \
	(int)map->game->p_orient[0], (int)map->game->p_orient[1], \
	(int)map->game->p_orient[2]);
	ft_printf("The NO string is: %s", map->no_texture);
	ft_printf("The SO string is: %s", map->so_texture);
	ft_printf("The WE string is: %s", map->we_texture);
	ft_printf("The EA string is: %s", map->ea_texture);
	ft_printf("The F_color string is: %s\n", map->f_color);
	ft_printf("The C_color string is: %s\n", map->c_color);
	ft_printf("map width: %d map height: %d\n", map->game->width, \
	map->game->height);
	ft_printf("The map is: \n");
	test_print_2d_map_array(map->map_array);
}
