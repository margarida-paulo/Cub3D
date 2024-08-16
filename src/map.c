/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 16:36:18 by plashkar          #+#    #+#             */
/*   Updated: 2024/08/15 20:13:01 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		is_valid_extension(char *map_file_name)
{
	int	name_len;

	name_len = ft_strlen(map_file_name);
	if (name_len < 5 || ft_strcmp(&map_file_name[name_len - 4], ".cub"))
		return (0);
	return (1);

}

char*	get_map_str(char **argv)
{
	int		map_fd;
	char*	buffer;
	char*	temp;
	char*	map_as_str;

	buffer = NULL;
	map_as_str = "";
	if (is_valid_extension(argv[1]) == 0)
		print_error(INVALID_EXTENTION, argv[1]);
	map_fd = open(argv[1], O_RDONLY);
	if (map_fd < 0)
		print_error(CAN_NOT_OPEN, argv[1]);
	while((buffer = get_next_line(map_fd)) != NULL)
	{
		temp = map_as_str;
		map_as_str = ft_strjoin(map_as_str, buffer);
		free(temp);
		free(buffer);
	}
	close(map_fd);
	return (map_as_str);
}
