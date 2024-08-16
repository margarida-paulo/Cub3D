/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:27:33 by mvalerio          #+#    #+#             */
/*   Updated: 2024/08/16 14:28:49 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// game is the structure with the minilibx info.


int main()
{
	t_game	*game;

	game = minilibx_init();
	mlx_loop_hook(game->mlx, ft_move, game);
	mlx_hook(game->mlx_win, 17, 0, exit_program, game);
	mlx_key_hook(game->mlx_win, ft_key_press, game);
	mlx_loop(game->mlx);
}
