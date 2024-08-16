/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 20:35:47 by plashkar          #+#    #+#             */
/*   Updated: 2024/08/16 20:44:05 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

/**
 * Copies an array of strings starting from a given index.
 * @param src_arr The source array of strings.
 * @param i The starting index from which to copy.
 * @return A new array of strings starting from the given index.
 */
char	**copy_array_from_index(char **src_arr, int i)
{
	char **dest_arr;
	int	j;

	j = 0;
	dest_arr = malloc (sizeof(char *) * ((ft_arrlen(src_arr) - i + 1)));
	while (src_arr[i])
	{
		dest_arr[j] = ft_strdup(src_arr[i]);
		j++;
		i++;
	}
	return (dest_arr);
}

/**
 * Trims leading spaces and tabs from a given string.
 * @param str The input string to be trimmed.
 * @return A pointer to the first non-space and non-tab character in the string.
 */
char *trim_leading_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (&str[i]);
}

/**
 * Frees a 2d array. used to free an array of strings.
 * @param src The array of strings to be freed.
 * @return void
*/
void	free_2d_array(char **src)
{
	int	i;

	i = 0;
	while (src && src[i])
	{
		free(src[i]);
		i++;
	}
	free(src);
}
