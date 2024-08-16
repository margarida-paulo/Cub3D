/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:22:43 by plashkar          #+#    #+#             */
/*   Updated: 2023/04/17 18:12:54 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (1);
	else
		return (0);
}

/*#include <stdio.h>
int main (void)
{
    int input;
    printf ("Enter the ascii value: ");
    scanf ("%d", &input);
    if (ft_isprint(input))
    printf ("That ascii value is a printable character\n");
    else
    printf ("That ascii value is not a printable character\n");
    return (0);
}*/
