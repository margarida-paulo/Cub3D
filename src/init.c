/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:22:55 by mvalerio          #+#    #+#             */
/*   Updated: 2024/09/03 12:03:46 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_data	*init_img(t_game *game, int width, int height)
{
	t_data *img;

	img = malloc(sizeof(t_data));
	img->img = mlx_new_image(game->mlx, width, height);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), &(img->line_length), &(img->endian));
	img->width = width;
	img->height = height;
	return (img);
}


/**
 * Initializes the visited array to keep track of visited coordinates.
 * used in check_map_borders() function.
 * @param map The map struct.
 * @return The 2d array to keep track of visited coordinates.
 */
int	**init_visited_arr(t_map *map)
{
	int	**visited;
	int	i;
	int	j;

	visited = malloc(sizeof(int *) * map->game->height);
	i = 0;
	while (i < map->game->height)
	{
		visited[i] = malloc(sizeof(int) * map->game->width);
		i++;
	}
	i = 0;
	while (i < map->game->height)
	{
		j = 0;
		while (j < map->game->width)
		{
			visited[i][j] = 0;
			j++;
		}
		i++;
	}
	return (visited);
}

// Initializes the instance and the window of the minilibx into the game struct.
void	minilibx_init(t_game *game) {

	game->fov = FOV;
    game->height = ft_arrlen(game->map.map_array) * GRID_SIZE;
    game->width = ft_strlen(game->map.map_array[0]) * GRID_SIZE;
    game->mlx = mlx_init();
    game->mlx_win = mlx_new_window(game->mlx, game->width, game->height, "The best Cub3D you've ever seen");
    game->img_list = malloc(sizeof(t_pics));
    game->img_list->minimap = NULL;
    game->img_list->player = NULL;
	game->p_orient[0] = game->p_orient[0] * GRID_SIZE + GRID_SIZE / 2;
	game->p_orient[1] = game->p_orient[1] * GRID_SIZE + GRID_SIZE / 2;
	game->key_press = 0;
	game->origin[0] = 0;
	game->origin[1] = 0;
	game->move_rate = (game->width * game->height * 0.3/260000);
    ft_build_minimap(game);
    ft_build_player(game);
	game->current_screen = ft_merge_images(game, game->img_list->minimap, game->img_list->player, game->origin);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->current_screen->img, 0, 0);
}

