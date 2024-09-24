/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:44:41 by mvalerio          #+#    #+#             */
/*   Updated: 2024/09/24 15:04:43 by plashkar         ###   ########.fr       */
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
			if(game->map.map_array[curr_y / GRID_SIZE][curr_x / GRID_SIZE] == '1')
				mlx_px(game->img_list->minimap, temp_curr_x, temp_curr_y, WALL_CLR);
			else if(game->map.map_array[curr_y / GRID_SIZE][curr_x / GRID_SIZE] == ' ')
				mlx_px(game->img_list->minimap, temp_curr_x, temp_curr_y, 0x00000000);
			else
				mlx_px(game->img_list->minimap, temp_curr_x, temp_curr_y, MINI_FLOOR_CLR);
			temp_curr_x++;
		}
		temp_curr_y++;
	}
}

void	crop_minimap_around_player(t_game *game)
{
	int	xy[2]; // int x and int y
	int	src_xy[2]; // src_x and src_y
	int color;

	xy[1] = 0;
	while (xy[1] < MINIMAP_HEIGHT)
	{
		xy[0] = 0;
		while (xy[0] < MINIMAP_WIDTH)
		{
			src_xy[0] = (int)game->p_orient[0] - MINIMAP_WIDTH / 2 + xy[0];
			src_xy[1] = (int)game->p_orient[1] - MINIMAP_HEIGHT / 2 + xy[1];
			if (src_xy[0] >= 0 && src_xy[0] < game->img_list->minimap->width &&
				src_xy[1] >= 0 && src_xy[1] < game->img_list->minimap->height)
				color = get_px_color(game->current_screen, src_xy[0], src_xy[1]);
			else
				color = 0x000000; // Out of bounds
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
		img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),\
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

/**
 * @brief Builds the player image.
 *
 * Given a game, this function builds the player image by drawing a triangle
 * on the player image. The triangle is centered at the player position and
 * has a side length of PLAYER_RAY. The player image is part of the game
 * structure.
 * SUGGESTION: Make the player colour dependent on the texture.
 *
 * @param game The game structure.
 */
void	ft_build_player(t_game *game)
{
	int 	center[2];
	double		v1[2];
	double		v2[2];
	double		v3[2];
	double		pos[2];

	if (game->img_list->player == NULL)
		game->img_list->player = init_img(game, game->width, game->height);
	ft_clear_img(game->img_list->player, game->img_list->player->width, game->img_list->player->height);
	cast_rays(game);
	center[0] = (int)game->p_orient[0];
	center[1] = (int)game->p_orient[1];
	v1[0] = center[0] + (PLAYER_RAY * cos(game->p_orient[2]));
	v1[1] = center[1] + (PLAYER_RAY * sin(game->p_orient[2]));
	v2[0] = center[0] + (PLAYER_RAY * cos(game->p_orient[2] - (2 * M_PI / 2.5)));
	v2[1] = center[1] + (PLAYER_RAY * sin(game->p_orient[2] - (2 * M_PI / 2.5)));
	v3[0] = center[0] + (PLAYER_RAY * cos(game->p_orient[2] + (2 * M_PI / 2.5)));
	v3[1] = center[1] + (PLAYER_RAY * sin(game->p_orient[2] + (2 * M_PI / 2.5)));
	pos[1] = center[1] - PLAYER_SIZE / 2;
	while (pos[1] < center[1] + PLAYER_SIZE / 2)
	{
		pos[0] = center[0] - PLAYER_SIZE / 2;
		while (pos[0] < center[0] + PLAYER_SIZE / 2)
		{
			if(is_inside_triangle(v1, v2, v3, pos))
				mlx_px(game->img_list->player, pos[0], pos[1], PLAYER_CLR);
			pos[0]++;
		}
		pos[1]++;
	}
}

/**
 * @brief Merges two images together.
 *
 * Given a game, a bottom image, a top image, and a position, this function
 * creates a new image that is a combination of the bottom and top images.
 * The top image is rendered at the specified position on the new image.
 * If a pixel of the top image is not transparent, the pixel of the new
 * image is set to the same color as the pixel of the top image. If the
 * pixel of the top image is transparent, the pixel of the new image is
 * set to the same color as the pixel of the bottom image.
 *
 * @param game The game structure.
 * @param bottom The image that will be rendered first.
 * @param top The image that will be rendered second.
 * @param pos The position on the new image where the top image will be rendered.
 *
 * @return The new image.
 */
t_data	*ft_merge_images(t_game *game, t_data *bottom, t_data *top, double *pos)
{
	t_data	*img;
	int		x;
	int		y;
	(void)top;
	(void)pos;

	img = malloc(sizeof(t_data));
	img->img = mlx_new_image(game->mlx, bottom->width, bottom->height);
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
				*(unsigned int *)(img->addr + (y + (int)pos[1]) * img->line_length + (x + (int)pos[0]) * img->bits_per_pixel / 8) = *(unsigned int *)(top->addr + y * top->line_length + x * top->bits_per_pixel / 8);
			x++;
		}
		y++;
	}
	return (img);
}


// t_data	*ft_merge_images(t_game *game, t_data *bottom, t_data *top, double *pos)
// {
// 	t_data	*img;
// 	int		x;
// 	int		y;
// 	(void)top;
// 	(void)pos;

// 	img = malloc(sizeof(t_data));
// 	img->img = mlx_new_image(game->mlx, game->width, game->height);
// 	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), &(img->line_length), &(img->endian));
// 	y = 0;
// 	while (y < bottom->height)
// 	{
// 		x = 0;
// 		while (x < bottom->width)
// 		{
// 			if (*(unsigned int *)(bottom->addr + y * bottom->line_length + x * bottom->bits_per_pixel / 8) != 0)
// 				*(unsigned int *)(img->addr + y * img->line_length + x * img->bits_per_pixel / 8) = *(unsigned int *)(bottom->addr + y * bottom->line_length + x * bottom->bits_per_pixel / 8);
// 			x++;
// 		}
// 		y++;
// 	}

// 	y = 0;
// 	while (y < top->height)
// 	{
// 		x = 0;
// 		while (x < top->width)
// 		{
// 			if (*(unsigned int *)(top->addr + y * top->line_length + x * top->bits_per_pixel / 8) != 0)
// 				*(unsigned int *)(img->addr + (y + (int)pos[1]) * img->line_length + (x + (int)pos[0]) * img->bits_per_pixel / 8) = *(unsigned int *)(top->addr + y * top->line_length + x * top->bits_per_pixel / 8);
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (img);
// }
