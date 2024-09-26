/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:22:55 by mvalerio          #+#    #+#             */
/*   Updated: 2024/09/26 14:08:09 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Initializes a new image with the given width and height
 *
 * It takes a pointer to a t_game struct, a width and a height.
 * It first allocates memory for the t_data struct, then
 * creates a new mlx image with the given width and height.
 * It then gets the address of the image data, and stores the
 * bits per pixel, line length and endian in the t_data struct.
 * Finally, it stores the width and height of the image in the
 * t_data struct and returns the allocated t_data struct.
 *
 * @param game the pointer to the t_game struct
 * @param width the width of the image
 * @param height the height of the image
 * @return the pointer to the allocated t_data struct
 */
t_data	*init_img(t_game *game, int width, int height)
{
	t_data	*img;

	img = malloc(sizeof(t_data));
	img->img = mlx_new_image(game->mlx, width, height);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), \
	&(img->line_length), &(img->endian));
	img->width = width;
	img->height = height;
	return (img);
}

/**
 * @brief Initializes the visited array to keep track of visited coordinates.
 *
 * It is used in check_map_borders() function.
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

/**
 * @brief Helper function to initialize MiniLibX variables.
 *
 * This function is a helper for ft_init_game() and sets the game state to
 * STATE_MENU, sets the field of view to FOV, and sets the minimap, player,
 * and cropped minimap images to NULL.
 *
 * @param game The game structure.
 */
void	minilibx_init_helper(t_game *game)
{
	game->fov = FOV / 3;
	game->state = STATE_MENU;
	game->img_list->cropped_minimap = NULL;
	game->img_list->minimap = NULL;
	game->img_list->player = NULL;
}

/**
 * @brief Initializes the minilibx window and its resources.
 *
 * This function takes a pointer to a t_game struct and initializes the
 * minilibx window and its resources. It first sets the width and height
 * of the map, then initializes the mlx pointer, creates a new window with
 * the WIN_WIDTH and WIN_HEIGHT and title, and allocates memory for
 * the t_pics struct. It then calls minilibx_init_helper() to initialize some
 * of the default values in the game struct, initializes the minimap and screen
 * images, loads the wall textures, and calculates the player's initial
 * position. Finally, it builds the minimap and player images, and sets the
 * current screen to the merged image of the two.
 *
 * @param game The pointer to the t_game struct.
 * @return void
 */
void	minilibx_init(t_game *game)
{
	game->height = ft_arrlen(game->map.map_array) * GRID_SIZE;
	game->width = ft_strlen(game->map.map_array[0]) * GRID_SIZE;
	game->mlx = mlx_init();
	game->game_window = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, \
	"IKEA simulator");
	game->img_list = ft_calloc(sizeof(t_pics), 1);
	minilibx_init_helper(game);
	game->img_list->cropped_minimap = init_img(game, MINIMAP_WIDTH, \
	MINIMAP_HEIGHT);
	game->img_list->screen = init_img(game, WIN_WIDTH, WIN_HEIGHT);
	load_wall_textures(game);
	game->p_orient[0] = game->p_orient[0] * GRID_SIZE + GRID_SIZE / 2;
	game->p_orient[1] = game->p_orient[1] * GRID_SIZE + GRID_SIZE / 2;
	game->key_press = 0;
	game->origin[0] = 0;
	game->origin[1] = 0;
	game->move_rate = MOVE_SPEED;
	ft_build_minimap(game);
	ft_build_player(game);
	game->current_screen = ft_merge_images(game, game->img_list->minimap, \
	game->img_list->player, game->origin);
	ft_init_cropped_minimap(game);
	game->head_bob_offset = 0;
	game->head_bob_phase = 0;
}

/**
 * @brief Initializes the cropped minimap image.
 *
 * This function allocates memory for a new t_data struct and initializes a
 * new mlx image with the given width and height. It uses the same logic as
 * the init_img() function.
 *
 * @param game the pointer to the t_game struct
 * @return void
 */
void	ft_init_cropped_minimap(t_game *game)
{
	t_data	*img;

	if (game->img_list->cropped_minimap == NULL)
	{
		img = malloc(sizeof(t_data));
		img->img = mlx_new_image(game->mlx, MINIMAP_WIDTH, MINIMAP_HEIGHT);
		img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), \
		&(img->line_length), &(img->endian));
		img->width = MINIMAP_WIDTH;
		img->height = MINIMAP_HEIGHT;
		game->img_list->cropped_minimap = img;
	}
	else
		return ;
}
