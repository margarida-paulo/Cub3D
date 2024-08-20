/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:22:55 by mvalerio          #+#    #+#             */
/*   Updated: 2024/08/20 17:12:37 by mvalerio         ###   ########.fr       */
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


void	ft_rotate_player(t_game *game, t_data **img, double angle)
{
	int	y;
	int	x;
	t_data	*r_img;
	int		new_x;
	int		new_y;

	r_img = malloc(sizeof(t_data));
	r_img->img = mlx_new_image(game->mlx, sqrt(2 * pow(PLAYER_SIZE, 2)), sqrt(2 * pow(PLAYER_SIZE, 2)));
	r_img->addr = mlx_get_data_addr(r_img->img, &r_img->bits_per_pixel, &r_img->line_length, &r_img->endian);
	y = 0;
	while (y < (*img)->height)
	{
		x = 0;
		while (x < (*img)->width)
		{
			new_x = x * cos(angle) - y * sin(angle);
			new_y = y * cos(angle) + x * sin(angle);
			*(r_img->addr + (new_y * r_img->line_length) + (new_x * (r_img->bits_per_pixel / 8))) = *((*img)->addr + (y * (*img)->line_length) + (x * ((*img)->bits_per_pixel / 8)));
			x++;
		}
		y++;
	}
	mlx_destroy_image(game->mlx, (*img)->img);
	free(*img);
	*img = r_img;
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
    game->p_orient[2] = 0;
    game->p_orient[0] = PLAYER_X * GRID_SIZE + GRID_SIZE / 2;
    game->p_orient[1] = PLAYER_Y * GRID_SIZE + GRID_SIZE / 2;
    game->img_list = malloc(sizeof(t_pics));
    game->img_list->minimap = NULL;
    game->key_press = 0;
    ft_minimap_bckg(game);
    ft_put_player_map(game);

    int width;
    int height;
    t_data *test;
    test = malloc(sizeof(t_data));
    if (!test)
        exit(1);
    test->img = mlx_xpm_file_to_image(game->mlx, "/home/mvalerio/Documents/Cub3D/imgs/gps_arrow_20.xpm", &width, &height);
	test->addr = mlx_get_data_addr(test->img, &(test->bits_per_pixel), &(test->line_length), &(test->endian));
	test->height = 20;
	test->width = 20;
    if (!test->img) {
        // Handle error
        exit(1);
    }
	ft_rotate_player(game, &test, 0);
    mlx_put_image_to_window(game->mlx, game->mlx_win, test->img, 10, 10);

    return game;
}

