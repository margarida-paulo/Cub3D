/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:45:00 by mvalerio          #+#    #+#             */
/*   Updated: 2023/04/19 11:19:56 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	a;

	i = 0;
	if ((unsigned char)little[i] == '\0')
		return ((char *)big);
	while (i < len && (unsigned char)big[i] != '\0')
	{
		a = 0;
		while ((unsigned char)little[a] == (unsigned char)big[i + a] && \
			(i + a) < len && (unsigned char)little[a] != '\0')
			a++;
		if ((unsigned char)little[a] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
