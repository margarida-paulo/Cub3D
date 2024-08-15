/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove_string_from_array.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:32:06 by mvalerio          #+#    #+#             */
/*   Updated: 2024/05/01 19:01:38 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_array(char ***array, size_t index)
{
	size_t	i;

	i = 0;
	while (i < ft_arrlen(*array))
	{
		if (i != index)
			free((*array)[i]);
		i++;
	}
	free (*array);
}

void	ft_remove_string_from_array(char ***array, size_t index)
{
	size_t	i;
	char	**new_array;

	if (index >= ft_arrlen(*array))
		return ;
	new_array = malloc(sizeof(char *) * (ft_arrlen(*array)));
	if (!new_array)
		return ;
	i = 0;
	while (i < ft_arrlen(*array) - 1)
	{
		if (i == index)
			free((*array)[i]);
		if (i >= index)
			(new_array)[i] = ft_strdup((*array)[i + 1]);
		else
			(new_array)[i] = ft_strdup((*array)[i]);
		i++;
	}
	if (i == index)
		free((*array)[i]);
	new_array[i] = NULL;
	free_array(array, index);
	*array = new_array;
}
/*
int main(){
	char **array = malloc(sizeof(char*) * 4);
	array[0] = ft_strdup("Hello");
	array[1] = ft_strdup("World");
	array[2] = ft_strdup("!");
	array[3] = NULL;
	ft_remove_string_from_array(&array, 1);
	for (size_t i = 0; i < ft_arrlen(array); i++)
		ft_printf("%s\n", array[i]);
}
*/
