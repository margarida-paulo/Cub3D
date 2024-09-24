/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:24:13 by plashkar          #+#    #+#             */
/*   Updated: 2024/09/24 14:25:25 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	load_wall_textures(t_game *game)
{
	game->img_list->wall[NO] = load_texture(game, game->map.no_texture);
	game->img_list->wall[SO] = load_texture(game, game->map.so_texture);
	game->img_list->wall[WE] = load_texture(game, game->map.we_texture);
	game->img_list->wall[EA] = load_texture(game, game->map.ea_texture);
}

t_data	*load_texture(t_game *game, char *path)
{
	t_data	*texture;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		print_error_2(CAN_NOT_OPEN_TEXTURE, &game->map);
	close(fd);
	texture = malloc(sizeof(t_data));
	if (!texture)
		print_error_2(CAN_NOT_MALLOC_TEXTURE, &game->map);
	texture->img = mlx_xpm_file_to_image(game->mlx, path, &texture->width, \
	&texture->height);
	if (!texture->img)
		print_error_3(MLX_XPM_TO_IMG_FAIL, &game->map);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel, \
	&texture->line_length, &texture->endian);
	return (texture);
}
