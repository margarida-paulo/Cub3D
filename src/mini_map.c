/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:44:41 by mvalerio          #+#    #+#             */
/*   Updated: 2024/08/15 20:04:05 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_put_player_map(t_game *game)
{
	int	x;
	int y;

	x = -MAP_PX/2;
	while (x <= MAP_PX / 2)
	{
		y = -MAP_PX/2;
		while (y <= MAP_PX / 2)
		{
			mlx_pixel_put(game->mlx, game->mlx_win, game->p_orient[0] + x, game->p_orient[1] + y, PLAYER_COLOUR);
			y++;
		}
		x++;
	}

}

int	ft_move(t_game *game)

{
	(void)game;
	return (0);
}
