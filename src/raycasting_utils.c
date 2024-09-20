/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:22:58 by mvalerio          #+#    #+#             */
/*   Updated: 2024/09/20 17:30:15 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Gets the color of a given pixel in an image.
 * @param img The image from which to get the pixel color.
 * @param x The x coordinate of the pixel.
 * @param y The y coordinate of the pixel.
 * @return The color of the pixel at (x, y) in the image.
 */
int	get_px_color(t_data *img, int x, int y)
{
	int color;

	color = *(int *)(img->addr + (y * img->line_length + \
	x * (img->bits_per_pixel / 8)));
	return (color);
}

/**
 * @brief Checks if a given point in a ray (x_n, y_n) is
 * the intersection with a wall.
 *
 * @param game The game structure.
 * @param ray The ray of which to check the intersection.
 * @param x_n The x coordinate of the point to check.
 * @param y_n The y coordinate of the point to check.
 * @return 1 if the point is inside the map and not a wall, 0 otherwise.
 */
// char	is_inside_map_ver(t_game *game, t_ray *ray, int x_n, int y_n)
// {
// 	return (x_n < game->width && x_n >= 0 && y_n < game->height && y_n >= 0
// 	&& get_px_color(game->img_list->minimap, x_n + 
// 	ray->multiplier_x, y_n) != WALL_CLR);
// }

char	is_inside_map_ver(t_game *game, t_ray *ray, int x_n, int y_n)
{
	int	color;

	color = get_px_color(game->img_list->minimap, x_n + ray->multiplier_x, y_n);
	if (color == DOOR_CLR)
	{
		ray->is_door = 1;
		return (1);
	}
	return(x_n < game->width && x_n >= 0 && y_n < game->height && y_n >= 0 && \
	color != WALL_CLR);
}

// char	is_inside_map_hor(t_game *game, t_ray *ray, int x_n, int y_n)
// {
// 	return (x_n < game->width && x_n >= 0 && y_n < game->height && y_n >= 0
// 	&& get_px_color(game->img_list->minimap, x_n,
// 	y_n + ray->multiplier_y) != WALL_CLR);
// }

char	is_inside_map_hor(t_game *game, t_ray *ray, int x_n, int y_n)
{
	int	color;

	color = get_px_color(game->img_list->minimap, x_n, y_n + ray->multiplier_y);
	if (color == DOOR_CLR)
	{
		ray->is_door = 1;
		return (1);
	}
	return(x_n < game->width && x_n >= 0 && y_n < game->height && y_n >= 0 && \
	color != WALL_CLR);
}

