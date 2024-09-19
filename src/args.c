/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 17:07:59 by plashkar          #+#    #+#             */
/*   Updated: 2024/09/20 00:01:52 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * Checks if the file has a valid .cub extension.
 * @param map_file_name The name of the file.
 * @return 1 if the file has a valid extension, 0 otherwise.
 */
int	is_valid_extension(char *map_file_name)
{
	int	name_len;

	name_len = ft_strlen(map_file_name);
	if (name_len < 5 || ft_strcmp(&map_file_name[name_len - 4], ".cub"))
		return (0);
	return (1);

}

/**
 * Counts the number of lines in the .cub file.
 * It will try to open the file and read it line by line.
 * If it fails to open the file, it will print an error message and exit.
 * @param argv The arguments passed to the program.
 * @return The number of lines in the .cub file.
 */
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

/**
 * Reads the .cub file and stores it in an array of strings.
 * It will try to open the file and read it line by line.
 * If it fails to open the file, it will print an error message and exit.
 * @param argv The arguments passed to the program.
 * @return char **cub_file_arr; An array of strings containing the .cub file.
 */
char**	get_cub_file_arr(char **argv)
{
	char**	cub_file_arr;
	char*	buffer;
	int		cub_fd;
	int		i;

	if (is_valid_extension(argv[1]) == 0)
		print_error_0(INVALID_EXTENTION, argv[1]);
	cub_file_arr = malloc(sizeof(char *) * (cub_file_cnt_lines(argv) + 1));
	// cub_file_arr = ft_calloc(cub_file_cnt_lines(argv) + 1, sizeof(char*));
	if (!cub_file_arr)
		return (NULL);
	cub_fd = open(argv[1], O_RDONLY);
	if (cub_fd < 0)
		print_error_0(CAN_NOT_OPEN, argv[1]);
	i = 0;
	buffer = get_next_line(cub_fd);
	while((buffer))
	{
		cub_file_arr[i] = buffer;
		i++;
		buffer = get_next_line(cub_fd);
	}
	cub_file_arr[i] = NULL;
	close(cub_fd);
	return(cub_file_arr);
}
