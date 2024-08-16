/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:55:30 by plashkar          #+#    #+#             */
/*   Updated: 2023/04/17 18:13:18 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

/*#include <stdio.h>
int main (void)
{
	char str[] = "This is probabaly gonna be censored";
	printf ("the original string is: %s", str);
	printf ("\n");
	bzero(str + 27, 8);
	printf ("the new string is %s\n", str);
	return (0);
m}*/
