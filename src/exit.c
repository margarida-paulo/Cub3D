/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:22:32 by mvalerio          #+#    #+#             */
/*   Updated: 2024/09/23 00:16:28 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"



int	exit_program(t_game *game)
{
	free_img(game, game->img_list->minimap);
	free_img(game, game->img_list->player);
	free_img(game, game->current_screen);
	free_img(game, game->img_list->screen);
	free_img(game, game->img_list->cropped_minimap);
	free_wall_textures(game);
	mlx_destroy_window(game->mlx, game->game_window);
	mlx_destroy_display(game->mlx);
	free(game->img_list);
	free(game->mlx);
	free_map_struct(&game->map);
	exit(0);
}
