/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:20:34 by plashkar          #+#    #+#             */
/*   Updated: 2023/04/17 18:08:40 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*The  memmove()  function  copies  n bytes from memory area src to memory
area dest. The memory areas can overlap.
because it checks and arranges the order correctly */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*desti;
	const unsigned char	*srci;
	size_t				i;

	desti = dest;
	srci = src;
	if (dest == src)
		return (dest);
	else if (desti < srci)
	{
		i = 0;
		while (i++ < n)
		{
			desti[i - 1] = srci[i - 1];
		}
	}
	else if (desti > srci)
	{
		i = n;
		while (i-- > 0)
		{
			desti[i] = srci[i];
		}
	}
	return (dest);
}

/*#include <stdio.h>
#include <string.h>
int main (void)
{
	const char src[50] = "We are knights who say Ni!";
	char dest[50] = "Who are ye noble knights?";
	printf("The original: %s\n", dest);
	ft_memmove(dest, src, strlen(src +1));
	printf ("repsonse: %s\n", dest);
	return (0);
}*/
