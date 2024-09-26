/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_extra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 11:31:16 by mvalerio          #+#    #+#             */
/*   Updated: 2024/09/26 11:14:59 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	mlx_px(t_data *img, int x, int y, int color)
{
	char	*pixel_pos;

	pixel_pos = img->addr + (y * img->line_length + x \
	* (img->bits_per_pixel / 8));
	*(unsigned int *)pixel_pos = color;
}
