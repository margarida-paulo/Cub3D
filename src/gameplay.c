/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:37:59 by plashkar          #+#    #+#             */
/*   Updated: 2024/09/28 15:19:23 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_gameplay(t_game *game)
{
	if (game->state == STATE_MENU)
	{
		render_menu(game);
		return (0);
	}
	else if (game->state == STATE_PLAYING)
	{
		if (game->key_press == XK_RIGHT || game->key_press == XK_LEFT)
			ft_rotate(game);
		else if (game->key_press == XK_W || game->key_press == XK_A || \
		game->key_press == XK_S || game->key_press == XK_D)
		{
			update_head_bob(game);
			ft_move(game);
		}
		ft_render_screen(game);
		return (0);
	}
	return (0);
}
