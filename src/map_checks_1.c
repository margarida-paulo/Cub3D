/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 00:10:15 by plashkar          #+#    #+#             */
/*   Updated: 2024/09/23 00:10:42 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * Checks if the given coordinates are within the bounds of the map.
 * used in the flood_fill algo.
 * @param x The x coordinate.
 * @param y The y coordinate.
 * @param map The map struct.
 * @return 1 if the coordinates are within the bounds, 0 otherwise.
 */
int	is_within_bounds(int x, int y, t_map *map)
{
	if (x < 0 || y < 0 || x >= map->game->height || y >= map->game->width)
		return (0);
	return (1);
}

/**
 * The flood fill algorithm to check if the map has invalid borders.
 * First it checks if the coordinates are within the bounds of the map.
 * Then it checks if the coordinates are visited or if the coordinates are walls.
 * If the coordinates are on the borders or are empty spaces, it will return 1.
 * If the coordinates are valid, it will mark them as visited
 * and call itself recursively.
 * @param map The map struct.
 * @param visited The 2d array to keep track of visited coordinates.
 * @param x The x coordinate.
 * @param y The y coordinate.
 * @return 0 if the map has invalid borders, 1 otherwise.
 */
int	flood_fill(t_map *map, int **visited, int x, int y)
{
	if (!is_within_bounds(x, y, map))
		return (0);
	if (visited[x][y] == 1 || map->map_array[x][y] == '1')
		return (1);
	visited[x][y] = 1;
	if (map->map_array[x][y] == ' ')
	{
		return (1);
	}
	else if (map->map_array[x][y] == '0')
	{
		if ((is_within_bounds(x + 1, y, map) && map->map_array[x + 1][y] == ' ') ||
			(is_within_bounds(x - 1, y, map) && map->map_array[x - 1][y] == ' ') ||
			(is_within_bounds(x, y + 1, map) && map->map_array[x][y + 1] == ' ') ||
			(is_within_bounds(x, y - 1, map) && map->map_array[x][y - 1] == ' '))
			return (0);
	}
	return (flood_fill(map, visited, x + 1, y) &&
			flood_fill(map, visited, x - 1, y) &&
			flood_fill(map, visited, x, y + 1) &&
			flood_fill(map, visited, x, y - 1));
}
