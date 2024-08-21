/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:44:41 by mvalerio          #+#    #+#             */
/*   Updated: 2024/08/21 18:15:18 by mvalerio         ###   ########.fr       */
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
	ft_build_minimap(game);
	ft_build_player(game);
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

void	ft_build_minimap(t_game *game)
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
	img->width = game->width;
	img->height = game->height;
//	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_list->minimap->img, 0, 0);
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
void	ft_build_player(t_game *game)
{
	game->img_list->player = malloc(sizeof(t_data));
	game->img_list->player->img = mlx_xpm_file_to_image(game->mlx, "/home/mvalerio/Documents/Cub3D/imgs/gps_arrow_20.xpm", &(game->img_list->player->width), &(game->img_list->player->height));
	game->img_list->player->addr = mlx_get_data_addr(game->img_list->player->img, &(game->img_list->player->bits_per_pixel), &(game->img_list->player->line_length), &(game->img_list->player->endian));
}

t_data	*ft_merge_images(t_game *game, t_data *bottom, t_data *top, int pos[2])
{
	t_data	*img;
	int		x;
	int		y;
	(void)top;
	(void)pos;

	img = malloc(sizeof(t_data));
	img->img = mlx_new_image(game->mlx, game->width, game->height);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), &(img->line_length), &(img->endian));
	y = 0;
	while (y < bottom->height)
	{
		x = 0;
		while (x < bottom->width)
		{
			if (*(unsigned int *)(bottom->addr + y * bottom->line_length + x * bottom->bits_per_pixel / 8) != 0)
				*(unsigned int *)(img->addr + y * img->line_length + x * img->bits_per_pixel / 8) = *(unsigned int *)(bottom->addr + y * bottom->line_length + x * bottom->bits_per_pixel / 8);
			x++;
		}
		y++;
	}

	y = 0;
	while (y < top->height)
	{
		x = 0;
		while (x < top->width)
		{
			if (*(unsigned int *)(top->addr + y * top->line_length + x * top->bits_per_pixel / 8) != 0)
				*(unsigned int *)(img->addr + (y + pos[1]) * img->line_length + (x + pos[0]) * img->bits_per_pixel / 8) = *(unsigned int *)(top->addr + y * top->line_length + x * top->bits_per_pixel / 8);
			x++;
		}
		y++;
	}
	return (img);
}
