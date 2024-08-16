/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 16:49:10 by plashkar          #+#    #+#             */
/*   Updated: 2023/07/20 17:53:24 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//to count the digit of the number in any base

int	digitcnt_base(unsigned int num, unsigned int base)
{
	int	digitcnt;
	int	sign;

	sign = 0;
	digitcnt = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num = num / base;
		digitcnt++;
	}
	return (digitcnt + sign);
}

//to print a hexodecimal number

int	ft_print_hex(unsigned int n, char format)
{
	put_number_base(n, 16, format);
	return (digitcnt_base(n, 16));
}

//to print a percent sign

int	ft_print_percent_sign(void)
{
	write (1, "%", 1);
	return (1);
}
