/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:44:41 by mvalerio          #+#    #+#             */
/*   Updated: 2024/08/16 19:24:18 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_bckg_square(t_game *game, int curr_x, int curr_y)
{
	int	temp_curr_x;
	int	temp_curr_y;

	temp_curr_y = curr_y + 1;
	while (temp_curr_y < curr_y + GRID_SIZE)
	{
		temp_curr_x = curr_x + 1;
		while (temp_curr_x < curr_x + GRID_SIZE)
		{
			if(game->map[curr_y / GRID_SIZE][curr_x / GRID_SIZE] == '1')
				mlx_px(game->img_list->bckg, temp_curr_x, temp_curr_y, MINI_WALL_COLOUR);
			else
				mlx_px(game->img_list->bckg, temp_curr_x, temp_curr_y, MINI_FLOOR_COLOUR);
			temp_curr_x++;
		}
		temp_curr_y++;
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->img_list->bckg->img, 0, 0);
	}
}

void	ft_minimap_bckg(t_game *game)
{
	t_data	*img;
	int		curr_x;
	int		curr_y;

	img = malloc(sizeof(t_data));
	game->img_list->bckg = img;
	img->img = mlx_new_image(game->mlx, game->width, game->height);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), &(img->line_length), &(img->endian));
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
	mlx_put_image_to_window(game->mlx, game->mlx_win, img->img, 0, 0);
}

// Inserts a square in the minimap.
// game->p_orient[0] = x
// game->p_orient[1] = y
// The colour is, for now, PLAYER_COLOUR. In the future it would be cool if
// the colour could be random or based on the texture colours.
void	ft_put_player_map(t_game *game)
{
	t_data	*img;
	int		curr_x;
	int		curr_y;

	img = malloc(sizeof(t_data));
	game->img_list->p_minimap = img;
	img->img = mlx_new_image(game->mlx, GRID_SIZE / 3, GRID_SIZE / 3);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), &(img->line_length), &(img->endian));
	curr_y = 0;
	while (curr_y < GRID_SIZE / 3)
	{
		curr_x = 0;
		while (curr_x < GRID_SIZE / 3)
		{
			mlx_px(img, curr_x, curr_y, PLAYER_COLOUR);
			curr_x++;
		}
		curr_y++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, img->img, game->p_orient[0] * GRID_SIZE + 1, game->p_orient[1] * GRID_SIZE + 1);
}

int	ft_move(t_game *game)

{
	(void)game;
	return (0);
}
