/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printed.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maggie <maggie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:03:50 by mvalerio          #+#    #+#             */
/*   Updated: 2023/06/08 21:40:49 by maggie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_printed(int n, int *a)

{
	if (n == -2147483648)
	{
		ft_putchar_fd('-', 1);
		ft_putchar_fd('2', 1);
		(*a) += 2;
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		(*a)++;
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_printed(n / 10, a);
		n = n % 10;
	}
	if (n < 10)
	{
		(*a)++;
		ft_putchar_fd('0' + n, 1);
	}
}

void	ft_putstr_printed(char *s, int *a)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		write (1, "(null)", 6);
		(*a) += 6;
		return ;
	}
	while (s[i])
	{
		write (1, &s[i], 1);
		i++;
		(*a)++;
	}
}

void	ft_pointer_address(unsigned long n, int fd, int *a)
{
	if (n == 0)
	{
		write (1, "(nil)", 5);
		(*a) += 5;
		return ;
	}
	write(1, "0x", 2);
	(*a) += 2;
	ft_putnbr_hex_lower_fd((unsigned long)n, fd, a);
}
