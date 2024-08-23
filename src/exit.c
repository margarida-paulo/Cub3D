/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:22:32 by mvalerio          #+#    #+#             */
/*   Updated: 2024/08/23 11:45:54 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_free_img(t_game *game, t_data *img)
{
	if (img != NULL)
	{
		mlx_destroy_image(game->mlx, img->img);
		free(img);
	}
}

int	exit_program(t_game *game)
{
	ft_free_img(game, game->img_list->minimap);
	ft_free_img(game, game->img_list->player);
	ft_free_img(game, game->current_screen);
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	free(game->img_list);
	free(game->mlx);
	free(game);
	exit(0);
}
