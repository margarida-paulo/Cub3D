/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:28:54 by plashkar          #+#    #+#             */
/*   Updated: 2024/08/28 16:04:42 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * Checks if the map has any invalid characters.
 * used in check_map_requirements() function.
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
	while(map->map_array[i])
	{
		j = 0;
		while(map->map_array[i][j])
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
 * Checks if the map has only one player.
 * if the map has only one player, it will set the player's orientation array.
 * used in check_map_requirements() function.
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
	while(map->map_array[i])
	{
		j = 0;
		while(map->map_array[i][j])
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
		if (x == 0 || x == map->game->height - 1 || y == 0 || y == map->game->width - 1)
			return (0);
	}
	else if (map->map_array[x][y] == '0')
	{
		if ((is_within_bounds(x + 1, y, map) && map->map_array[x + 1][y] == ' ') ||
			(is_within_bounds(x - 1, y, map) && map->map_array[x - 1][y] == ' ') ||
			(is_within_bounds(x, y + 1, map) && map->map_array[x][y + 1] == ' ') ||
			(is_within_bounds(x, y - 1, map) && map->map_array[x][y - 1] == ' '))
			return (0);
	}
	else
		return (1);
	return (flood_fill(map, visited, x + 1, y) &&
			flood_fill(map, visited, x - 1, y) &&
			flood_fill(map, visited, x, y + 1) &&
			flood_fill(map, visited, x, y - 1));
}

/**
 * Checks the cells of 1 row of map via the flood fill algorithm.
 * used in check_map_borders() function. and is called once for each row.
 * @param map The map struct.
 * @param visited The 2d array to keep track of visited coordinates.
 * @param i The index of the row.
 */
int	check_cells(t_map *map, int **visited, int i)
{
	int	j;
	int	res;

	res = 1;
	j = 0;
	while (j < map->game->width)
	{
		if (map->map_array[i][j] == '0' ||  map->map_array[i][j] == ' ')
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
 * Checks if the map has invalid borders.
 * used in check_map_requirements() function.
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

