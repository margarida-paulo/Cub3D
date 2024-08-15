/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 13:47:46 by mvalerio          #+#    #+#             */
/*   Updated: 2023/04/20 17:38:22 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_chars(long int a)
{
	size_t	divisors;
	size_t	chars;

	chars = 1;
	if (a < 0)
	{
		chars++;
		a = -a;
	}
	if (a == 0)
		return (1);
	divisors = 10;
	while (a / divisors != 0)
	{
		divisors = divisors * 10;
		chars = chars + 1;
	}
	return (chars);
}

char	*ft_itoa(int n)
{
	char			*string;
	size_t			i;
	unsigned int	number;

	string = (char *) malloc(sizeof(char) * (ft_chars((long int)n) + 1));
	if (!string)
		return (NULL);
	if (n < 0)
		number = -n;
	else
		number = n;
	i = ft_chars(n) - 1;
	string[i + 1] = '\0';
	while (i > 0)
	{
		string[i] = '0' + (number % 10);
		number = number / 10;
		i--;
	}
	if (n < 0)
		string[0] = '-';
	else
		string[0] = '0' + (number % 10);
	return (string);
}
