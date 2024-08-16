/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:27:33 by mvalerio          #+#    #+#             */
/*   Updated: 2024/08/16 19:28:10 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int main(int argc, char **argv)
{
	void	*mlx;
	t_game	game;

	(void)game;
	ft_memset(&game, 0, sizeof(game));
	game.map.game = &game;
	if (argc != 2)
		print_error_0(INVALID_ARG_CNT, NULL);
	parse_map(&game.map, argv);
	// ft_printf("The player x: %d y: %d and angle: %d\n", game.map.p_orient[0], \
	// game.map.p_orient[1], game.map.p_orient[2]);
	test_print_map_struct_data(&game.map);
	// test_print_2D_array(get_cub_file_arr(argv));
	mlx = mlx_init();
}
