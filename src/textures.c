/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 14:24:13 by plashkar          #+#    #+#             */
/*   Updated: 2024/09/28 20:21:25 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	load_all_textures(t_game *game)
{
	game->img_list->wall[NO] = load_texture(game, game->map.no_texture);
	game->img_list->wall[SO] = load_texture(game, game->map.so_texture);
	game->img_list->wall[WE] = load_texture(game, game->map.we_texture);
	game->img_list->wall[EA] = load_texture(game, game->map.ea_texture);
	game->img_list->start_screen = \
	load_texture(game, "./textures/start_img.xpm");
}

t_data	*load_texture(t_game *game, char *path)
{
	t_data	*texture;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		print_error_4(CAN_NOT_OPEN_TEXTURE, &game->map);
	close(fd);
	texture = malloc(sizeof(t_data));
	if (!texture)
		print_error_4(CAN_NOT_OPEN_TEXTURE, &game->map);
	texture->img = mlx_xpm_file_to_image(game->mlx, path, &texture->width, \
	&texture->height);
	if (!texture->img)
		print_error_3(MLX_XPM_TO_IMG_FAIL, &game->map);
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel, \
	&texture->line_length, &texture->endian);
	return (texture);
}

void	ft_set_wall_type(t_ray *ray)
{
	if (ray->inter_type == HORIZONTAL)
	{
		if (ray->multiplier_y > 0)
			ray->wall_type = SO;
		else
			ray->wall_type = NO;
	}
	else
	{
		if (ray->multiplier_x > 0)
			ray->wall_type = EA;
		else
			ray->wall_type = WE;
	}
}
