/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:36:18 by plashkar          #+#    #+#             */
/*   Updated: 2024/08/20 17:02:59 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_valid_extension(char *map_file_name)
{
	int	name_len;

	name_len = ft_strlen(map_file_name);
	if (name_len < 5 || ft_strcmp(&map_file_name[name_len - 4], ".cub"))
		return (0);
	return (1);

}

int	cub_file_cnt_lines(char **argv)
{
	int		map_fd;
	int		line_cnt;
	char*	buffer;

	line_cnt = 0;
	map_fd = open(argv[1], O_RDONLY);
	if (map_fd < 0)
		print_error_0(CAN_NOT_OPEN, argv[1]);
	while((buffer = get_next_line(map_fd)) != NULL)
	{
		line_cnt++;
		free(buffer);
	}
	close(map_fd);
	return (line_cnt);
}

char**	get_cub_file_arr(char **argv)
{
	char**	cub_file_arr;
	char*	buffer;
	int		cub_fd;
	int		i;

	if (is_valid_extension(argv[1]) == 0)
		print_error_0(INVALID_EXTENTION, argv[1]);
	cub_file_arr = malloc(sizeof(char *) * (cub_file_cnt_lines(argv) + 1));
	if (!cub_file_arr)
		return (NULL);
	cub_fd = open(argv[1], O_RDONLY);
	if (cub_fd < 0)
		print_error_0(CAN_NOT_OPEN, argv[1]);
	i = 0;
	while((buffer = get_next_line(cub_fd)))
	{
		cub_file_arr[i] = buffer;
		i++;
	}
	cub_file_arr[i] = NULL;
	close(cub_fd);
	return(cub_file_arr);
}



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
			// map->map_array = &cub_file_arr[i];
			map->map_array = copy_array_from_index(cub_file_arr, i);
			map_start_found = 1;
		}
		else if (!map_start_found)
			parse_elements(map, line);
		i++;
	}
	free_2d_array(cub_file_arr);
	check_map_requirements(map);
}

void	parse_elements(t_map *map, char *line)
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

void	free_map_struct(t_map *map)
{
	free_2d_array(map->map_array);
	free(map->no_texture);
	free(map->so_texture);
	free(map->we_texture);
	free(map->ea_texture);
	free(map->f_color);
	free(map->c_color);
}

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

void	set_p_orient_angle(t_map *map, char c)
{
	if (c == 'E')
		map->game->p_orient[2] = 0;
	else if (c == 'N')
		map->game->p_orient[2] = M_PI / 2;
	else if (c == 'W')
		map->game->p_orient[2] = M_PI;
	else if (c == 'S')
		map->game->p_orient[2] = 3 * M_PI / 2;
}

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

// int	check_map_newlines(t_map *map)
// {
// 	int	check;
// 	int	i;

// 	check = 0;
// 	i = 0;
// 	while (map->map_array[i])
// 	{
// 		if (map->map_array[i][0] == '\n')
// 		{
// 			check = 1;
// 			break ;
// 		}
// 		i++;
// 	}
// 	return (check);
// }



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
}
