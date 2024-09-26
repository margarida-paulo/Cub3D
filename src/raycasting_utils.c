/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:22:58 by mvalerio          #+#    #+#             */
/*   Updated: 2024/09/26 12:24:37 by mvalerio         ###   ########.fr       */
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
	int	color;

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
char	is_inside_map_ver(t_game *game, t_ray *ray, int x_n, int y_n)
{
	return (x_n < game->width && x_n >= 0 && y_n < game->height && y_n >= 0 \
	&& get_px_color(game->img_list->minimap, x_n + \
	ray->multiplier_x, y_n) != WALL_CLR);
}

char	is_inside_map_hor(t_game *game, t_ray *ray, int x_n, int y_n)
{
	return (x_n < game->width && x_n >= 0 && y_n < game->height && y_n >= 0 \
	&& get_px_color(game->img_list->minimap, x_n, \
	y_n + ray->multiplier_y) != WALL_CLR);
}

/**
 * @brief Finds the vertical intersection of the ray with the map.
 *
 * Given a ray and a game, this function finds the point of intersection of
 * the ray with the map in the vertical direction. The intersection is found
 * by moving the ray in the vertical direction and checking the color of the
 * pixel at that point. If the color is not a wall, the intersection is the
 * point at which the ray intersects the map.
 *
 * @param game The game structure.
 * @param ray The ray to find the intersection for.
 * @return A double array of size 3 containing the x, y coordinates of the
 * intersection and the distance from the player to the intersection.
 */
double	*find_vertical_inter(t_game *game, t_ray *ray)
{
	double	x_n;
	double	y_n;
	double	step[2];
	double	*info;

	if (ray->cos > 0)
		x_n = (int)(game->p_orient[0] / GRID_SIZE) * GRID_SIZE + GRID_SIZE;
	else
		x_n = (int)(game->p_orient[0] / GRID_SIZE) * GRID_SIZE;
	y_n = (x_n - game->p_orient[0]) * tan(ray->angle) + game->p_orient[1];
	step[0] = GRID_SIZE * ray->multiplier_x;
	step[1] = step[0] * tan(ray->angle);
	while (is_inside_map_ver(game, ray, x_n, y_n))
	{
		x_n += step[0];
		y_n += step[1];
	}
	info = malloc(sizeof(double) * 3);
	info[0] = x_n;
	info[1] = y_n;
	info[2] = ft_distance(game->p_orient[0], game->p_orient[1], x_n, y_n);
	return (info);
}

/**
 * @brief Finds the horizontal intersection of the ray with the map.
 *
 * Given a ray and a game, this function finds the point of intersection of
 * the ray with the map in the horizontal direction. The intersection is found
 * by moving the ray in the horizontal direction and checking the color of the
 * pixel at that point. If the color is not a wall, the intersection is the
 * point at which the ray intersects the map.
 *
 * @param game The game structure.
 * @param ray The ray to find the intersection for.
 * @return A double array of size 3 containing the x, y coordinates of the
 * intersection and the distance from the player to the intersection.
 */
double	*find_horizontal_inter(t_game *game, t_ray *ray)
{
	double	x_n;
	double	y_n;
	double	step[2];
	double	*info;

	if (ray->sin > 0)
		y_n = (int)(game->p_orient[1] / GRID_SIZE) * GRID_SIZE + GRID_SIZE;
	else
		y_n = (int)(game->p_orient[1] / GRID_SIZE) * GRID_SIZE;
	x_n = (y_n - game->p_orient[1]) / tan(ray->angle) + game->p_orient[0];
	step[1] = GRID_SIZE * ray->multiplier_y;
	step[0] = step[1] / tan(ray->angle);
	while (is_inside_map_hor(game, ray, x_n, y_n))
	{
		x_n += step[0];
		y_n += step[1];
	}
	info = malloc(sizeof(double) * 3);
	info[0] = x_n;
	info[1] = y_n;
	info[2] = ft_distance(game->p_orient[0], game->p_orient[1], x_n, y_n);
	return (info);
}
