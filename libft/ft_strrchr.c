/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:59:46 by mvalerio          #+#    #+#             */
/*   Updated: 2023/04/17 17:50:35 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	if ((unsigned char)c == '\0')
		return ((char *)&s[i]);
	while (--i >= 0)
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
	}
	return (NULL);
}
