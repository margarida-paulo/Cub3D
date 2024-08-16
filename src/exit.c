/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:22:32 by mvalerio          #+#    #+#             */
/*   Updated: 2024/08/16 18:05:46 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	exit_program(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_list->bckg->img);
	free(game->img_list->bckg);
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	free(game->img_list);
	free(game->mlx);
	free(game);
	exit(0);
}
