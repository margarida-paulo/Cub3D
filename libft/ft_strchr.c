/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:11:35 by plashkar          #+#    #+#             */
/*   Updated: 2023/04/19 16:01:03 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*ft_strchr replicates the behavior of the standard library function strchr
 as it searches for the first occurrence of the character c in the string str
 and returns a pointer to that location in the string.*/

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	c1;

	c1 = c;
	while (*s != '\0')
	{
		if (*s == c1)
			return ((char *)s);
		s++;
	}
	if (c1 == '\0')
		return ((char *)s);
	return (NULL);
}

/*#include <stdio.h>

int main (void)
{/MY OG*why does this not work? char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (c == '\0')
		return((char *)&str[ft_strlen(str)]);
	while (str[i] != '\0' && str[i] !=
	i++;
	if (str[i] == '\0')
		return (NULL);
	else
		return ((char *)&str[i]);
}
int main (void)
	char *res;
	char *res2;
	char str[] = "if you gaze into the abyss, the abyss gazes also into you.";
	res = ft_strchr(str, 'g');
	printf ("My ft: %s\n", res);
	printf ("OG ft: %s\n", res2);
	return(0);
}*/
