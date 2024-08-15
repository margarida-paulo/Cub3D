/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:22:55 by mvalerio          #+#    #+#             */
/*   Updated: 2024/08/15 17:23:10 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
