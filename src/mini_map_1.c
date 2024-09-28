/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 12:20:31 by mvalerio          #+#    #+#             */
/*   Updated: 2024/09/28 15:45:18 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	copy_non_zero_pixels(t_data *src, t_data *dst, \
int x_offset, int y_offset)
{
	int				xy[2];
	unsigned int	*src_pixel;
	unsigned int	*dst_pixel;

	xy[1] = 0;
	while (xy[1] < src->height)
	{
		xy[0] = 0;
		while (xy[0] < src->width)
		{
			src_pixel = (unsigned int *)(src->addr + xy[1] * src->line_length + \
			xy[0] * src->bits_per_pixel / 8);
			if (*src_pixel != 0)
			{
				dst_pixel = (unsigned int *)(dst->addr + \
				(xy[1] + y_offset) * dst->line_length + \
				(xy[0] + x_offset) * dst->bits_per_pixel / 8);
				*dst_pixel = *src_pixel;
			}
			xy[0]++;
		}
		xy[1]++;
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

	img = init_img(game, bottom->width, bottom->height);
	copy_non_zero_pixels(bottom, img, 0, 0);
	copy_non_zero_pixels(top, img, (int)pos[0], (int)pos[1]);
	return (img);
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
	double		pos[2];

	if (game->img_list->player == NULL)
		game->img_list->player = init_img(game, game->width, game->height);
	ft_clear_img(game->img_list->player, \
	game->img_list->player->width, game->img_list->player->height);
	cast_rays(game);
	ft_set_player_info(game);
	pos[1] = game->p_center[1] - PLAYER_SIZE / 2;
	while (pos[1] < game->p_center[1] + PLAYER_SIZE / 2)
	{
		pos[0] = game->p_center[0] - PLAYER_SIZE / 2;
		while (pos[0] < game->p_center[0] + PLAYER_SIZE / 2)
		{
			if (is_inside_triangle(game->v1, game->v2, game->v3, pos))
				mlx_px(game->img_list->player, pos[0], pos[1], PLAYER_CLR);
			pos[0]++;
		}
		pos[1]++;
	}
}

/**
 * @brief Draws a ray from the player position.
 *
 * Given a game, the length of the ray and the angle of the ray, this function
 * draws a ray from the player position in the direction given by the angle,
 * until a wall is found.
 * The ray is drawn on the player image.
 *
 * @param game The game structure.
 * @param ray_size The length of the ray.
 * @param angle The angle of the ray.
 */
void	ft_draw_ray(t_game *game, double ray_size, double angle)
{
	double	new_position[2];
	double	i;

	i = 0;
	while (i <= ray_size)
	{
		new_position[0] = game->p_orient[0] + i * cos(angle);
		new_position[1] = game->p_orient[1] + i * sin(angle);
		mlx_px(game->img_list->player, round(new_position[0]), \
		round(new_position[1]), 0x00ab3425);
		i += 0.5;
	}
}
