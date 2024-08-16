/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:33:51 by plashkar          #+#    #+#             */
/*   Updated: 2023/04/17 16:55:46 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

/*#include <stdio.h>
int main (void)
{
    char input;
    printf ("Enter letter: ");
    scanf("%c", &input);
    printf ("%c", ft_toupper(input));
    printf ("\n");
    return (0);
}*/
