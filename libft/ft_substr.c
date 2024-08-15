/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:33:22 by mvalerio          #+#    #+#             */
/*   Updated: 2023/04/19 11:34:53 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	qty;

	if (start >= ft_strlen(s))
	{
		substr = (char *) malloc(sizeof(char) * 1);
		*substr = '\0';
		return (substr);
	}
	qty = 0;
	while (s[start + qty] != '\0' && qty < len)
		qty++;
	substr = (char *) malloc(sizeof(*s) * (qty + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
