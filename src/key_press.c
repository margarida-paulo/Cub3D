/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:21:51 by mvalerio          #+#    #+#             */
/*   Updated: 2024/09/14 17:14:41 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_render_screen(t_game *game)
{
	ft_clear_img(game->img_list->screen, WIN_WIDTH, WIN_HEIGHT);
	ft_build_minimap(game);
	ft_build_player(game);
	mlx_destroy_image(game->mlx, game->current_screen->img);
	free(game->current_screen);
	game->current_screen = ft_merge_images(game, game->img_list->minimap, game->img_list->player, game->origin);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->current_screen->img, 0, 0);
	mlx_put_image_to_window(game->mlx, game->game_window, game->img_list->screen->img, 0, 0);
}

int	ft_rotate(t_game *game)
{
	if (game->key_press == XK_Right)
	{
		if (game->p_orient[2] + (SENSITVITY / 1000) > (2 * M_PI))
			game->p_orient[2] = 0;
		else
			game->p_orient[2]  += (SENSITVITY / 1000);
	}
	else if(game->key_press == XK_Left)
	{
		if (game->p_orient[2] - (SENSITVITY / 1000) > (2 * M_PI))
			game->p_orient[2] = 0;
		else
			game->p_orient[2]  -= (SENSITVITY / 1000);
	}
	return (0);
}

int	ft_key_release(int key_code, t_game *game)
{
	(void)key_code;
    game->key_press = 0;
    return 0;
}

int	ft_key_press(int key_code, t_game *game)
{
	if (key_code == XK_Escape)
		exit_program(game);
	else
		game->key_press = key_code;
	return (0);
}
