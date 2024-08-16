/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:55:23 by plashkar          #+#    #+#             */
/*   Updated: 2023/04/17 16:42:48 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

/*#include <stdio.h>
int main (void)
{
    int input;
    printf ("Enter your digit: ");
    scanf("%d", &input);
    if (ft_isascii(input))
    printf ("Yep\n");
    else
    printf ("Nope\n");
    return (0);
}*/
