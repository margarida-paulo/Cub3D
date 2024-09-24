/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:27:33 by mvalerio          #+#    #+#             */
/*   Updated: 2024/09/24 14:41:25 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(game));
	game.map.game = &game;
	if (argc != 2)
		print_error_0(INVALID_ARG_CNT, NULL);
	parse_map(&game.map, argv);
	test_print_map_struct_data(&game.map);
	minilibx_init(&game);
	mlx_loop_hook(game.mlx, ft_gameplay, &game);
	mlx_hook(game.game_window, 17, 0, exit_program, &game);
	mlx_hook(game.game_window, 3, (1L << 1), ft_key_release, &game);
	mlx_hook(game.game_window, 2, (1L << 0), ft_key_press, &game);
	mlx_loop(game.mlx);
}
