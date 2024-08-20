/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 14:37:00 by plashkar          #+#    #+#             */
/*   Updated: 2024/08/20 17:09:19 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	test_print_2D_array(char** arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		ft_printf(arr[i]);
		i++;
	}
}

void	test_print_map_struct_data(t_map *map)
{
	ft_printf("the start of the map is: %d\n", map->map_start);
	ft_printf("The player x: %d y: %d and angle: %d\n", \
	(int)map->game->p_orient[0], (int)map->game->p_orient[1], \
	(int)map->game->p_orient[2]);
	ft_printf("The NO string is: %s\n", map->no_texture);
	ft_printf("The SO string is: %s\n", map->so_texture);
	ft_printf("The WE string is: %s\n", map->we_texture);
	ft_printf("The EA string is: %s\n", map->ea_texture);
	ft_printf("The F_color string is: %s\n", map->f_color);
	ft_printf("The C_color string is: %s\n", map->c_color);
	ft_printf("The map is: \n");
	test_print_2D_array(map->map_array);
}
