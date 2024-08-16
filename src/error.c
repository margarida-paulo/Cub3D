/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 14:27:33 by mvalerio          #+#    #+#             */
/*   Updated: 2024/08/16 19:48:05 by plashkar         ###   ########.fr       */
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

int	print_error_1(int error)
{
	if (error == MISSING_ELEMENTS)
	{
		ft_putstr_fd("\033[0;31mError:\nMissing element in the .cub", 2);
		ft_putstr_fd(" file\n\033[0m", 2);
		exit(error);
	}
	return (error);
}



