/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils0.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 14:59:02 by plashkar          #+#    #+#             */
/*   Updated: 2023/07/20 17:52:52 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//to print a single char

int	ft_printchar(int c)
{
	int	printcnt;

	printcnt = 0;
	ft_putchar_fd(c, 1);
	printcnt++;
	return (printcnt);
}

//to print a number in base 10 that can be positive or negative

int	ft_printnum(int c)
{
	int		printcnt;
	int		i;
	long	b;
	int		sign;

	printcnt = 0;
	sign = 0;
	b = c;
	i = 0;
	ft_putnbr_fd(c, 1);
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
	printcnt = (i + sign);
	return (printcnt);
}

//to print a string

int	ft_printstr(char *str)
{
	int	printcnt;

	printcnt = 0;
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	printcnt = ft_strlen(str);
	return (printcnt);
}

//to print an unsigned decimal number in base ten

int	ft_print_unsigned_dec(unsigned int n)
{
	int				printcnt;
	char			c;
	unsigned int	n2;

	printcnt = 0;
	n2 = n;
	if (n <= 9)
		c = n + '0';
	if (n >= 10)
	{
		c = (n % 10) + '0';
		n = n / 10;
		ft_print_unsigned_dec(n);
	}
	write (1, &c, 1);
	printcnt = digitcnt_base(n2, 10);
	return (printcnt);
}

//to print a number in any base we want, it can not be negative

void	put_number_base(unsigned int n, unsigned int base, char format)
{
	char	c;

	if (n >= base)
	{
		put_number_base(n / base, base, format);
		put_number_base(n % base, base, format);
	}
	else
	{
		if (n <= 9)
			c = n + '0';
		else
		{
			if (format == 'X')
				c = n - 10 + 'A';
			if (format == 'x')
				c = n - 10 + 'a';
		}
		write(1, &c, 1);
	}
}
