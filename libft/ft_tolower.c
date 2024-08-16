/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:02:16 by plashkar          #+#    #+#             */
/*   Updated: 2023/04/18 17:08:06 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

/*#include <stdio.h>
int main (void)
{
    char input;
    printf ("Enter your letter: ");
    scanf ("%c", &input);
    printf ("%c", ft_tolower(input));
    printf ("\n");
    return (0);
}*/
