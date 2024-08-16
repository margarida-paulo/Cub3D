/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:13:05 by plashkar          #+#    #+#             */
/*   Updated: 2023/04/18 17:24:23 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	dstlen;
	size_t	i;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	i = 0;
	if (size <= dstlen)
		return (size + srclen);
	while (src[i] && dstlen + i < size - 1)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}
/*
int main(void)
{
	char src[] = "Heroiam slava!";
	char dest[60] = "Slava Ukraini! ";
	printf("The original dest is: %s\n", dest);
	size_t sizeofall = ft_strlcat(dest, src, 10);
	printf ("The result is: %s\n", dest);
	printf ("the total length of the string that would be created if
	there was unlimted space is: %ld\n", sizeofall);
	return (0);
}*/
