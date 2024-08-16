/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:36:46 by plashkar          #+#    #+#             */
/*   Updated: 2023/04/20 11:44:12 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void*s, int c, size_t n)
{
	unsigned char		c1;
	const unsigned char	*s1;
	size_t				i;

	i = 0;
	c1 = c;
	s1 = s;
	while (i < n)
	{
		if (s1[i] == c1)
			return ((void *)(s1 + i));
		i++;
	}
	return (NULL);
}

/*int main(void)
{
	char *res;
	char *res2;
	char str[] = "King Arthur : The swallow may fly south with the sun
	or the house martin or the plover may seek warmer climes in winter,
	yet these are not strangers to our land?";
	res = ft_memchr(str, 'h', 10);
	res2 = memchr(str, 'h', 10);
	printf ("My ft: %s\n", res);
	pritf ("OG ft: %s\n", res2);
	return(0);
}*/
