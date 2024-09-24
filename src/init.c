/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 17:22:55 by mvalerio          #+#    #+#             */
/*   Updated: 2024/09/24 11:31:32 by plashkar         ###   ########.fr       */
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
	t_data *img;

	img = malloc(sizeof(t_data));
	img->img = mlx_new_image(game->mlx, width, height);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), &(img->line_length), &(img->endian));
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


void	minilibx_init(t_game *game)
{
	game->fov = FOV;
	game->state = STATE_MENU;
	game->height = ft_arrlen(game->map.map_array) * GRID_SIZE;
	game->width = ft_strlen(game->map.map_array[0]) * GRID_SIZE;
	game->mlx = mlx_init();
	game->game_window = mlx_new_window(game->mlx, WIN_WIDTH, WIN_HEIGHT, "IKEA simulator");
	game->img_list = malloc(sizeof(t_pics));
	game->img_list->cropped_minimap = NULL;
	game->img_list->minimap = NULL;
	game->img_list->player = NULL;
	game->img_list->cropped_minimap = init_img(game, MINIMAP_WIDTH, MINIMAP_HEIGHT);
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
	game->current_screen = ft_merge_images(game, game->img_list->minimap, game->img_list->player, game->origin);
	ft_init_cropped_minimap(game);
	game->head_bob_offset = 0;
	game->head_bob_phase = 0;
}


void	ft_init_cropped_minimap(t_game *game)
{
	t_data *img;
	if (game->img_list->cropped_minimap == NULL)
	{
		img = malloc(sizeof(t_data));
		img->img = mlx_new_image(game->mlx, MINIMAP_WIDTH, MINIMAP_HEIGHT);
		img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel),\
		 &(img->line_length), &(img->endian));
		img->width = MINIMAP_WIDTH;
		img->height = MINIMAP_HEIGHT;
		game->img_list->cropped_minimap = img;
	}
	else
		return;
}

void	load_wall_textures(t_game* game)
{
	game->img_list->wall[NO] = load_texture(game->mlx, game->map.no_texture);
	game->img_list->wall[SO] = load_texture(game->mlx, game->map.so_texture);
	game->img_list->wall[WE] = load_texture(game->mlx, game->map.we_texture);
	game->img_list->wall[EA] = load_texture(game->mlx, game->map.ea_texture);
}

t_data *load_texture(void *mlx, char *path)
{
	t_data *texture = malloc(sizeof(t_data));

	ft_printf("%s", path);
	int fd = open(path, O_RDONLY);
    if (fd == -1)
    {
        ft_printf("Error: Cannot open file %s\n", path);
        exit(EXIT_FAILURE);
    }
    close(fd);

	if (!texture)
	{
		ft_printf("Error: Failed to allocate memory for texture\n");
		exit(EXIT_FAILURE);
    }
	texture->img = mlx_xpm_file_to_image(mlx, path, &texture->width, &texture->height);
	if (!texture->img)
	{
		ft_printf("Error: Failed to load texture from %s\n", path);
		free(texture);
		exit(EXIT_FAILURE);
	}
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel, &texture->line_length, &texture->endian);
	return texture;
}


