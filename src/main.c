/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:27:33 by mvalerio          #+#    #+#             */
/*   Updated: 2024/09/20 12:01:29 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	render_menu(t_game *game)
{
	mlx_clear_window(game->mlx, game->game_window);

	mlx_string_put(game->mlx, game->game_window, 100, 100, 0xFFFFFF, "1. Start Game");
	mlx_string_put(game->mlx, game->game_window, 100, 150, 0xFFFFFF, "2. Exit");

	// Update the window
	mlx_do_sync(game->mlx);
	if (game->key_press == XK_1)
	{
		game->state = STATE_PLAYING;
		return ;
	}
	else if (game->key_press == XK_2)
		exit_program(game);
}

//The calculation game->head_bob_offset = HEAD_BOB_AMPLITUDE * sin(game->head_bob_phase);
//determines the vertical displacement of the player's view based on a sine wave.
void	update_head_bob(t_game *game)
{
	// Check if the player is moving
	if (game->key_press == XK_w || game->key_press == XK_a || \
		game->key_press == XK_s || game->key_press == XK_d)
	{
		// Increment the head bob phase
		game->head_bob_phase += HEAD_BOB_FREQUENCY;
		if (game->head_bob_phase > 2 * M_PI)
			game->head_bob_phase -= 2 * M_PI;

			// Calculate the head bob offset based on the sine of the phase
		game->head_bob_offset = HEAD_BOB_AMPLITUDE * sin(game->head_bob_phase);
	}
	else
	{
		// Reset the head bob offset and phase when the player stops moving
		game->head_bob_offset = 0;
		game->head_bob_phase = 0;
	}
}

int	ft_gameplay(t_game *game)
{
	// ft_render_screen(game);
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
		// else if (game->key_press == XK_space)
		// 	ft_shoot(game);
		// else
		// 	return (0);
		ft_render_screen(game);
		return (0);
	}
	return (0);
}

int main(int argc, char **argv)
{
	t_game	game;

	(void)game;
	ft_memset(&game, 0, sizeof(game));
	game.map.game = &game;
	if (argc != 2)
		print_error_0(INVALID_ARG_CNT, NULL);
	parse_map(&game.map, argv);
	test_print_map_struct_data(&game.map);
	minilibx_init(&game);
	mlx_loop_hook(game.mlx, ft_gameplay, &game);
//	mlx_hook(game.mlx_win, 17, 0, exit_program, &game);
	mlx_hook(game.game_window, 17, 0, exit_program, &game);
//	mlx_hook(game.mlx_win, 3, (1L<<1), ft_key_release, &game);
//	mlx_hook(game.mlx_win, 2, (1L<<0), ft_key_press, &game);
	mlx_hook(game.game_window, 3, (1L<<1), ft_key_release, &game);
	mlx_hook(game.game_window, 2, (1L<<0), ft_key_press, &game);
	mlx_loop(game.mlx);
}



