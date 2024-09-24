/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 23:59:51 by plashkar          #+#    #+#             */
/*   Updated: 2024/09/24 14:37:34 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Checks if a given point is near a wall.
 * If the point is closer than PLAYER_SIZE/3, it is considered near a wall.
 *
 * @param game The game structure.
 * @param x The x coordinate of the point to check.
 * @param y The y coordinate of the point to check.
 *
 * @return 1 if the point is near a wall, 0 otherwise.
 */
int	is_near_wall(t_game *game, double x, double y)
{
	int	dx;
	int	dy;

	dx = -PLAYER_SIZE / 3;
	while (dx <= PLAYER_SIZE / 3)
	{
		dy = -PLAYER_SIZE / 3;
		while (dy <= PLAYER_SIZE / 3)
		{
			if (sqrt(dx * dx + dy * dy) <= PLAYER_SIZE / 3)
			{
				if (get_px_color(game->img_list->minimap, x + dx, y + dy) \
				== WALL_CLR)
					return (1);
			}
			dy++;
		}
		dx++;
	}
	return (0);
}

/**
 * @brief Handles player movement.
 *
 * This function changes the player's position (game->p_orient[0] and
 * game->p_orient[1]) based on the key press (game->key_press).
 *
 * The move is a function of the game's width and height.
 *
 * @param game The game structure.
 */
void	ft_move(t_game *game)
{
	double	n_pos[3];
	int		m;

	if (game->key_press == XK_w || game->key_press == XK_a)
		m = 1;
	else
		m = -1;
	n_pos[0] = game->p_orient[0];
	n_pos[1] = game->p_orient[1];
	if (game->key_press == XK_w || game->key_press == XK_s)
	{
		n_pos[0] += (game->move_rate * cos(game->p_orient[2]) * m);
		n_pos[1] += (game->move_rate * sin(game->p_orient[2]) * m);
	}
	else if (game->key_press == XK_a || game->key_press == XK_d)
	{
		n_pos[0] += (game->move_rate * cos(game->p_orient[2] - M_PI / 2) * m);
		n_pos[1] += (game->move_rate * sin(game->p_orient[2] - M_PI / 2) * m);
	}
	if (!is_near_wall(game, n_pos[0], n_pos[1]))
	{
		game->p_orient[0] = n_pos[0];
		game->p_orient[1] = n_pos[1];
	}
}

/**
 * @brief Updates the head bob offset and phase.
 *
 * This function should be called every frame.
 *
 * If the player is moving, the head bob phase is incremented by the
 * head bob frequency. If the phase exceeds 2 * pi, it is reset to 0.
 * The head bob offset is then calculated as the amplitude times the
 * sine of the phase.
 *
 * If the player is not moving, the head bob offset and phase are both
 * set to 0.
 *
 * @param game the game struct
 * @return void
 */

void	update_head_bob(t_game *game)
{
	if (game->key_press == XK_w || game->key_press == XK_a || \
		game->key_press == XK_s || game->key_press == XK_d)
	{
		game->head_bob_phase += HEAD_BOB_FREQUENCY;
		if (game->head_bob_phase > 2 * M_PI)
			game->head_bob_phase -= 2 * M_PI;
		game->head_bob_offset = HEAD_BOB_AMPLITUDE * sin(game->head_bob_phase);
	}
	else
	{
		game->head_bob_offset = 0;
		game->head_bob_phase = 0;
	}
}
