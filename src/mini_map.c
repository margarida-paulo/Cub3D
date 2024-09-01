/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:44:41 by mvalerio          #+#    #+#             */
/*   Updated: 2024/09/01 16:07:37 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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


// Function to calculate the area of a triangle
float area(int x1, int y1, int x2, int y2, int x3, int y3) {
    return fabs((x1*(y2-y3) + x2*(y3-y1) + x3*(y1-y2)) / 2.0);
}

// Function to check if a point (x, y) is inside or on the border of the triangle
int is_inside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y) {
    // Calculate the area of the triangle ABC
    float A = area(x1, y1, x2, y2, x3, y3);

    // Calculate the area of the triangle PBC
    float A1 = area(x, y, x2, y2, x3, y3);

    // Calculate the area of the triangle PAC
    float A2 = area(x1, y1, x, y, x3, y3);

    // Calculate the area of the triangle PAB
    float A3 = area(x1, y1, x2, y2, x, y);

    // Check if the sum of A1, A2, and A3 is equal to A
    return (A == A1 + A2 + A3);
}

int		ft_move(t_game *game)
{
	if (game->key_press == XK_w)
	{
		game->p_orient[0] += 0.03 * cos(game->p_orient[2]);
		game->p_orient[1] += 0.03 * sin(game->p_orient[2]);
	}
	else if (game->key_press == XK_s)
	{
		game->p_orient[0] -= 0.03 * cos(game->p_orient[2]);
		game->p_orient[1] -= 0.03 * sin(game->p_orient[2]);
	}

	if (game->key_press == XK_a)
	{
		game->p_orient[0] += 0.03 * cos(game->p_orient[2] - M_PI / 2);
		game->p_orient[1] += 0.03 * sin(game->p_orient[2] - M_PI / 2);
	}
	else if (game->key_press == XK_d)
	{
		game->p_orient[0] -= 0.03 * cos(game->p_orient[2] - M_PI / 2);
		game->p_orient[1] -= 0.03 * sin(game->p_orient[2] - M_PI / 2);
	}
	ft_render_screen(game);
	return (0);
}

double	ft_distance(int x1, int y1, int x2, int y2)
{
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

void	ft_bckg_square(t_game *game, int curr_x, int curr_y)
{
	int	temp_curr_x;
	int	temp_curr_y;

	temp_curr_y = curr_y + 1;
	while (temp_curr_y <= curr_y + GRID_SIZE)
	{
		temp_curr_x = curr_x + 1;
		while (temp_curr_x <= curr_x + GRID_SIZE)
		{
			if(game->map.map_array[curr_y / GRID_SIZE][curr_x / GRID_SIZE] == '1')
				mlx_px(game->img_list->minimap, temp_curr_x, temp_curr_y, MINI_WALL_COLOUR);
			else if(game->map.map_array[curr_y / GRID_SIZE][curr_x / GRID_SIZE] == ' ')
				mlx_px(game->img_list->minimap, temp_curr_x, temp_curr_y, 0x00000000);
			else
				mlx_px(game->img_list->minimap, temp_curr_x, temp_curr_y, MINI_FLOOR_COLOUR);
			temp_curr_x++;
		}
		temp_curr_y++;
	}
}

void	ft_build_minimap(t_game *game)
{
	t_data	*img;
	int		curr_x;
	int		curr_y;

	if (game->img_list->minimap == NULL)
	{
		img = malloc(sizeof(t_data));
		img->img = mlx_new_image(game->mlx, game->width, game->height);
		img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), &(img->line_length), &(img->endian));
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

// Inserts a square in the minimap.
// game->p_orient[0] = x
// game->p_orient[1] = y
// The colour is, for now, PLAYER_COLOUR. In the future it would be cool if
// the colour could be random or based on the texture colours.
void	ft_build_player(t_game *game)
{
	int 	center[2];
	double		v1[2];
	double		v2[2];
	double		v3[2];
	double	angle = game->p_orient[2]; // Adjust angle to face south
	double		pos[2];

	if (game->img_list->player == NULL)
	{
		game->img_list->player = malloc(sizeof(t_data));
		game->img_list->player->img = mlx_new_image(game->mlx, game->width, game->height);
		game->img_list->player->addr = mlx_get_data_addr(game->img_list->player->img, &(game->img_list->player->bits_per_pixel), &(game->img_list->player->line_length), &(game->img_list->player->endian));
		game->img_list->player->width = game->width;
		game->img_list->player->height = game->height;
	}
	ft_clear_img(game->img_list->player, game->img_list->player->width, game->img_list->player->height);
	cast_rays(game);
	center[0] = (int)game->p_orient[0];
	center[1] = (int)game->p_orient[1];

	v1[0] = center[0] + (PLAYER_RAY * cos(angle));
	v1[1] = center[1] + (PLAYER_RAY * sin(angle));

	v2[0] = center[0] + (PLAYER_RAY * cos(angle - (2 * M_PI / 2.5)));
	v2[1] = center[1] + (PLAYER_RAY * sin(angle - (2 * M_PI / 2.5)));

	v3[0] = center[0] + (PLAYER_RAY * cos(angle + (2 * M_PI / 2.5)));
	v3[1] = center[1] + (PLAYER_RAY * sin(angle + (2 * M_PI / 2.5)));

	pos[1] = center[1] - PLAYER_SIZE / 2;

	while (pos[1] < center[1] + PLAYER_SIZE / 2)
	{
		pos[0] = center[0] - PLAYER_SIZE / 2;
		while (pos[0] < center[0] + PLAYER_SIZE / 2)
		{
			if(is_inside(v1[0], v1[1], v2[0], v2[1], v3[0], v3[1], pos[0], pos[1]))
			{
				mlx_px(game->img_list->player, pos[0], pos[1], PLAYER_COLOUR);
			}
			pos[0]++;
		}
		pos[1]++;
	}
}

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
