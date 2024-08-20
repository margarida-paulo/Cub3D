/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:27:33 by mvalerio          #+#    #+#             */
/*   Updated: 2024/08/20 17:08:52 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	print_error_0(int error, char *str)
{

	if (error == INVALID_ARG_CNT)
	{
		ft_putstr_fd("\033[0;31mError:\nInavlid number of arguments!\n", 2);
		ft_putstr_fd("\033[0mUsage: ./cub3D <./path_to_map>\n", 2);
		exit(error);
	}
	else if (error == INVALID_EXTENTION)
	{
		ft_putstr_fd("\033[0;31mError:\nInavlid file extention: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\n\033[0mThe map file should end in .cub\n", 2);
		exit(error);
	}
	else if (error == CAN_NOT_OPEN)
	{
		ft_putstr_fd("\033[0;31mError:\nCan not open the file: ", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\033[0m\n", 2);
		exit(error);
	}
	return (error);
}

int	print_error_1(int error, t_map* map)
{
	free_map_struct(map);
	if (error == MISSING_ELEMENTS)
	{
		ft_putstr_fd("\033[0;31mError:\nMissing element in the .cub", 2);
		ft_putstr_fd(" file\n\033[0m", 2);
		exit(error);
	}
	if (error == MAP_TOO_SMALL)
	{
		ft_putstr_fd("\033[0;31mError:\nMap is too small.", 2);
		ft_putstr_fd(" It has to be at least a 3x3 grid\n\033[0m", 2);
		exit(error);
	}
	if (error == INVALID_CHARS)
	{
		ft_putstr_fd("\033[0;31mError:\nMap contains invalid characters", 2);
		ft_putstr_fd("\n\033[0m\nValid character: [0, 1, N, S, W, E]", 2);
		exit(error);
	}
	if (error == INVALID_P_CNT)
	{
		ft_putstr_fd("\033[0;31mError:\nInvalid player location\n\033[0m", 2);
		exit(error);
	}
	return (error);
}

int	print_error_2(int error, t_map* map)
{
	free_map_struct(map);
	if (error == MISSING_ELEMENTS)
	{
		ft_putstr_fd("\033[0;31mError:\nMissing element in the .cub", 2);
		ft_putstr_fd(" file\n\033[0m", 2);
		exit(error);
	}
	return(error);
}



