/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:24:08 by mvalerio          #+#    #+#             */
/*   Updated: 2024/08/20 17:08:39 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <math.h>
#include <stdio.h>
#include <fcntl.h>
#include "../mlx_linux/mlx.h"
#include "../libft/libft.h"

//Color codes for ft_printf
# define DEFAULT "\033[0m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"

# define VALID_CHARS "01NSWE \n"

enum exit_codes {
	INVALID_ARG_CNT = 1,
	INVALID_EXTENTION,
	CAN_NOT_OPEN,
	MISSING_ELEMENTS,
	MAP_TOO_SMALL,
	INVALID_CHARS,
	INVALID_P_CNT,
	INVALID_BORDERS,
    // Add other exit codes here
};

typedef struct s_game t_game;

typedef struct	s_map
{
	t_game	*game;
	int		map_start; //the starting index of the map in the .cub file
	char**	map_array;
	char*	no_texture; //./path_to_the_north_texture
	char*	so_texture; //./path_to_the_south_texture
	char*	we_texture; //./path_to_the_west_texture
	char*	ea_texture; //./path_to_the_east_texture
	char*	f_color; //∗ Floor color: F 220,100,0
	char*	c_color; //* Ceiling color: C 225,30,0
}	t_map;

typedef struct	s_game
{
	t_map	map;
	int		height;
	int		width;
	double	p_orient[3]; // x y angle
}	t_game;


int		print_error_0(int exit_code, char *str);
int		print_error_1(int exit_code, t_map *map);
void	free_map_struct(t_map *map);

int		is_valid_extension(char *map_file_name);
int		cub_file_cnt_lines(char **argv);
char	**get_cub_file_arr(char **argv);
void	parse_elements(t_map *map, char *line);
void	parse_map(t_map *map, char **argv);
void	check_map_requirements(t_map *map);

char	*trim_leading_spaces(char *str);
void	free_2d_array(char **src);
char	**copy_array_from_index(char **src_arr, int i);

void	test_print_2D_array(char** arr);
void	test_print_map_struct_data(t_map *map);

#endif
