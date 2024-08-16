/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:42:23 by plashkar          #+#    #+#             */
/*   Updated: 2023/04/21 18:53:11 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_digitcnt(int a);
char	*ft_strdup(const char *s);

char	*ft_itoa(int a)
{
	char	*str;
	int		i;
	long	b;

	b = a;
	str = malloc(sizeof(char) * (ft_digitcnt(b) + 1));
	if (!str)
		return (NULL);
	i = ft_digitcnt(b);
	str[i] = '\0';
	if (b < 0)
	{
		str[0] = '-';
		b = b * -1;
	}
	if (b == 0)
		str[0] = '0';
	while (b > 0)
	{
		str[i-- - 1] = b % 10 + '0';
		b = b / 10;
	}
	return (str);
}

int	ft_digitcnt(int a)
{
	int		i;
	long	b;
	int		sign;

	sign = 0;
	b = a;
	i = 0;
	if (b < 0)
		sign = 1;
	if (b < 0)
		b = b * -1;
	if (b == 0)
		return (1);
	while (b > 0)
	{
		b = b / 10;
		i++;
	}
	return (i + sign);
}

/*int main (void)
{
	int		num;
	char	*strnum;
	printf("what is your number?\n");
	scanf("%d", &num);
	strnum = ft_itoa(num);
	printf("The string is: %s\n", strnum);
	return (0);
}*/
