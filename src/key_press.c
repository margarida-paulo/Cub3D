/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:21:51 by mvalerio          #+#    #+#             */
/*   Updated: 2024/08/21 18:15:06 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_rotate(t_game *game)
{
	if (game->key_press == XK_Right)
	{
		if (game->p_orient[2] + 0.001 > (2 * M_PI))
			game->p_orient[2] = 0;
		else
			game->p_orient[2]  += 0.001;
		ft_build_minimap(game);
		ft_build_player(game);
    	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_list->player->img, 10, 10);
	}
	else if(game->key_press == XK_Left)
	{
		if (game->p_orient[2] - 0.001 > (2 * M_PI))
			game->p_orient[2] = 0;
		else
			game->p_orient[2]  -= 0.001;
		ft_build_minimap(game);
		ft_build_player(game);
    	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_list->player->img, 10, 10);
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
