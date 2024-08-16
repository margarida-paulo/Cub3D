/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:42:20 by plashkar          #+#    #+#             */
/*   Updated: 2023/04/17 16:41:37 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
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

    if (ft_isalpha(input))
        printf("%c is an alphabetic character.\n", input);
    else
        printf("%c is not an alphabetic character.\n", input);

    return 0;
}*/
