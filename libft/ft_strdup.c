/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 15:32:56 by plashkar          #+#    #+#             */
/*   Updated: 2023/04/20 18:15:15 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dup)
		return (NULL);
	while (s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

/*#include <string.h>
#include <stdio.h>
//I forgot to consider the null terminator in my amlloc and also after while loop
//was done! don't forget!!!
int main(void)
{
	char src[] = "There are some who call me ... Tim.";
	char *dest1 = strdup(src);
	char *dest2 = ft_strdup(src);
	printf("OG ft: %s\n", dest1);
	printf("my ft: %s\n", dest2);
	return(0);
}*/
