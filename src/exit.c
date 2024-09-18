/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:22:32 by mvalerio          #+#    #+#             */
/*   Updated: 2024/09/18 19:54:22 by plashkar         ###   ########.fr       */
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

void	ft_free_wall_textures(t_game *game)
{
	int	i;
	while (i < 4)
	{
		ft_free_img(game, &game->img_list->wall[i]);
		i++;
	}
}

int	exit_program(t_game *game)
{
	ft_free_img(game, game->img_list->minimap);
	ft_free_img(game, game->img_list->player);
	ft_free_img(game, game->current_screen);
	ft_free_img(game, game->img_list->screen);
	ft_free_wall_textures(game);
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_window(game->mlx, game->game_window);
	mlx_destroy_display(game->mlx);
	free(game->img_list);
	free(game->mlx);
	exit(0);
}
