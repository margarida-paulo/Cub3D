/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:18:47 by plashkar          #+#    #+#             */
/*   Updated: 2023/04/17 18:22:59 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/*#include <stdio.h>
int main()
{
    char input;
    printf("Enter a character: ");
    scanf("%c", &input);

    if (ft_isdigit(input))
        printf("%c is a digit.\n", input);
    else
        printf("%c is not a digit.\n", input);

    return 0;
}*/
