/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:34:00 by plashkar          #+#    #+#             */
/*   Updated: 2023/09/07 15:19:16 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	wordcnt(const char *s, char delimit)
{
	int	wrdcnt;
	int	i;

	i = 0;
	wrdcnt = 0;
	while (s[i] != '\0')
	{
		if (s[i] != delimit && (s[i + 1] == delimit || s[i + 1] == '\0'))
			wrdcnt++;
		i++;
	}
	return (wrdcnt);
}

int	lettercnt(const char *s, char delimit, int i)
{
	int	ltcnt;

	ltcnt = 0;
	while (s[i] != delimit && s[i] != '\0')
	{
		if (s[i] != delimit && (s[i + 1] == delimit || s[i + 1] == '\0'))
			break ;
		i++;
		ltcnt++;
	}
	return (ltcnt + 1);
}

char	**freecntsubstr(char **substring)
{
	int	i;

	i = 0;
	while (substring[i] != NULL)
	{
		free(substring[i]);
		i++;
	}
	free(substring);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		a;
	int		start;

	a = 0;
	start = 0;
	result = malloc(sizeof(char *) * (wordcnt(s, c) + 1));
	if (!result)
		return (NULL);
	while (s[start] != '\0')
	{
		if (s[start] == c)
		{
			start++;
			continue ;
		}
		result[a] = ft_substr(s, start, lettercnt(s, c, start));
		if (result[a] == NULL)
			return (freecntsubstr(result));
		start = start + lettercnt(s, c, start);
		a++;
	}
	result[a] = NULL;
	return (result);
}

/*int main (void)
{
	int i = 0;
	char str1[] = "Abc,sdt,sffg,,,h,";
	//char str2[] = "almocar,imhungry,abc";
	char **arrstr = ft_split(str1, ',');
	if (!arrstr)
		return (1);
	while (arrstr[i] != NULL)
	{
		printf("%s\n", arrstr[i]);
		i++;
	}
	free (arrstr);
	return (0);
}*/
