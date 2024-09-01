/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:02:07 by mvalerio          #+#    #+#             */
/*   Updated: 2024/09/01 17:27:00 by mvalerio         ###   ########.fr       */
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


double	find_vertical_inter(t_game *game, double angle)
{
	double	x_n;
	double	y_n;
//	double	h;
	double	step[2];
	// double	h_step;
	int	multiplier_x;
	int	multiplier_y;

	if (sin(angle) > 0)
		multiplier_y = 1;
	else
		multiplier_y = -1;

	if (cos(angle) > 0)
	{
		x_n = (int)(game->p_orient[0] / GRID_SIZE) * GRID_SIZE + GRID_SIZE;
		multiplier_x = 1;
	}
	else
	{
		x_n = (int)(game->p_orient[0] / GRID_SIZE) * GRID_SIZE;
		multiplier_x = -1;
	}
//	h = (x_n - game->p_orient[0]) / cos(angle);
//	y_n = h * sin(angle) + game->p_orient[1];
	y_n = (x_n - game->p_orient[0]) * tan(angle) + game->p_orient[1];
	step[0] = GRID_SIZE * multiplier_x;
	// h_step = step[0] * cos(angle);
	// step[1] = h_step * sin(angle);
	step[1] = step[0] * tan(angle);
	while (x_n < game->width && x_n >= 0 && y_n < game->height && y_n >= 0 && get_px_color(game->img_list->minimap, x_n + multiplier_x, y_n + multiplier_y) != MINI_WALL_COLOUR)
	{
		x_n += step[0];
		y_n += step[1];
	}
	return (ft_distance(game->p_orient[0], game->p_orient[1], x_n, y_n));
}

double	find_horizontal_inter(t_game *game, double angle)
{
	double	x_n;
	double	y_n;
//	double	h;
	double	step[2];
	// double	h_step;
	int	multiplier_y;
	int	multiplier_x;

	if (sin(angle) > 0)
	{
		y_n = (int)(game->p_orient[1] / GRID_SIZE) * GRID_SIZE + GRID_SIZE;
		multiplier_y = 1;
	}
	else
	{
		y_n = (int)(game->p_orient[1] / GRID_SIZE) * GRID_SIZE;
		multiplier_y = -1;
	}

	if (cos(angle) > 0)
		multiplier_x = 1;
	else
		multiplier_x = -1;
//	h = (y_n - game->p_orient[1]) / sin(angle);
	x_n = (y_n - game->p_orient[1]) / tan(angle) + game->p_orient[0];
	step[1] = GRID_SIZE * multiplier_y;
	// h_step = step[1] * sin(angle);
	// step[0] = h_step * cos(angle);
	step[0] = step[1] / tan(angle);
	while (x_n < game->width && x_n >= 0 && y_n < game->height && y_n >= 0 && get_px_color(game->img_list->minimap, x_n + multiplier_x, y_n + multiplier_y) != MINI_WALL_COLOUR)
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

	initial_angle = game->p_orient[2] - (game->fov / 2);
	final_angle = game->p_orient[2] + (game->fov / 2);
	while (initial_angle < final_angle)
	{
		vertical_inter = find_vertical_inter(game, initial_angle);
		horizontal_inter = find_horizontal_inter(game, initial_angle);
		if (vertical_inter > horizontal_inter)
			ft_player_ray(game, horizontal_inter, initial_angle);
		else
			ft_player_ray(game, vertical_inter, initial_angle);
		initial_angle += game->fov / game->width;
	}
	return;
}
