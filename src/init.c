/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:22:55 by mvalerio          #+#    #+#             */
/*   Updated: 2024/08/28 15:33:50 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


// Initializes the instance and the window of the minilibx into the game struct.
void	minilibx_init(t_game *game) {

	game->fov = FOV;
    game->height = ft_arrlen(game->map.map_array) * GRID_SIZE;
    game->width = ft_strlen(game->map.map_array[0]) * GRID_SIZE;
    game->mlx = mlx_init();
    game->mlx_win = mlx_new_window(game->mlx, game->width, game->height, "The best Cub3D you've ever seen");
    game->img_list = malloc(sizeof(t_pics));
    game->img_list->minimap = NULL;
    game->img_list->player = NULL;
	game->p_orient[0] = game->p_orient[0] * GRID_SIZE + GRID_SIZE / 2;
	game->p_orient[1] = game->p_orient[1] * GRID_SIZE + GRID_SIZE / 2;
	game->key_press = 0;
	game->origin[0] = 0;
	game->origin[1] = 0;
    ft_build_minimap(game);
    ft_build_player(game);
	game->current_screen = ft_merge_images(game, game->img_list->minimap, game->img_list->player, game->origin);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->current_screen->img, 0, 0);
}

