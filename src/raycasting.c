/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:02:07 by mvalerio          #+#    #+#             */
/*   Updated: 2024/09/11 10:57:57 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
	while (is_inside_map(game, ray, x_n, y_n))
	{
		x_n += step[0];
		y_n += step[1];
	}
	info = malloc(sizeof(double *) * 3);
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
	while (is_inside_map(game, ray, x_n, y_n))
	{
		x_n += step[0];
		y_n += step[1];
	}
	info = malloc(sizeof(double *) * 3);
	info[0] = x_n;
	info[1] = y_n;
	info[2] = ft_distance(game->p_orient[0], game->p_orient[1], x_n, y_n);
	return (info);
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

void	ft_set_wall_type(t_ray *ray)
{
	if (ray->inter_type == HORIZONTAL)
	{
		if (ray->multiplier_y > 0)
			ray->wall_type = SO;
		else
			ray->wall_type = NO;
	}
	else
	{
		if (ray->multiplier_x > 0)
			ray->wall_type = EA;
		else
			ray->wall_type = WE;
	}
}

/**
 * @brief Initializes a ray.
 *
 * Given a ray structure, an angle and a game structure, this function
 * initializes the ray by calculating its sin and cos, and by finding its
 * intersection with the map in both the horizontal and vertical directions.
 *
 * @param ray The ray structure to be initialized.
 * @param angle The angle of the ray.
 * @param game The game structure.
 */
void	ft_ray_init(t_ray *ray, double angle, t_game *game)
{
	double	*vertical_inter;
	double	*horizontal_inter;
	double	*inter;

	ray->inter_type = HORIZONTAL;
	ray->angle = angle;
	ray->sin = sin(ray->angle);
	ray->cos = cos(ray->angle);
	ray->multiplier_y = copysign(1, ray->sin);
	ray->multiplier_x = copysign(1, ray->cos);
	vertical_inter = find_vertical_inter(game, ray);
	horizontal_inter = find_horizontal_inter(game, ray);
	if (vertical_inter[2] < horizontal_inter[2])
	{
		inter = vertical_inter;
		ray->inter_type = VERTICAL;
	}
	else
		inter = horizontal_inter;
	ray->x_n = inter[0];
	ray->y_n = inter[1];
	ray->distance = inter[2];
	ft_set_wall_type(ray);
	free(horizontal_inter);
	free(vertical_inter);
}

/**
 * @brief Casts rays from the player's position.
 *
 * Given a game structure, this function casts rays from the player's position
 * in all directions within the player's field of view. Each ray is initialized
 * with the ft_ray_init function and then used to calculate the distance from
 * the player to the first collision with the map in the ray's direction. The
 * result is then used to draw the ray on the screen with the ft_draw_ray
 * function.
 *
 * @param game The game structure.
 */
void	cast_rays(t_game *game)
{
	double	initial_angle;
	double	final_angle;
	t_ray	ray;
	int		x;

	x = 0;
	initial_angle = game->p_orient[2] - (game->fov / 2);
	final_angle = game->p_orient[2] + (game->fov / 2);
	while (initial_angle < final_angle)
	{
		ft_ray_init(&ray, initial_angle, game);
		ft_draw_ray(game, ray.distance, initial_angle);
		render(game, &ray, x);
		initial_angle += game->fov / game->width;
		x++;
	}
}

void	calculate_wall_height(t_game* game, t_ray* ray, int* draw_start, int* draw_end)
{
	int	line_height;

	(void)game;

	line_height = (int)(WIN_HEIGHT / ray->distance);
	*draw_start = (-line_height / 2) + (WIN_HEIGHT / 2);
	if (*draw_start < 0)
		*draw_start = 0;
	*draw_end = (line_height / 2) + (WIN_HEIGHT / 2);
	if (*draw_end > WIN_HEIGHT)
		*draw_end = WIN_HEIGHT - 1;
	ray->line_height = line_height;
}

void	set_texture_coordinates(t_game* game, t_ray* ray)
{
	double	wall_x;

	if (ray->wall_type == NO || ray->wall_type == SO)
		wall_x = ray->x_n;
	else
		wall_x = ray->y_n;
	wall_x -= floor(wall_x);
	ray->tex_x = (int)(wall_x * (double)game->img_list->wall[ray->wall_type].width);
	if ((ray->wall_type == NO || ray->wall_type == SO) && ray->cos > 0)
		ray->tex_x = game->img_list->wall[ray->wall_type].width - ray->tex_x - 1;
	if ((ray->wall_type == EA || ray->wall_type == WE) && ray->sin < 0)
		ray->tex_x = game->img_list->wall[ray->wall_type].width - ray->tex_x - 1;
}

void	draw_wall_slice(t_game* game, t_ray *ray, int x, int draw_start, int draw_end)
{
	int	y;
	int	tex_y;
	int	color;

	y = draw_start;
	while (y < draw_end)
	{
		tex_y = (int)(((y - (-ray->line_height / 2 + WIN_HEIGHT / 2)) * game->img_list->wall[ray->wall_type].height) / ray->line_height);
		 if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= game->img_list->wall[ray->wall_type].height)
			tex_y = game->img_list->wall[ray->wall_type].height - 1;
		color = get_px_color(&game->img_list->wall[ray->wall_type], ray->tex_x, tex_y);
		mlx_px(game->img_list->screen, x, y, color);
		y++;
	}
}

void	render(t_game *game, t_ray *ray, int x)
{
	int	draw_start;
	int	draw_end;

	calculate_wall_height(game, ray, &draw_start, &draw_end);
	set_texture_coordinates(game, ray);
	draw_wall_slice(game, ray, x, draw_start, draw_end);
}
