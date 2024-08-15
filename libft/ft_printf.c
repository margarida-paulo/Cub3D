/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maggie <maggie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 17:42:07 by mvalerio          #+#    #+#             */
/*   Updated: 2023/06/08 21:40:57 by maggie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* size_t count(const char *str)
{
    size_t  i;
    size_t  count;

    i = 0;
    while(str[i])
    {
        if (str[i] == '%')
        {
            count++;
            i++;
        }
        i++;
    }
    return (count);
}*/

void	ft_putnbr_hex_lower_fd(unsigned long n, int fd, int *a)
{
	if (n / 16 > 0)
		ft_putnbr_hex_lower_fd(n / 16, fd, a);
	if (n % 16 <= 9)
	{
		ft_putchar_fd('0' + (n % 16), 1);
		(*a)++;
	}
	if (n % 16 > 9)
	{
		ft_putchar_fd('a' - 10 + n % 16, 1);
		(*a)++;
	}
}

void	ft_putnbr_hex_upper_fd(unsigned long n, int fd, int *a)
{
	if (n / 16 > 0)
		ft_putnbr_hex_upper_fd(n / 16, fd, a);
	if (n % 16 <= 9)
	{
		ft_putchar_fd('0' + (n % 16), 1);
		(*a)++;
	}
	if (n % 16 > 9)
	{
		ft_putchar_fd('A' - 10 + n % 16, 1);
		(*a)++;
	}
}

void	ft_putnbr_unsigned_fd(unsigned long n, int fd, int *a)
{
	if (n >= 10)
	{
		ft_putnbr_unsigned_fd(n / 10, fd, a);
		n = n % 10;
	}
	if (n < 10)
	{
		ft_putchar_fd('0' + n, fd);
		(*a)++;
	}
}

void	ft_formater(size_t *i, const char *string, int *printed, va_list *list)
{
	(*i)++;
	if (string[*i] == 'c')
	{
		ft_putchar_fd(va_arg(*list, int), 1);
		(*printed)++;
	}
	if (string[*i] == 's')
		ft_putstr_printed(va_arg(*list, char *), printed);
	if (string[*i] == 'd' || string[*i] == 'i')
		ft_putnbr_printed(va_arg(*list, int), printed);
	if (string[*i] == 'u')
		ft_putnbr_unsigned_fd(va_arg(*list, unsigned int), 1, printed);
	if (string[*i] == 'x')
		ft_putnbr_hex_lower_fd(va_arg(*list, unsigned int), 1, printed);
	if (string[*i] == 'X')
		ft_putnbr_hex_upper_fd(va_arg(*list, unsigned int), 1, printed);
	if (string[*i] == '%')
	{
		ft_putchar_fd('%', 1);
		(*printed)++;
	}
	if (string[*i] == 'p')
		ft_pointer_address(va_arg(*list, unsigned long), 1, printed);
}

int	ft_printf(const char *string, ...)
{
	size_t	i;
	int		printed;
	va_list	list;

	va_start(list, string);
	i = 0;
	printed = 0;
	while (string[i])
	{
		if (string[i] == '%')
		{
			ft_formater(&i, string, &printed, &list);
		}
		else
		{
			ft_putchar_fd(string[i], 1);
			printed++;
		}
		i++;
	}
	return (printed);
}
