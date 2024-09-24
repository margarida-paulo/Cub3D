/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:34:44 by plashkar          #+#    #+#             */
/*   Updated: 2024/09/24 15:04:03 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Re-renders the screen and the minimap.
 *
 * This function is called every time the player moves.
 * It first clears the screen and the minimap images, then builds the
 * minimap and the player images and merges them. It then puts the merged
 * image on the window at position (0, 0). It then crops the minimap
 * around the player and puts it on the window at position (10, 10).
 * Finally, it syncs the mlx in order to ensure that the images are
 * properly displayed.
 *
 * @param game the game struct containing all the resources.
 * @return void
 */
void	ft_render_screen(t_game *game)
{
	ft_clear_img(game->img_list->screen, WIN_WIDTH, WIN_HEIGHT);
	ft_clear_img(game->img_list->cropped_minimap, MINIMAP_WIDTH, \
	MINIMAP_HEIGHT);
	ft_build_minimap(game);
	ft_build_player(game);
	mlx_destroy_image(game->mlx, game->current_screen->img);
	free(game->current_screen);
	game->current_screen = ft_merge_images(game, game->img_list->minimap, \
	game->img_list->player, game->origin);
	mlx_put_image_to_window(game->mlx, game->game_window, \
	game->img_list->screen->img, 0, 0);
	crop_minimap_around_player(game);
	mlx_put_image_to_window(game->mlx, game->game_window, \
	game->img_list->cropped_minimap->img, 10, 10);
	mlx_do_sync(game->mlx);
}

// void	ft_render_screen(t_game *game)
// {
// 	ft_clear_img(game->img_list->screen, WIN_WIDTH, WIN_HEIGHT);
// 	ft_clear_img(game->img_list->cropped_minimap, MINIMAP_WIDTH, MINIMAP_HEIGHT);
// 	ft_build_minimap(game);
// 	ft_build_player(game);
// 	mlx_destroy_image(game->mlx, game->current_screen->img);
// 	free(game->current_screen);
// 	game->current_screen = ft_merge_images(game, game->img_list->minimap, game->img_list->player, game->origin);
// 	// mlx_put_image_to_window(game->mlx, game->mlx_win, game->current_screen->img, 0, 0);
// 	mlx_put_image_to_window(game->mlx, game->game_window, game->img_list->screen->img, 0, 0);
// 	crop_minimap_around_player(game);
// 	 mlx_put_image_to_window(game->mlx, game->game_window, game->img_list->cropped_minimap->img, 10, 10);
// 	mlx_do_sync(game->mlx);
// }

/**
 * @brief Renders the menu screen.
 *
 * This function is called every time the game enters the menu state.
 * It first clears the window, then renders the menu options using
 * mlx_string_put() and updates the window with mlx_do_sync(). It then
 * checks the key press and changes the game state accordingly. If the
 * key press is XK_1, it changes the game state to STATE_PLAYING, and if
 * the key press is XK_2, it exits the game with exit_program().
 * @param game the game struct containing all the resources.
 * @return void
 */
void	render_menu(t_game *game)
{
	mlx_clear_window(game->mlx, game->game_window);

	mlx_string_put(game->mlx, game->game_window, 100, 100, 0xFFFFFF, "1. Start Game");
	mlx_string_put(game->mlx, game->game_window, 100, 150, 0xFFFFFF, "2. Exit");

	// Update the window
	mlx_do_sync(game->mlx);
	if (game->key_press == XK_1)
	{
		game->state = STATE_PLAYING;
		return ;
	}
	else if (game->key_press == XK_2)
		exit_program(game);
}
