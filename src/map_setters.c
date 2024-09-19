/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_setters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:13:55 by plashkar          #+#    #+#             */
/*   Updated: 2024/09/20 00:04:19 by plashkar         ###   ########.fr       */
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
	char*	trimmed_line;
	char*	tmp;
	size_t	len;

	trimmed_line = trim_leading_spaces(line);
	if (ft_strlen(trimmed_line) < 2)
		return ;
	tmp = trim_leading_spaces(trimmed_line + 2);
	len = ft_strlen(tmp) - 1;

	if (ft_strncmp(trimmed_line, "NO", 2) == 0)
		map->no_texture = ft_substr(tmp, 0 , len);
	else if (ft_strncmp(trimmed_line, "SO", 2) == 0)
		map->so_texture = ft_substr(tmp, 0 , len);
	else if (ft_strncmp(trimmed_line, "WE", 2) == 0)
		map->we_texture = ft_substr(tmp, 0 , len);
	else if (ft_strncmp(trimmed_line, "EA", 2) == 0)
		map->ea_texture = ft_substr(tmp, 0 , len);
	else if (ft_strncmp(trimmed_line, "F", 1) == 0)
		map->f_color = ft_substr(tmp, 0 , len);
	else if (ft_strncmp(trimmed_line, "C", 1) == 0)
 		map->c_color = ft_substr(tmp, 0 , len);
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
				map->game->p_orient[0] = j;
				map->game->p_orient[1] = i;
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
