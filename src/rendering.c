/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:34:44 by plashkar          #+#    #+#             */
/*   Updated: 2024/09/26 11:39:36 by mvalerio         ###   ########.fr       */
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
	t_data	*temp;
	double	minimap_pos[2];

	minimap_pos[0] = 10;
	minimap_pos[1] = 10;
	ft_clear_img(game->img_list->screen, WIN_WIDTH, WIN_HEIGHT);
	ft_clear_img(game->img_list->cropped_minimap, \
	MINIMAP_WIDTH, MINIMAP_HEIGHT);
	ft_build_minimap(game);
	ft_build_player(game);
	mlx_destroy_image(game->mlx, game->current_screen->img);
	free(game->current_screen);
	game->current_screen = ft_merge_images(game, game->img_list->minimap, \
	game->img_list->player, game->origin);
	crop_minimap_around_player(game);
	temp = game->current_screen;
	game->current_screen = ft_merge_images(game, game->img_list->screen, \
	game->img_list->cropped_minimap, minimap_pos);
	free_img(game, temp);
	mlx_put_image_to_window(game->mlx, game->game_window, \
	game->current_screen->img, 0, 0);
	mlx_do_sync(game->mlx);
}

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
	mlx_string_put(game->mlx, game->game_window, 100, 100, 0xFFFFFF, \
	"1. Start Game");
	mlx_string_put(game->mlx, game->game_window, 100, 150, 0xFFFFFF, "2. Exit");
	mlx_do_sync(game->mlx);
	if (game->key_press == XK_1)
	{
		game->state = STATE_PLAYING;
		return ;
	}
	else if (game->key_press == XK_2)
		exit_program(game);
}
