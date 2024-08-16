/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:36:54 by plashkar          #+#    #+#             */
/*   Updated: 2023/04/19 15:17:13 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1i;
	const unsigned char	*s2i;
	size_t				i;

	i = 0;
	s1i = s1;
	s2i = s2;
	if (n == 0)
		return (0);
	while (i < n && s1i[i] == s2i[i])
		i++;
	if (i == n)
		return (0);
	return ((unsigned char)s1i[i] - (unsigned char)s2i[i]);
}

/*#include <stdio.h>
#include <string.h>

int main (void)
{
	char *s1 = "How could a 5-ounce bird possibly carry a 1-pound coconut?";
	char *s2 = "it could be carried by an african swallow";
	printf("OG ft: %d\n", memcmp(s1, s2, 0));
	printf("My ft: %d\n", ft_memcmp(s1, s2, 0));
	return (0);
}*/
