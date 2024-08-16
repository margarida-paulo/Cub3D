/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:27:33 by mvalerio          #+#    #+#             */
/*   Updated: 2024/08/15 19:56:39 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int argc, char **argv)
{
	void	*mlx;
	t_game	game;

	(void)game;
	if (argc != 2)
		print_error(INVALID_ARG_CNT, NULL);
	// parse_map(&game.map, argv);
	ft_printf("the map str is :%s \n", get_map_str(argv));
	mlx = mlx_init();
}
