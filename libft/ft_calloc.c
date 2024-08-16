/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:20:39 by plashkar          #+#    #+#             */
/*   Updated: 2023/04/20 14:19:27 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t mbmb, size_t size)
{
	void	*a;

	a = malloc(mbmb * size);
	if (!a)
		return (NULL);
	if (a)
		ft_bzero(a, mbmb * size);
	return (a);
}

/*#include <stdlib.h>
#include <stdio.h>

int main (void)
{//	if (mbmb == 0 || size == 0)
//		return (NULL); why did we not need this safty measure?
	int *a = calloc(10, sizeof(int));
	for (int i = 0; i < 10; i++)
		a[i] = 10 - i;
	for (int i = 0; i < 10; i++)
		printf("a[%d] : %d\n", i, a[i]);
	printf("\n");
	printf("a : %p\n", a);
	printf("Allocated size: %lu\n", sizeof(*a));

	free (a);
}*/
