/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:22:55 by mvalerio          #+#    #+#             */
/*   Updated: 2024/08/23 11:30:38 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_make_example_map(t_game *game)
{
	game->map = malloc(sizeof(char *) * 7);

	game->map[0] = malloc(sizeof(char) * 7);
	game->map[0][0] = '1';
	game->map[0][1] = '1';
	game->map[0][2] = '1';
	game->map[0][3] = '1';
	game->map[0][4] = '1';
	game->map[0][5] = '1';
	game->map[0][6] = '\0';

	game->map[1] = malloc(sizeof(char) * 7);
	game->map[1][0] = '1';
	game->map[1][1] = '0';
	game->map[1][2] = '0';
	game->map[1][3] = '1';
	game->map[1][4] = '0';
	game->map[1][5] = '1';
	game->map[1][6] = '\0';

	game->map[2] = malloc(sizeof(char) * 7);
	game->map[2][0] = '1';
	game->map[2][1] = '0';
	game->map[2][2] = '0';
	game->map[2][3] = '1';
	game->map[2][4] = '0';
	game->map[2][5] = '1';
	game->map[2][6] = '\0';

	game->map[3] = malloc(sizeof(char) * 7);
	game->map[3][0] = '1';
	game->map[3][1] = '0';
	game->map[3][2] = '0';
	game->map[3][3] = '0';
	game->map[3][4] = '0';
	game->map[3][5] = '1';
	game->map[3][6] = '\0';

	game->map[4] = malloc(sizeof(char) * 7);
	game->map[4][0] = '1';
	game->map[4][1] = '0';
	game->map[4][2] = '1';
	game->map[4][3] = '0';
	game->map[4][4] = '0';
	game->map[4][5] = '1';
	game->map[4][6] = '\0';

	game->map[5] = malloc(sizeof(char) * 7);
	game->map[5][0] = '1';
	game->map[5][1] = '1';
	game->map[5][2] = '1';
	game->map[5][3] = '1';
	game->map[5][4] = '1';
	game->map[5][5] = '1';
	game->map[5][6] = '\0';

	game->map[6] = NULL;
}






// Initializes the instance and the window of the minilibx into the game struct.
t_game *minilibx_init() {
    t_game *game;
    game = malloc(sizeof(t_game));
    if (!game)
        exit(1);
    ft_make_example_map(game);
    game->height = ft_arrlen(game->map) * GRID_SIZE;
    game->width = ft_strlen(game->map[0]) * GRID_SIZE;
    game->mlx = mlx_init();
    game->mlx_win = mlx_new_window(game->mlx, game->width, game->height, "The best Cub3D you've ever seen");
    game->p_orient[2] = M_PI / 2;
    game->p_orient[0] = PLAYER_X * GRID_SIZE + GRID_SIZE / 2;
    game->p_orient[1] = PLAYER_Y * GRID_SIZE + GRID_SIZE / 2;
    game->img_list = malloc(sizeof(t_pics));
    game->img_list->minimap = NULL;
    game->img_list->player = NULL;
    game->key_press = 0;
	game->origin[0] = 0;
	game->origin[1] = 0;
    ft_build_minimap(game);
    ft_build_player(game);
	game->current_screen = ft_merge_images(game, game->img_list->minimap, game->img_list->player, game->origin);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->current_screen->img, 0, 0);
    return (game);
}

