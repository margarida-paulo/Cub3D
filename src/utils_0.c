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
 * @brief Finds the maximum length of a string in a given array of strings.
 *
 * @param arr The array of strings to search in.
 * @return The maximum length of a string in the array.
 */
size_t	get_max_len_in_array(char **arr)
{
	int	i;
	size_t max_len;

	i = 0;
	max_len = 0;
	while (arr[i])
	{
		if (ft_strlen(arr[i]) > max_len)
			max_len = ft_strlen(arr[i]);
		i++;
	}
	return (max_len);
}

/**
 * @brief Creates a new string with the same contents as the given string,
 * but with length max_len by padding it with spaces.
 *
 * @param str The string to pad.
 * @param max_len The desired length of the new string.
 * @return A newly allocated string with the same contents as str, but with
 * length max_len.
 */
char *pad_string(char *str, size_t max_len)
{
	char	*new_str;
	size_t	i;
	size_t	len;

	len = ft_strlen(str);
	new_str = malloc(sizeof(char) * (max_len + 1));
	if (!new_str)
		return NULL; // Handle malloc failure
	i = 0;
	while (i < len)
	{
		new_str[i] = str[i];
		i++;
	}
	while (i < max_len)
	{
		new_str[i] = ' ';
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

/**
 * @brief Normalizes an array of strings by padding each string with spaces
 * to the maximum length in the array.
 *
 * @param arr The array of strings to normalize.
 * @return A new array of strings with the same contents as arr, but with
 * each string padded to the maximum length in the array.
 */
char** normalize_array(char **arr)
{
	int		i;
	size_t	max_len;
	char	**new_arr;

	i = 0;
	max_len = get_max_len_in_array(arr);
	new_arr = malloc (sizeof(char *) * (ft_arrlen(arr) + 1));
	while (arr[i])
	{
		new_arr[i] = pad_string(arr[i], max_len);
		i++;
	}
	new_arr[i] = NULL;
	free_2d_array(arr);
	return (new_arr);

}

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
	dest_arr = normalize_array(dest_arr);
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


