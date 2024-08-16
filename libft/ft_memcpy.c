/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:32:00 by plashkar          #+#    #+#             */
/*   Updated: 2023/04/17 16:50:27 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*desti;
	const unsigned char	*srci;
	size_t				i;

	desti = dest;
	srci = src;
	i = 0;
	if (dest == src)
	{
		return (dest);
	}
	while (i < n)
	{
		desti[i] = srci[i];
		i++;
	}
	return (dest);
}

/*#include <stdio.h>
#include <string.h>
int main (void)
{
	const char src[50] = "This will be copied";
	char dest[50] = "This will be overwritten";
	printf("The original destiantion string is: %s\n", dest);
	ft_memcpy(dest, src, strlen(src)+1);
	printf("the modified dest is: %s\n", dest);
	return (0);
The  memcpy()  function  copies  n bytes from memory area src to memory
area dest. The memory areas must not overlap. because it doesn't check for that 
It's important to put if both src and dest are pointing to the same address,
if so it should just return and not copy to not currupt data
}
*/
