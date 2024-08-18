/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:27:33 by mvalerio          #+#    #+#             */
/*   Updated: 2024/08/18 05:27:03 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// game is the structure with the minilibx info.


int main()
{
	t_game	*game;

	game = minilibx_init();
	mlx_loop_hook(game->mlx, ft_rotate, game);
	mlx_hook(game->mlx_win, 17, 0, exit_program, game);
	mlx_hook(game->mlx_win, 3, (1L<<1), ft_key_release, game);
	mlx_hook(game->mlx_win, 2, (1L<<0), ft_key_press, game);
	mlx_loop(game->mlx);
}
