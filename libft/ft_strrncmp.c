/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrncmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 13:11:12 by plashkar          #+#    #+#             */
/*   Updated: 2023/10/18 12:39:18 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strrncmp(const char *s1, const char *s2, size_t n)
{
	size_t	ln1;
	size_t	ln2;

	ln1 = ft_strlen(s1);
	ln2 = ft_strlen(s2);
	if (n == 0 || ln1 < n || ln2 < n)
		return (0);
	ln1 = ln1 - n;
	ln2 = ln2 - n;
	while (n > 0 && s1[ln1] != '\0' && s2[ln2] != '\0' && s1[ln1] == s2[ln2])
	{
		ln1++;
		ln2++;
		n--;
	}
	if (n == 0 || (s1[ln1] == '\0' && s2[ln2] == '\0'))
		return (0);
	else
		return ((unsigned char)s1[ln1] - (unsigned char)s2[ln2]);
}
