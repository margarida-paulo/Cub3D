/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:44:41 by mvalerio          #+#    #+#             */
/*   Updated: 2024/09/18 19:44:14 by plashkar         ###   ########.fr       */
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
void ft_clear_img(t_data *img, int width, int height)
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
 * @brief Calculates the area of a triangle given its vertices.
 *
 * @param xy1 The first vertex of the triangle.
 * @param xy2 The second vertex of the triangle.
 * @param xy3 The third vertex of the triangle.
 *
 * @return The area of the triangle.
 */
double area_triangle(double xy1[2], double xy2[2], double xy3[2])
{
	return fabs((xy1[0]*(xy2[1]-xy3[1]) + xy2[0]*(xy3[1]-xy1[1]) + \
	xy3[0]*(xy1[1]-xy2[1])) / 2.0);
}


/**
 * @brief Checks if a given point is inside a triangle.
 *
 * @param xy1 The first vertex of the triangle.
 * @param xy2 The second vertex of the triangle.
 * @param xy3 The third vertex of the triangle.
 * @param xy The point to check.
 *
 * @return 1 if the point is inside the triangle, 0 otherwise.
 */
int is_inside_triangle(double xy1[2], double xy2[2], double xy3[2], double xy[2])
{
	float a = area_triangle(xy1, xy2, xy3);
	float a1 = area_triangle(xy, xy2, xy3);
	float a2 = area_triangle(xy1, xy, xy3);
	float a3 = area_triangle(xy1, xy2, xy);
	return (round(a) == round(a1 + a2 + a3));
}

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

	dx = -PLAYER_SIZE/3;
	while (dx <= PLAYER_SIZE/3)
	{
		dy = -PLAYER_SIZE/3;
		while (dy <= PLAYER_SIZE/3)
		{
			if (sqrt(dx * dx + dy * dy) <= PLAYER_SIZE/3)
			{
				if (get_px_color(game->img_list->minimap, x + dx, y + dy) == WALL_CLR)
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

void		ft_move(t_game *game)
{
	double		n_pos[3];
	int			m;;

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
	// if(get_px_color(game->img_list->minimap, n_pos[0], n_pos[1]) != WALL_CLR)
	if (!is_near_wall(game, n_pos[0], n_pos[1]))
	{
		game->p_orient[0] = n_pos[0];
		game->p_orient[1] = n_pos[1];
	}
}

/**
 * @brief Calculates the Euclidean distance between two points.
 *
 * @param x1 The x coordinate of the first point.
 * @param y1 The y coordinate of the first point.
 * @param x2 The x coordinate of the second point.
 * @param y2 The y coordinate of the second point.
 * @return The Euclidean distance between the two points.
 */
double	ft_distance(int x1, int y1, int x2, int y2)
{
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
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

void crop_minimap_around_player(t_game *game)
{
	int player_x = (int)game->p_orient[0];
	int player_y = (int)game->p_orient[1];
	int start_x = player_x - MINIMAP_WIDTH / 2;
	int start_y = player_y - MINIMAP_HEIGHT / 2;
	int x, y;
	int color;

	// Create a new image for the cropped minimap
	t_data *cropped_minimap = game->img_list->cropped_minimap;

    for (y = 0; y < MINIMAP_HEIGHT; y++)
    {
        for (x = 0; x < MINIMAP_WIDTH; x++)
        {
            int src_x = start_x + x;
            int src_y = start_y + y;

            if (src_x >= 0 && src_x < game->img_list->minimap->width &&
                src_y >= 0 && src_y < game->img_list->minimap->height)
            {
                color = get_px_color(game->current_screen, src_x, src_y);
            }
            else
            {
                color = 0x000000; // Out of bounds
            }
            mlx_px(cropped_minimap, x, y, color);
        }
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
				*(unsigned int *)(img->addr + (y + (int)pos[1]) * img->line_length + (x + (int)pos[0]) * img->bits_per_pixel / 8) = *(unsigned int *)(top->addr + y * top->line_length + x * top->bits_per_pixel / 8);
			x++;
		}
		y++;
	}
	return (img);
}
