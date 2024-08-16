/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:05:28 by plashkar          #+#    #+#             */
/*   Updated: 2023/04/17 18:29:11 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] != '\0' && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

/*#include <stdio.h>
int main (void)
{
	char src[] = "I can see it in your eyes";
	char dest[] = "Hello is it me you looking for?";
	printf("The original dest is: %s\n", dest);
	size_t sizesrc = ft_strlcpy(dest, src, 5);
	printf("the total length of the string that would have been copied if
	 there was unlimited space: %ld\n", sizesrc);
	printf("the new dest is: %s\n", dest);
	return (0);
}*/
