/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:27:33 by mvalerio          #+#    #+#             */
/*   Updated: 2024/08/20 16:33:25 by mvalerio         ###   ########.fr       */
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

int main()
{
	t_game	*game;

	game = minilibx_init();
	mlx_loop_hook(game->mlx, ft_gameplay, game);
	mlx_hook(game->mlx_win, 17, 0, exit_program, game);
	mlx_hook(game->mlx_win, 3, (1L<<1), ft_key_release, game);
	mlx_hook(game->mlx_win, 2, (1L<<0), ft_key_press, game);
	mlx_loop(game->mlx);
}

