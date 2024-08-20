/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:44:41 by mvalerio          #+#    #+#             */
/*   Updated: 2024/08/20 13:49:48 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_move(t_game *game)
{
	if (game->key_press == XK_w)
	{
		game->p_orient[0] += 0.01 * cos(game->p_orient[2]);
		game->p_orient[1] += 0.01 * sin(game->p_orient[2]);
	}
	else if (game->key_press == XK_s)
	{
		game->p_orient[0] -= 0.01 * cos(game->p_orient[2]);
		game->p_orient[1] -= 0.01 * sin(game->p_orient[2]);
	}

	if (game->key_press == XK_a)
	{
		game->p_orient[0] += 0.01 * cos(game->p_orient[2] - M_PI / 2);
		game->p_orient[1] += 0.01 * sin(game->p_orient[2] - M_PI / 2);
	}
	else if (game->key_press == XK_d)
	{
		game->p_orient[0] -= 0.01 * cos(game->p_orient[2] - M_PI / 2);
		game->p_orient[1] -= 0.01 * sin(game->p_orient[2] - M_PI / 2);
	}
	ft_minimap_bckg(game);
	ft_put_player_map(game);
	return (0);
}

double	ft_distance(int x1, int y1, int x2, int y2)
{
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void	ft_bckg_square(t_game *game, int curr_x, int curr_y)
{
	int	temp_curr_x;
	int	temp_curr_y;

	temp_curr_y = curr_y + 1;
	while (temp_curr_y <= curr_y + GRID_SIZE)
	{
		temp_curr_x = curr_x + 1;
		while (temp_curr_x <= curr_x + GRID_SIZE)
		{
			if(temp_curr_x == curr_x + GRID_SIZE || temp_curr_y == curr_y + GRID_SIZE)
				mlx_px(game->img_list->minimap, temp_curr_x, temp_curr_y, 0);
			else if(game->map[curr_y / GRID_SIZE][curr_x / GRID_SIZE] == '1')
				mlx_px(game->img_list->minimap, temp_curr_x, temp_curr_y, MINI_WALL_COLOUR);
			else
				mlx_px(game->img_list->minimap, temp_curr_x, temp_curr_y, MINI_FLOOR_COLOUR);
			temp_curr_x++;
		}
		temp_curr_y++;
	}
}

void	ft_minimap_bckg(t_game *game)
{
	t_data	*img;
	int		curr_x;
	int		curr_y;

	if (game->img_list->minimap == NULL)
	{
		img = malloc(sizeof(t_data));
		img->img = mlx_new_image(game->mlx, game->width, game->height);
		img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), &(img->line_length), &(img->endian));
		game->img_list->minimap = img;
	}
	curr_y = 0;
	while (curr_y < game->height)
	{
		curr_x = 0;
		while (curr_x < game->width)
		{
			ft_bckg_square(game, curr_x, curr_y);
			curr_x += GRID_SIZE;
		}
		curr_y += GRID_SIZE;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_list->minimap->img, 0, 0);
}

void	ft_player_ray(t_game *game)
{
	int ray_size = 0;
	int new_position[2];

	while (ray_size < PLAYER_SIZE)
	{
		new_position[0] = game->p_orient[0] + ((PLAYER_SIZE / 2 + ray_size) * cos(game->p_orient[2]));
		new_position[1] = game->p_orient[1] + ((PLAYER_SIZE / 2 + ray_size) * sin(game->p_orient[2]));
		mlx_px(game->img_list->minimap, new_position[0], new_position[1], PLAYER_COLOUR);
		ray_size++;
	}
}

// Inserts a square in the minimap.
// game->p_orient[0] = x
// game->p_orient[1] = y
// The colour is, for now, PLAYER_COLOUR. In the future it would be cool if
// the colour could be random or based on the texture colours.
void	ft_put_player_map(t_game *game)
{
	t_data	*img;
	int		curr_x;
	int		curr_y;

	img = game->img_list->minimap;
	curr_y = - PLAYER_SIZE / 2;
	while (curr_y < PLAYER_SIZE / 2)
	{
		curr_x = - PLAYER_SIZE / 2;
		while (curr_x < PLAYER_SIZE / 2)
		{
			if(ft_distance(game->p_orient[0], game->p_orient[1], game->p_orient[0] + curr_x, game->p_orient[1] + curr_y) < PLAYER_SIZE/2)
				mlx_px(img, game->p_orient[0] + curr_x, game->p_orient[1] + curr_y, PLAYER_COLOUR);
			curr_x++;
		}
		curr_y++;
	}
	ft_player_ray(game);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img->img, 0, 0);
}
