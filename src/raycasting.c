/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:02:07 by mvalerio          #+#    #+#             */
/*   Updated: 2024/08/30 17:02:55 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	increment = 0;

int	get_px_color(t_data *img, int x, int y)
{
    int color;

	color = *(int *)(img->addr + (y * img->line_length + \
	x * (img->bits_per_pixel / 8)));
    return color;
}


double	find_vertical_inter(t_game *game, double angle)
{
	int	x_n;
	int	y_n;
	double	h;
	double	step[2];
	double	h_step;
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
	h = (x_n - game->p_orient[0]) / cos(angle);
	y_n = h * sin(angle) + game->p_orient[1];
	step[0] = GRID_SIZE * multiplier_x;
	h_step = step[0] * cos(angle);
	step[1] = h_step * sin(angle);
	while (x_n < game->width && x_n >= 0 && y_n < game->height && y_n >= 0 && get_px_color(game->img_list->minimap, x_n + multiplier_x, y_n + multiplier_y) != MINI_WALL_COLOUR)
	{
		x_n += step[0];
		y_n += step[1];
	}
	return (ft_distance(game->p_orient[0], game->p_orient[1], x_n, y_n));
}

double	find_horizontal_inter(t_game *game, double angle)
{
	int	x_n;
	int	y_n;
	double	h;
	double	step[2];
	double	h_step;
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
	h = (y_n - game->p_orient[1]) / sin(angle);
	x_n = h * cos(angle) + game->p_orient[0];
	step[1] = GRID_SIZE * multiplier_y;
	h_step = step[1] * sin(angle);
	step[0] = h_step * cos(angle);
	while (x_n < game->width && x_n >= 0 && y_n < game->height && y_n >= 0 && get_px_color(game->img_list->minimap, x_n + multiplier_x, y_n + multiplier_y) != MINI_WALL_COLOUR)
	{
		x_n += step[0];
		y_n += step[1];
	}

	return(ft_distance(game->p_orient[0], game->p_orient[1], x_n, y_n));
}

void	ft_player_ray(t_game *game, double ray_size, double angle)
{
	int	new_position[2];
	int	i;

	i = 0;
	while ((double)i <= ray_size)
	{
		new_position[0] = game->p_orient[0] + i * cos(angle);
		new_position[1] = game->p_orient[1] + i * sin(angle);
		mlx_px(game->img_list->player, new_position[0], new_position[1], 0x00ab3425 + increment);
		i++;
	}
	increment += 50;
}

void	cast_rays(t_game *game)
{
	double	initial_angle;
	double	final_angle;
	double vertical_inter;
	double horizontal_inter;

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
