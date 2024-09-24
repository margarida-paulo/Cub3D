/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gameplay.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:37:59 by plashkar          #+#    #+#             */
/*   Updated: 2024/09/24 14:38:13 by plashkar         ###   ########.fr       */
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
		if (game->key_press == XK_Right || game->key_press == XK_Left)
			ft_rotate(game);
		else if (game->key_press == XK_w || game->key_press == XK_a || \
		game->key_press == XK_s || game->key_press == XK_d)
		{
			update_head_bob(game);
			ft_move(game);
		}
		ft_render_screen(game);
		return (0);
	}
	return (0);
}
