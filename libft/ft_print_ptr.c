/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:48:56 by plashkar          #+#    #+#             */
/*   Updated: 2023/07/20 17:34:05 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	digitcnt_ptr(unsigned long long num)
{
	int	digitcnt;

	digitcnt = 0;
	while (num != 0)
	{
		num = num / 16;
		digitcnt++;
	}
	return (digitcnt);
}

void	put_ptr_number(unsigned long long n)
{
	char	c;

	if (n >= 16)
	{
		put_ptr_number(n / 16);
		put_ptr_number(n % 16);
	}
	else
	{
		if (n <= 9)
			c = n + '0';
		else
		{
			c = n - 10 + 'a';
		}
		write(1, &c, 1);
	}
}

int	ft_print_ptr(unsigned long long ptr)
{
	if (!ptr)
		return (write(1, "(nil)", 5));
	write (1, "0x", 2);
	put_ptr_number(ptr);
	return (digitcnt_ptr(ptr) + 2);
}
