/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks_0.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:28:54 by plashkar          #+#    #+#             */
/*   Updated: 2024/09/24 14:44:05 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * @brief Checks if the map has any invalid characters.
 *
 * used in check_map_requirements() function.
 *
 * @param map The map struct.
 * @return 1 if the map has invalid characters, 0 otherwise.
 */
int	check_map_invalid_chars(t_map *map)
{
	int	check;
	int	i;
	int	j;

	check = 0;
	i = 0;
	while (map->map_array[i])
	{
		j = 0;
		while (map->map_array[i][j])
		{
			if (!ft_strchr(VALID_CHARS, map->map_array[i][j]))
			{
				check = 1;
				break ;
			}
			j++;
		}
		if (check == 1)
			break ;
		i++;
	}
	return (check);
}

/**
 * @brief Checks if the map has only one player.
 *
 * if the map has only one player, it will set the player's orientation array.
 * used in check_map_requirements() function.
 *
 * @param map The map struct.
 * @return 1 if the map has more than one player, 0 otherwise.
 */
int	check_map_player_cnt(t_map *map)
{
	int	p_cnt;
	int	i;
	int	j;

	p_cnt = 0;
	i = 0;
	while (map->map_array[i])
	{
		j = 0;
		while (map->map_array[i][j])
		{
			if (ft_strchr("NSWE", map->map_array[i][j]))
				p_cnt++;
			j++;
		}
		i++;
	}
	if (p_cnt == 1)
		return (set_p_orient_arr(map));
	else
		return (1);
}

/**
 * @brief Checks the cells of 1 row of map via the flood fill algorithm.
 *
 * used in check_map_borders() function. and is called once for each row.
 *
 * @param map The map struct.
 * @param visited The 2d array to keep track of visited coordinates.
 * @param i The index of the row.
 * @return 1 if the cells of the row are valid, 0 otherwise.
 */
int	check_cells(t_map *map, int **visited, int i)
{
	int	j;
	int	res;

	res = 1;
	j = 0;
	while (j < map->game->width)
	{
		if (map->map_array[i][j] == '0' || map->map_array[i][j] == ' ')
		{
			res = flood_fill(map, visited, i, j);
			if (res == 0)
				return (0);
		}
		j++;
	}
	return (res);
}

/**
 * @brief Checks if the map has invalid borders.
 *
 * used in check_map_requirements() function.
 * 
 * @param map The map struct.
 * @return 1 if the map has invalid borders, 0 otherwise.
 */
int	check_map_borders(t_map *map)
{
	int	**visited;
	int	i;
	int	res;

	res = 1;
	visited = init_visited_arr(map);
	i = 0;
	while (i < map->game->height)
	{
		res = check_cells(map, visited, i);
		if (res == 0)
		{
			free_visited(visited, map);
			return (0);
		}
		i++;
	}
	free_visited(visited, map);
	return (res);
}
