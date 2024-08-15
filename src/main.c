/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:27:33 by mvalerio          #+#    #+#             */
/*   Updated: 2024/08/15 17:15:44 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// game is the structure with the minilibx info.

int	ft_key_press(int key_code, t_game *game)
{
	if (key_code == 0xff1b)
		exit_program(game);
	return (0);
}

int	exit_program(t_game *game)
{
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free(game);
	exit(0);
}

// Initializes the instance and the window of the minilibx into the game struct.
t_game	*minilibx_init()
{
	t_game *game = malloc(sizeof(t_game));
	if (!game)
		exit (1);
	game->height = 1000;
	game->width = 1000;
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, game->width, \
	game->height, "The best Cub3D you've ever seen");
	return (game);
}

int main()
{
	t_game	*game;
	game = minilibx_init();
	mlx_hook(game->mlx_win, 17, 0, exit_program, game);
	mlx_key_hook(game->mlx_win, ft_key_press, game);
	mlx_loop(game->mlx);
}
