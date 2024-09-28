/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:21:51 by mvalerio          #+#    #+#             */
/*   Updated: 2024/09/28 15:18:47 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Rotate the player.
 *
 * This function changes the player's orientation based on the key press.
 * If the key press is XK_Right, the player's orientation is increased by
 * SENSITVITY / 1000. If the key press is XK_Left, the player's orientation
 * is decreased by SENSITVITY / 1000. If the player's orientation is greater
 * than 2 * M_PI, it is set to 0.
 *
 * @param game the game struct containing all the resources.
 * @return 0
 */
int	ft_rotate(t_game *game)
{
	if (game->key_press == XK_RIGHT)
	{
		if (game->p_orient[2] + (SENSITVITY / 1000) > (2 * M_PI))
			game->p_orient[2] = 0;
		else
			game->p_orient[2] += (SENSITVITY / 1000);
	}
	else if (game->key_press == XK_LEFT)
	{
		if (game->p_orient[2] - (SENSITVITY / 1000) > (2 * M_PI))
			game->p_orient[2] = 0;
		else
			game->p_orient[2] -= (SENSITVITY / 1000);
	}
	return (0);
}

/**
 * @brief Called when a key is released.
 *
 * This function is called by the event loop when a key is released.
 * It takes the key code of the released key and the game struct as parameters.
 * It sets the key press value of the game struct to 0.
 *
 * @param key_code the key code of the released key
 * @param game the game struct containing all the resources
 * @return 0
 */
int	ft_key_release(int key_code, t_game *game)
{
	(void)key_code;
	game->key_press = 0;
	return (0);
}

/**
 * @brief Called when a key is pressed.
 *
 * This function is called by the event loop when a key is pressed.
 * It takes the key code of the pressed key and the game struct as parameters.
 * If the pressed key is XK_Escape, it calls exit_program to gracefully exit
 * the program. Otherwise, it sets the key press value of the game struct to
 * the key code.
 *
 * @param key_code the key code of the pressed key
 * @param game the game struct containing all the resources
 * @return 0
 */
int	ft_key_press(int key_code, t_game *game)
{
	if (key_code == XK_ESCAPE)
		exit_program(game);
	else
		game->key_press = key_code;
	return (0);
}
