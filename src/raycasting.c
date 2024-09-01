/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:02:07 by mvalerio          #+#    #+#             */
/*   Updated: 2024/09/01 18:25:04 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"


int	get_px_color(t_data *img, int x, int y)
{
    int color;

	color = *(int *)(img->addr + (y * img->line_length + \
	x * (img->bits_per_pixel / 8)));
    return color;
}


void	ft_ray_init(t_ray *ray, double angle)
{
	ray->angle = angle;
	ray->sin = sin(ray->angle);
	ray->cos = cos(ray->angle);
	if (ray->sin > 0)
		ray->multiplier_y = 1;
	else
		ray->multiplier_y = -1;
	if (ray->cos > 0)
		ray->multiplier_x = 1;
	else
		ray->multiplier_x = -1;
}

double	find_vertical_inter(t_game *game, t_ray *ray)
{
	double	x_n;
	double	y_n;
	double	step[2];

	if (ray->cos > 0)
		x_n = (int)(game->p_orient[0] / GRID_SIZE) * GRID_SIZE + GRID_SIZE;
	else
		x_n = (int)(game->p_orient[0] / GRID_SIZE) * GRID_SIZE;
	y_n = (x_n - game->p_orient[0]) * tan(ray->angle) + game->p_orient[1];
	step[0] = GRID_SIZE * ray->multiplier_x;
	step[1] = step[0] * tan(ray->angle);
	while (x_n < game->width && x_n >= 0 && y_n < game->height && y_n >= 0 && get_px_color(game->img_list->minimap, x_n + ray->multiplier_x, y_n + ray->multiplier_y) != MINI_WALL_COLOUR)
	{
		x_n += step[0];
		y_n += step[1];
	}
	return (ft_distance(game->p_orient[0], game->p_orient[1], x_n, y_n));
}

double	find_horizontal_inter(t_game *game, t_ray *ray)
{
	double	x_n;
	double	y_n;
	double	step[2];


	if (ray->sin > 0)
		y_n = (int)(game->p_orient[1] / GRID_SIZE) * GRID_SIZE + GRID_SIZE;
	else
		y_n = (int)(game->p_orient[1] / GRID_SIZE) * GRID_SIZE;
	x_n = (y_n - game->p_orient[1]) / tan(ray->angle) + game->p_orient[0];
	step[1] = GRID_SIZE * ray->multiplier_y;
	step[0] = step[1] / tan(ray->angle);
	while (x_n < game->width && x_n >= 0 && y_n < game->height && y_n >= 0 && get_px_color(game->img_list->minimap, x_n + ray->multiplier_x, y_n + ray->multiplier_y) != MINI_WALL_COLOUR)
	{
		x_n += step[0];
		y_n += step[1];
	}

	return(ft_distance(game->p_orient[0], game->p_orient[1], x_n, y_n));
}

void	ft_player_ray(t_game *game, double ray_size, double angle)
{
	double	new_position[2];
	double	i;

	i = 0;
	while (i <= ray_size)
	{
		new_position[0] = game->p_orient[0] + i * cos(angle);
		new_position[1] = game->p_orient[1] + i * sin(angle);
		mlx_px(game->img_list->player, round(new_position[0]), round(new_position[1]), 0x00ab3425);
		i+= 0.5;
	}
}

void	cast_rays(t_game *game)
{
	double	initial_angle;
	double	final_angle;
	double	vertical_inter;
	double	horizontal_inter;
	t_ray	ray;

	initial_angle = game->p_orient[2] - (game->fov / 2);
	final_angle = game->p_orient[2] + (game->fov / 2);
	while (initial_angle < final_angle)
	{
		ft_ray_init(&ray, initial_angle);
		vertical_inter = find_vertical_inter(game, &ray);
		horizontal_inter = find_horizontal_inter(game, &ray);
		if (vertical_inter > horizontal_inter)
			ft_player_ray(game, horizontal_inter, initial_angle);
		else
			ft_player_ray(game, vertical_inter, initial_angle);
		initial_angle += game->fov / game->width;
	}
	return;
}
