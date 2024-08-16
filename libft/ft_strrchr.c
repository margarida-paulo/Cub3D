/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 20:36:03 by plashkar          #+#    #+#             */
/*   Updated: 2023/04/18 21:42:38 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	c1;
	size_t			len;

	len = ft_strlen(s);
	c1 = c;
	while (len > 0)
	{
		if (s[len - 1] == c1)
			return ((char *)(s + len - 1));
		len--;
	}
	if (c1 == '\0')
		return ((char *)&s[ft_strlen(s)]);
	return (NULL);
}

/*int main (void)
{
	char *res;
	char *res2;
	char str[] = "if you gaze into the abyss, the abyss gazes also into you.";
	res = ft_strrchr(str, '\0');
	res2 = strrchr(str, '\0');
	printf ("My ft: %s\n", res);
	printf ("OG ft: %s\n", res2);
	return(0);
}*/
