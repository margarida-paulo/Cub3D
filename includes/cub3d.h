/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:24:08 by mvalerio          #+#    #+#             */
/*   Updated: 2024/08/15 19:56:16 by plashkar         ###   ########.fr       */
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

enum exit_codes {
	INVALID_ARG_CNT = 1,
	INVALID_EXTENTION,
	CAN_NOT_OPEN,
	INVALID_BORDERS,
    // Add other exit codes here
};


typedef struct	s_map
{
	char*	map_as_str;
	char**	map_array;
	double	p_orient[3]; // x y angle
	char*	NO; //./path_to_the_north_texture
	char*	SO; //./path_to_the_south_texture
	char*	WE; //./path_to_the_west_texture
	char*	EA; //./path_to_the_east_texture
	char*	F_color; //∗ Floor color: F 220,100,0
	char*	C_color; //* Ceiling color: C 225,30,0
}	t_map;

typedef struct	s_game
{
	t_map	map;
}	t_game;


int	print_error(int exit_code, char *str);


char*	get_map_str(char **argv);

#endif
