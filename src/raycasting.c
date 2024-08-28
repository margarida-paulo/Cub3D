/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 11:02:07 by mvalerio          #+#    #+#             */
/*   Updated: 2024/08/28 17:15:05 by mvalerio         ###   ########.fr       */
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


int	find_inter_x(t_game *game, double angle)
{
	int	inter_y;
	int	inter_x;
	int	i_x;
	int	i_y;

	if (angle < 0)
		angle = 2 * M_PI + angle;
	if (angle <= M_PI)
	{
		inter_y = ((int)game->p_orient[1] / GRID_SIZE) * GRID_SIZE + GRID_SIZE;
		i_y = 1;
	}
	else
	{
		inter_y = ((int)game->p_orient[1] / GRID_SIZE) * GRID_SIZE;
		i_y = -1;
	}

	if (angle >= M_PI / 2 && angle <= 3 * M_PI / 2)
	{
		inter_x = (int)game->p_orient[0] + (inter_y - (int)game->p_orient[1]) / tan(angle);
		i_x = -1;
	}
	else
	{
		inter_x = (int)game->p_orient[0] + (inter_y - (int)game->p_orient[1]) / tan(angle);
		i_x = 1;
	}
	while (get_px_color(game->img_list->minimap, inter_x + i_x, inter_y + i_y) != MINI_WALL_COLOUR)
	{
		inter_y += GRID_SIZE * i_y;
		inter_x += (GRID_SIZE / fabs(tan(angle))) * i_x;
	}

	mlx_px(game->img_list->minimap, inter_x, inter_y, 0xab45cdff);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_list->minimap->img, 0, 0);

	return (inter_x);
}

int	find_inter_y(t_game *game, double angle)
{
	int	inter_y;
	int	inter_x;
	int	i_x;
	int	i_y;

	if (angle < 0)
		angle = 2 * M_PI + angle;
	if (angle >= M_PI / 2 && angle <= 3 * M_PI / 2 )
	{
		inter_x = ((int)game->p_orient[0] / GRID_SIZE) * GRID_SIZE;
		i_x = -1;
	}
	else
	{
		inter_x = ((int)game->p_orient[0] / GRID_SIZE) * GRID_SIZE + GRID_SIZE;
		i_x = 1;
	}

	if (angle >= 0 && angle <= M_PI)
	{
		inter_y = (int)game->p_orient[1] + (inter_x - (int)game->p_orient[0]) / tan(angle);
		i_y = 1;
	}
	else
	{
		inter_y = (int)game->p_orient[1] + (inter_x - (int)game->p_orient[0]) / tan(angle);;
		i_y = -1;
	}
	while (get_px_color(game->img_list->minimap, inter_x + i_x, inter_y + i_y) != MINI_WALL_COLOUR)
	{
		inter_x += GRID_SIZE * i_x;
		inter_y += (GRID_SIZE / tan(angle)) * i_y;
	}
			mlx_px(game->img_list->minimap, inter_x, inter_y, 0xab45cdff);
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_list->minimap->img, 0, 0);

	return(inter_y);

}

void	cast_rays(t_game *game)
{
	double	initial_angle;
	double	final_angle;
	int		inter_x;
//	int		inter_y;

	initial_angle = game->p_orient[2] - (game->fov / 2);
	final_angle = game->p_orient[2] + (game->fov / 2);
	printf("FOV: %f | Angle: %f | Initial angle: %f | End angle: %f\n", game->fov, game->p_orient[2], initial_angle, final_angle);

	while (initial_angle < final_angle)
	{
		inter_x = find_inter_x(game, initial_angle);
//		inter_y = find_inter_y(game, initial_angle);
//		mlx_px(game->img_list->minimap, inter_x, inter_y, 0xab45cdff);
//		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_list->minimap->img, 0, 0);
		initial_angle += game->fov / game->width;
	}
	fflush(stdout);
	return;
}
