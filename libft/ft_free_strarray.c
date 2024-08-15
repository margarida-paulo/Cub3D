/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strarray.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 10:25:24 by maggie            #+#    #+#             */
/*   Updated: 2024/05/03 18:23:01 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_strarray(char **array)
{
	size_t	i;

	i = 0;
	while (array && array[i])
	{
		free (array[i]);
		i++;
	}
	free (array);
	return ;
}
