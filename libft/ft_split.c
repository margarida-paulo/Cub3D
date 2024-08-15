/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:57:52 by mvalerio          #+#    #+#             */
/*   Updated: 2023/04/20 13:41:45 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_countwords(char const *string, char delimiter)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	if (string[i] && string[i] != delimiter)
	{
		words++;
		i++;
	}
	while (string[i])
	{
		if (string[i] == delimiter && string[i + 1] != \
			delimiter && string[i + 1] != '\0')
			words++;
		i++;
	}
	return (words);
}

size_t	ft_countletters(char const *string, char delimiter)
{
	size_t	i;

	i = 0;
	while (string[i] && string[i] != (const char) delimiter)
	{
		i++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**final;
	size_t	i;
	size_t	a;

	final = (char **) malloc(sizeof(char *) * (ft_countwords(s, c) + 1));
	if (!final)
		return (NULL);
	i = 0;
	a = 0;
	while (i < ft_countwords(s, c))
	{
		while (s[a] == (const char)c)
			a++;
		final[i] = ft_substr(s, a, ft_countletters(&s[a], c));
		a = a + ft_countletters(&s[a], c);
		i++;
	}
	final[ft_countwords(s, c)] = 0;
	return (final);
}
