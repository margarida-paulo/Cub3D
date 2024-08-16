/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:24:29 by plashkar          #+#    #+#             */
/*   Updated: 2023/04/26 12:22:05 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (n == -2147483648)
	{
		write (fd, "-2", 2);
		n = 147483648;
	}
	if (n < 0 && n != -2147483648)
	{
		n = n * -1;
		write (fd, "-", 1);
	}
	if (n >= 0 && n <= 9)
	{
		c = n + '0';
	}
	if (n >= 10)
	{
		c = (n % 10) + '0';
		n = n / 10;
		ft_putnbr_fd(n, fd);
	}
	write(fd, &c, 1);
}

/*int	main (void)
{
		ft_putnbr_fd(5, 2);
	write (1, "\n", 1);
		ft_putnbr_fd(-7, 2);
	write (1, "\n", 1);
		ft_putnbr_fd(0, 2);
	write (1, "\n", 1);
		ft_putnbr_fd(2147483647, 2);
	write (1, "\n", 1);
		ft_putnbr_fd(-2147483648, 2);
	write (1, "\n", 1);
		ft_putnbr_fd(-21, 2);
	write (1, "\n", 1);
		ft_putnbr_fd(798, 2);
	write (1, "\n", 1);
}*/
