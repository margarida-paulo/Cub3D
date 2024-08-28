/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:13:55 by plashkar          #+#    #+#             */
/*   Updated: 2024/08/28 15:33:01 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * Sets the elements of the map struct based on the line read from the cub file.
 * used in parse_map() function.
 * @param map The map struct.
 * @param line The line read from the cub file.
 * @return void
 */
void	set_elements(t_map *map, char *line)
{
	line = trim_leading_spaces(line);
	if (ft_strncmp(line, "NO", 2) == 0)
		map->no_texture = ft_strdup(trim_leading_spaces(line + 2));
	else if (ft_strncmp(line, "SO", 2) == 0)
		map->so_texture = ft_strdup(trim_leading_spaces(line + 2));
	else if (ft_strncmp(line, "WE", 2) == 0)
		map->we_texture = ft_strdup(trim_leading_spaces(line + 2));
	else if (ft_strncmp(line, "EA", 2) == 0)
		map->ea_texture = ft_strdup(trim_leading_spaces(line + 2));
	else if (ft_strncmp(line, "F", 1) == 0)
		map->f_color = ft_strdup(trim_leading_spaces(line + 2));
	else if (ft_strncmp(line, "C", 1) == 0)
		map->c_color = ft_strdup(trim_leading_spaces(line + 2));
}

/**
 * Sets the player's orientation angle based on the character found in the map.
 * used in set_p_orient_arr() function.
 * @param map The map struct.
 * @param c The character found in the map.
 * @return void
 */
void	set_p_orient_angle(t_map *map, char c)
{
	if (c == 'E')
		map->game->p_orient[2] = 0;
	else if (c == 'N')
		map->game->p_orient[2] = 3 * (M_PI / 2);
	else if (c == 'W')
		map->game->p_orient[2] = M_PI;
	else if (c == 'S')
		map->game->p_orient[2] = M_PI / 2;
}

/**
 * Sets the player's orientation array based on the character found in the map.
 * this fucntion will only run if there is only one player in the map.
 * that check is done in check_map_player_cnt() function.
 * used in check_map_player_cnt() function.
 * @param map The map struct.
 * @return 0 to indicate success of the check_map_player_cnt() function.
 */
int	set_p_orient_arr(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while(map->map_array[i])
	{
		j = 0;
		while(map->map_array[i][j])
		{
			if (ft_strchr("NSWE", map->map_array[i][j]))
			{
				map->game->p_orient[0] = i;
				map->game->p_orient[1] = j;
				set_p_orient_angle(map, map->map_array[i][j]);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (0);
}

/**
 * Sets the width and height of the map in the game struct.
 * used in check_map_requirements() function.
 * @param map The map struct.
 * @return void
 */
void	set_width_and_height(t_map *map)
{
	int	max_width;
	int	i;

	max_width = 0;
	i = 0;
	while (map->map_array[i])
	{
		if ((int)ft_strlen(map->map_array[i]) > max_width)
			max_width = ft_strlen(map->map_array[i]);
		i++;
	}
	map->game->width = max_width;
	map->game->height = ft_arrlen(map->map_array);
}
