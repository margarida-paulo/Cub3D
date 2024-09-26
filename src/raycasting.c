/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:02:07 by mvalerio          #+#    #+#             */
/*   Updated: 2024/09/26 12:29:37 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
#include <stdio.h>

void	ft_set_ray_angle_info(t_ray *ray, double angle)
{
	ray->inter_type = HORIZONTAL;
	ray->angle = angle;
	ray->sin = sin(ray->angle);
	ray->cos = cos(ray->angle);
	ray->multiplier_y = copysign(1, ray->sin);
	ray->multiplier_x = copysign(1, ray->cos);
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

	ft_set_ray_angle_info(ray, angle);
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
	if (vertical_inter[2] == horizontal_inter[2] && game->prev_wall_type != -1)
		ray->wall_type = game->prev_wall_type;
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
 * function. Add:
 * ft_draw_ray(game, game->ray.distance, initial_angle);
 * after ft_ray_init to draw the rays in the minimap
 *
 * @param game The game structure.
 */
void	cast_rays(t_game *game)
{
	double	initial_angle;
	double	final_angle;
	int		x;
	double	angle_diff;

	x = 0;
	initial_angle = game->p_orient[2] - (game->fov / 2);
	final_angle = game->p_orient[2] + (game->fov / 2);
	render_floor_ceiling(game);
	game->prev_wall_type = -1;
	while (initial_angle < final_angle)
	{
		angle_diff = initial_angle - game->p_orient[2];
		ft_ray_init(&(game->ray), initial_angle, game);
		game->ray.distance *= cos(angle_diff);
		render(game, &(game->ray), x);
		initial_angle += game->fov / WIN_WIDTH;
		x++;
		game->prev_wall_type = game->ray.wall_type;
	}
}

void	calculate_wall_height(t_game *game, t_ray *ray, \
int *draw_start, int *draw_end)
{
	int		line_height;
	double	normalized_distance;

	normalized_distance = ray->distance / GRID_SIZE;
	line_height = (int)(WIN_HEIGHT / normalized_distance);
	*draw_start = (-line_height / 2) + (WIN_HEIGHT / 2) + game->head_bob_offset;
	if (*draw_start < 0)
		*draw_start = 0;
	*draw_end = (line_height / 2) + (WIN_HEIGHT / 2) + game->head_bob_offset;
	if (*draw_end > WIN_HEIGHT)
		*draw_end = WIN_HEIGHT - 1;
	ray->line_height = line_height;
}

void	set_texture_coordinates(t_game *game, t_ray *ray, int draw_start)
{
	double	wall_x;
	double	tex_pos;
	double	step;

	if (ray->wall_type == NO || ray->wall_type == SO)
		wall_x = ray->x_n / GRID_SIZE;
	else
		wall_x = ray->y_n / GRID_SIZE;
	wall_x -= floor(wall_x);
	ray->tex_x = (int)(wall_x * \
	(double)game->img_list->wall[ray->wall_type]->width);
	ray->tex_x = ray->tex_x % game->img_list->wall[ray->wall_type]->width;
	step = 1.0 * game->img_list->wall[ray->wall_type]->height \
	/ ray->line_height;
	tex_pos = (draw_start - game->head_bob_offset - WIN_HEIGHT \
	/ 2 + ray->line_height / 2) * step;
	ray->tex_pos = tex_pos;
}
