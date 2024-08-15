/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:46:42 by mvalerio          #+#    #+#             */
/*   Updated: 2024/05/06 20:08:46 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	a;
	int	res;

	i = 0;
	a = 1;
	res = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
	{
		a = -1;
		i++;
	}
	else if (nptr[i] == '+')
	{
		a = 1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + nptr[i] - 48;
		i++;
	}
	return (res * a);
}

/**
 * If the input is too large to fit in a long,
 * this function will return LONG_MAX or LONG_MIN depending on the sign.
 * but also will print an error to the stdout.
 * @param str: the input string.
 * @param sign: the sign of the number.
 * @return LONG_MAX or LONG_MIN depending on the sign.
*/
long	ft_l_overflow_err(const char *str, int sign)
{
	ft_printf("overflow warning for input:%s\n", str);
	if (sign == 1)
		return (LONG_MAX);
	else
		return (LONG_MIN);
}

/**
 * If the input is too large to fit in a long long,
 * this function will return LONG_MAX or LONG_MIN depending on the sign.
 * however it doesn't print an error message.
 * @param str: the input string.
 * @param sign: the sign of the number.
 * @return LONG_MAX or LONG_MIN depending on the sign.
*/
long long	ft_ll_overflow_err_no_msg(const char *str, int sign)
{
	(void)str;
	if (sign == 1)
		return (LONG_MAX);
	else
		return (LONG_MIN);
}

long	ft_atol(const char *str)
{
	int		sign;
	long	value;
	long	i;

	i = 0;
	value = 0;
	sign = 1;
	while (str[i] != '\0')
	{
		while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
			i++;
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i++] == '-')
				sign = sign * -1;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			if (value > (LONG_MAX - (str[i] - '0')) / 10)
				return (ft_l_overflow_err(str, sign));
			value = value * 10 + (str[i++] - '0');
		}
		break ;
	}
	return (value * sign);
}

long long	ft_atoll(const char *str)
{
	int			sign;
	long long	value;
	long long	i;

	i = 0;
	value = 0;
	sign = 1;
	while (str[i] != '\0')
	{
		while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
			i++;
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i++] == '-')
				sign = sign * -1;
		}
		while (str[i] >= '0' && str[i] <= '9')
		{
			if (value > (LLONG_MAX - (str[i] - '0')) / 10)
				return (ft_ll_overflow_err_no_msg(str, sign));
			value = value * 10 + (str[i++] - '0');
		}
		break ;
	}
	return (value * sign);
}
