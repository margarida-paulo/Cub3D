/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:36:18 by plashkar          #+#    #+#             */
/*   Updated: 2024/09/28 15:47:39 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * Parses the map from the cub file and sets the elements of the map struct.
 * starts by reading each line from the cub file and checks if the map starts.
 * if the map starts, it will copy the rest of the lines to the map_array.
 * if the map does not start, it will set the elements of the map struct.
 * after the map is parsed, it will check if the map meets the requirements.
 * @param map The map struct.
 * @param argv The arguments passed to the program.
 * @return void
 */
void	parse_map(t_map *map, char **argv)
{
	char	**cub_file_arr;
	int		i;
	int		map_start_found;
	char	*line;

	i = 0;
	map_start_found = 0;
	cub_file_arr = get_cub_file_arr(argv);
	while (cub_file_arr[i])
	{
		line = trim_leading_spaces(cub_file_arr[i]);
		if (line[0] == '1' && !map_start_found)
		{
			map->map_start = i;
			map->map_array = copy_array_from_index(cub_file_arr, i);
			map_start_found = 1;
		}
		else if (!map_start_found)
			set_elements(map, line);
		i++;
	}
	parse_color(map);
	free_2d_array(cub_file_arr);
	check_map_requirements(map);
}

void	parse_color(t_map *map)
{
	if (map->c_color)
		map->c_color_val = parse_color_str(map->c_color);
	if (map->f_color)
		map->f_color_val = parse_color_str(map->f_color);
}

int	parse_color_str(char *color_str)
{
	char	**split;
	int		colors[3];
	int		index;

	index = 0;
	split = ft_split(color_str, ',');
	while (split && split[index])
		index++;
	if (index != 3 || ft_cntchr(color_str, ',') != 2)
		return (free_2d_array(split), -1);
	index = 0;
	while (split[index])
	{
		if (!is_numeric(split[index]) || ft_strlen(split[index]) > 3)
			return (free_2d_array(split), -1);
		colors[index] = ft_atoi(split[index]);
		if (colors[index] > 255 || colors[index] < 0)
			return (free_2d_array(split), -1);
		index++;
	}
	free_2d_array(split);
	return ((colors[0] << 16) | (colors[1] << 8) | colors[2]);
}

/**
 * Checks if the map meets the requirements.
 * Used in parse_map() function.
 * It will set the width and height of the map.
 * It will check if the map is too small, if it has all the required elements,
 * if it has invalid characters, if it has only one player,
 * and if it has invalid borders.
 * If any of the requirements are not met, prints an error message and exits.
 * @param map The map struct.
 * @return void
 */
void	check_map_requirements(t_map *map)
{
	set_width_and_height(map);
	if (map->game->height <= 2 || map->game->width <= 2)
		print_error_1(MAP_TOO_SMALL, map);
	if (!map->no_texture || !map->so_texture || !map->we_texture || \
	!map->ea_texture || !map->f_color || !map->c_color)
		print_error_1(MISSING_ELEMENTS, map);
	if (check_map_invalid_chars(map))
		print_error_1(INVALID_CHARS, map);
	if (check_map_player_cnt(map))
		print_error_1(INVALID_P_CNT, map);
	if (!check_map_borders(map))
		print_error_2(INVALID_BORDERS, map);
	if (check_map_nl(map))
		print_error_2(NEWLINES_IN_MAP, map);
}

int	check_map_nl(t_map *map)
{
	char	*curr_str;
	int		i;

	i = 0;
	while (i < map->game->height)
	{
		curr_str = trim_leading_spaces(map->map_array[i]);
		if (curr_str[0] == '\n' || curr_str[0] == '\0')
			return (1);
		i++;
	}
	return (0);
}
