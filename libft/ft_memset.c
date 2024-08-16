/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:23:19 by plashkar          #+#    #+#             */
/*   Updated: 2023/10/03 17:02:50 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*memset - fill memory with a constant byte*/
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = s;
	i = 0;
	while (i < n)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/*#include <stdio.h>

int main (void)
{
	char str[] = "This is probabaly gonna be censored";
	printf ("the original string is: %s", str);
	printf ("\n");
	ft_memset(str + 27, 161, 8);
	printf ("the new string is %s\n", str);
	return (0);
}*/
