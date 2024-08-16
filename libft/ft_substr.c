/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 16:06:57 by plashkar          #+#    #+#             */
/*   Updated: 2023/05/02 12:43:27 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;

	if (s == NULL)
		return (0);
	if (start >= ft_strlen(s))
	{
		substring = ft_strdup("");
		return (substring);
	}
	i = 0;
	while (s[start + i] != '\0' && i < len)
		i++;
	substring = malloc(sizeof (char) * (i + 1));
	if (!substring)
		return (NULL);
	i = 0;
	while (s[start + i] != '\0' && i < len)
	{
		substring[i] = s[start + i];
		i++;
	}
	substring[i] = '\0';
	return (substring);
}

/*#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int	main(void)
{
	size_t	starting;
	size_t	length;
	//char s[] = "Strange women lying in ponds, distributing swords, is
	no basis for a system of government!";
	char s[] = "Hello my name is Pouya and Im here to say ...";
	printf("What index is the starting point?\n");
	scanf("%ld", &starting);
	printf("What is the length?\n");
	scanf("%ld", &length);
	printf("Your string is: %s\n", ft_substr(s, starting, length));
	return (0);
}*/
