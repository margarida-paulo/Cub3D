/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:27:33 by mvalerio          #+#    #+#             */
/*   Updated: 2024/08/30 15:20:47 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// game is the structure with the minilibx info.

int	ft_gameplay(t_game *game)
{
	if (game->key_press == XK_Right || game->key_press == XK_Left)
		ft_rotate(game);
	else if (game->key_press == XK_w || game->key_press == XK_a || \
	game->key_press == XK_s || game->key_press == XK_d)
		ft_move(game);
	return (0);
}

int main(int argc, char **argv)
{
	t_game	game;

	(void)game;
	ft_memset(&game, 0, sizeof(game));
	game.map.game = &game;
	if (argc != 2)
		print_error_0(INVALID_ARG_CNT, NULL);
	parse_map(&game.map, argv);


	minilibx_init(&game);
	mlx_loop_hook(game.mlx, ft_gameplay, &game);
	mlx_hook(game.mlx_win, 17, 0, exit_program, &game);
	mlx_hook(game.mlx_win, 3, (1L<<1), ft_key_release, &game);
	mlx_hook(game.mlx_win, 2, (1L<<0), ft_key_press, &game);
	mlx_loop(game.mlx);
}

