/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:27:23 by plashkar          #+#    #+#             */
/*   Updated: 2023/04/18 20:34:33 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	if (i == n)
		return (0);
	else
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*#include <string.h>
#include <stdio.h>

int	main(void)
{
	char *s1 = "Guard: You're using Coconuts!";
	char *s2 = "Guard: You're using coconuts! Arthur: What?";
	printf("My ft: The difference is: %d\n", ft_strncmp(s1, s2, 10));
	printf("OG ft: The difference is: %d\n", strncmp(s1, s2, 5));
	return (0);
}*/
