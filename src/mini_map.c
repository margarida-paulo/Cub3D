/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:44:41 by mvalerio          #+#    #+#             */
/*   Updated: 2024/08/16 17:01:01 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_bckg_square(t_game *game, int curr_x, int curr_y)
{
	int	temp_curr_x;

	curr_y++;
	while (curr_y < PLAYER_SIZE)
	{
		temp_curr_x = curr_x + 1;
		while (temp_curr_x < PLAYER_SIZE)
		{
			mlx_px(game->img_list->p_minimap, curr_x, curr_y, MINIMAP_COLOUR);
			temp_curr_x++;
		}
		curr_y++;
	}
}

void	ft_minimap_bckg(t_game *game)
{
	t_data	*img;
	int		curr_x;
	int		curr_y;

	img = malloc(sizeof(t_data));
	game->img_list->p_minimap = img;
	img->img = mlx_new_image(game->mlx, game->width, game->height);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), &(img->line_length), &(img->endian));
	curr_y = 0;
	while (curr_y < game->height)
	{
		curr_x = 0;
		while (curr_x < game->width)
		{
			ft_bckg_square(game, curr_x, curr_y);
			curr_x += PLAYER_SIZE;
		}
		curr_y += PLAYER_SIZE;
	}

}

// Inserts a square in the minimap.
// game->p_position[0] = x
// game->p_position[1] = y
// The colour is, for now, PLAYER_COLOUR. In the future it would be cool if
// the colour could be random or based on the texture colours.
void	ft_put_player_map(t_game *game)
{
	t_data	*img;
	int		i;
	int		a;

	img = game->img_list->p_minimap;
	i = 0;
	while (i < PLAYER_SIZE)
	{
		a = 0;
		while (a < PLAYER_SIZE)
		{
			mlx_px(img, game->p_position[0] + i, game->p_position[1] + a, PLAYER_COLOUR);
			a++;
		}
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, img->img, 0, 0);
}

int	ft_move(t_game *game)

{
	(void)game;
	return (0);
}
