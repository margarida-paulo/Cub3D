/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:22:32 by mvalerio          #+#    #+#             */
/*   Updated: 2024/09/28 20:08:26 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Frees all the resources used by the game and exits with status 0.
 *
 * It destroys the following t_data* images:
 * minimap, player, current_screen, screen, cropped_minimap, cropped_minimap
 * It also runs free_wall_textures() and free_map_struct() to free each of the
 * resources respectively. It also destroys the window and display via mlx
 * finally it frees the pointers and exits with status 0.
 * @param game the game struct containing all the resources
 * @return 0
 */
int	exit_program(t_game *game)
{
	free_img(game, game->img_list->minimap);
	free_img(game, game->img_list->player);
	free_img(game, game->current_screen);
	free_img(game, game->img_list->screen);
	free_img(game, game->img_list->cropped_minimap);
	free_wall_textures(game);
	free_img(game, game->img_list->start_screen);
	if (game->game_window)
		mlx_destroy_window(game->mlx, game->game_window);
	mlx_destroy_display(game->mlx);
	free(game->img_list);
	free(game->mlx);
	free_map_struct(&game->map);
	exit(0);
}
