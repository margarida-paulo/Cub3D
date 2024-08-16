/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:28:09 by plashkar          #+#    #+#             */
/*   Updated: 2023/09/07 18:21:18 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}
/*#include <stdio.h>

int main (void)
{
char str[]
= "What if Soy milk is just regular milk introducing itself in Spanish.";
printf ("The size of the string is %ld", ft_strlen(str));
printf ("\n");
return (0);
}*/
