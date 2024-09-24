//utils.c/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 20:35:47 by plashkar          #+#    #+#             */
/*   Updated: 2024/08/21 17:05:55 by plashkar         ###   ########.fr       */
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
	char	**dest_arr;
	size_t	len;
	int		j;
	size_t	arr_len;

	j = 0;
	arr_len = ft_arrlen(src_arr);
	printf("arr_len = %lu\n", arr_len);
	dest_arr = malloc (sizeof(char *) * ((ft_arrlen(src_arr) - i + 1)));
	while (src_arr[i])
	{
		len = ft_strlen(src_arr[i]);
		if (len > 0 && src_arr[i][len - 1] == '\n')
			len--;
		if (len > 0)
			dest_arr[j] = ft_substr(src_arr[i], 0, len);
		else if (len == 0)
			dest_arr[j] = ft_strdup("");
		j++;
		i++;
	}
	dest_arr[j] = NULL;
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

int	ft_cntchr(char* str, char c)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			cnt++;
		i++;
	}
	return (cnt);
}

int	is_numeric(char* str)
{
	int	i;

	i = 0;
	while(str && str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}


