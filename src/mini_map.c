/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:44:41 by mvalerio          #+#    #+#             */
/*   Updated: 2024/09/26 12:22:28 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Clears an image by setting all pixels to black.
 *
 * @param img The image to clear.
 * @param width The width of the image.
 * @param height The height of the image.
 */
void	ft_clear_img(t_data *img, int width, int height)
{
	int	pos[2];

	pos[1] = 0;
	while (pos[1] < height)
	{
		pos[0] = 0;
		while (pos[0] < width)
		{
			mlx_px(img, pos[0], pos[1], 0);
			pos[0]++;
		}
		pos[1]++;
	}
}

/**
 * @brief Draws a background square on the minimap image.
 *
 * Given a game and the coordinates of the top left corner of a square,
 * this function draws a square on the minimap image. The square is
 * colored differently depending on the value of the corresponding
 * character in the map array. A '1' is a wall, a ' ' is empty space, and
 * any other character is a floor.
 *
 * @param game The game structure.
 * @param curr_x The x coordinate of the top left corner of the square.
 * @param curr_y The y coordinate of the top left corner of the square.
 */
void	ft_bckg_square(t_game *game, int curr_x, int curr_y)
{
	int	temp_curr_x;
	int	temp_curr_y;

	temp_curr_y = curr_y;
	while (temp_curr_y <= curr_y + GRID_SIZE)
	{
		temp_curr_x = curr_x;
		while (temp_curr_x <= curr_x + GRID_SIZE)
		{
			if (game->map.map_array[curr_y / GRID_SIZE] \
			[curr_x / GRID_SIZE] == '1')
				mlx_px(game->img_list->minimap, temp_curr_x, \
				temp_curr_y, WALL_CLR);
			else if (game->map.map_array[curr_y / \
			GRID_SIZE][curr_x / GRID_SIZE] == ' ')
				mlx_px(game->img_list->minimap, temp_curr_x, \
				temp_curr_y, 0x00000000);
			else
				mlx_px(game->img_list->minimap, temp_curr_x, \
				temp_curr_y, MINI_FLOOR_CLR);
			temp_curr_x++;
		}
		temp_curr_y++;
	}
}

void	crop_minimap_around_player(t_game *game)
{
	int	xy[2];
	int	src_xy[2];
	int	color;

	xy[1] = 0;
	while (xy[1] < MINIMAP_HEIGHT)
	{
		xy[0] = 0;
		while (xy[0] < MINIMAP_WIDTH)
		{
			src_xy[0] = (int)game->p_orient[0] - MINIMAP_WIDTH / 2 + xy[0];
			src_xy[1] = (int)game->p_orient[1] - MINIMAP_HEIGHT / 2 + xy[1];
			if (src_xy[0] >= 0 && src_xy[0] < game->img_list->minimap->width && \
				src_xy[1] >= 0 && src_xy[1] < game->img_list->minimap->height)
				color = get_px_color(game->current_screen, src_xy[0], \
				src_xy[1]);
			else
				color = 0x000000;
			mlx_px(game->img_list->cropped_minimap, xy[0], xy[1], color);
			xy[0]++;
		}
		xy[1]++;
	}
}

/**
 * @brief Builds the minimap image.
 *
 * Given a game, this function builds the minimap image by iterating over
 * the map array and drawing a square on the minimap image for each cell in
 * the map array. The colour of the square depends on the value of the
 * corresponding character in the map array. A '1' is a wall, a ' ' is empty
 * space, and any other character is a floor.
 *
 * @param game The game structure.
 */
void	ft_build_minimap(t_game *game)
{
	t_data	*img;
	int		curr_x;
	int		curr_y;

	if (game->img_list->minimap == NULL)
	{
		img = malloc(sizeof(t_data));
		img->img = mlx_new_image(game->mlx, game->width, game->height);
		img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), \
		&(img->line_length), &(img->endian));
		img->width = game->width;
		img->height = game->height;
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
}

void	ft_set_player_info(t_game *game)
{
	game->p_center[0] = (int)game->p_orient[0];
	game->p_center[1] = (int)game->p_orient[1];
	game->v1[0] = game->p_center[0] + (PLAYER_RAY * cos(game->p_orient[2]));
	game->v1[1] = game->p_center[1] + (PLAYER_RAY * sin(game->p_orient[2]));
	game->v2[0] = game->p_center[0] + (PLAYER_RAY * cos(game->p_orient[2] - \
	(2 * M_PI / 2.5)));
	game->v2[1] = game->p_center[1] + (PLAYER_RAY * sin(game->p_orient[2] - \
	(2 * M_PI / 2.5)));
	game->v3[0] = game->p_center[0] + (PLAYER_RAY * cos(game->p_orient[2] + \
	(2 * M_PI / 2.5)));
	game->v3[1] = game->p_center[1] + (PLAYER_RAY * sin(game->p_orient[2] + \
	(2 * M_PI / 2.5)));
}
