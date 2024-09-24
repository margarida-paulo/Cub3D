/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:05:40 by plashkar          #+#    #+#             */
/*   Updated: 2024/09/23 00:16:36 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * Frees a 2d array. used to free an array of strings.
 * @param src The array of strings to be freed.
 * @return void
*/
void	free_2d_array(char **src)
{
	int	i;

	i = 0;
	while (src && src[i])
	{
		free(src[i]);
		i++;
	}
	free(src);
}

/**
 * Frees the map struct.
 * @param map The map struct to be freed.
 * @return void
*/
void	free_map_struct(t_map *map)
{
	free_2d_array(map->map_array);
	free(map->no_texture);
	free(map->so_texture);
	free(map->we_texture);
	free(map->ea_texture);
	free(map->f_color);
	free(map->c_color);
}

/**
 * Frees the visited array used in the floodfill algorithm.
 * @param visited The 2d array to be freed.
 * @param map The map struct.
 * @return void
*/
void	free_visited(int **visited, t_map *map)
{
	int	i;

	i = 0;
	while (i < map->game->height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

void	free_img(t_game *game, t_data *img)
{
	if (img != NULL)
	{
		mlx_destroy_image(game->mlx, img->img);
		free(img);
	}
}

void	free_wall_textures(t_game *game)
{
	free_img(game, game->img_list->wall[NO]);
	free_img(game, game->img_list->wall[SO]);
	free_img(game, game->img_list->wall[WE]);
	free_img(game, game->img_list->wall[EA]);
}
