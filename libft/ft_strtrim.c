/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 19:09:27 by plashkar          #+#    #+#             */
/*   Updated: 2023/04/21 15:35:55 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_checkinlist(char s, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	ends1;
	size_t	i;

	start = 0;
	ends1 = ft_strlen(s1) - 1;
	i = 0;
	while (s1[i] != '\0')
	{
		if (ft_checkinlist(s1[i], set) == 0)
		{
			start = i;
			break ;
		}
		i++;
	}
	while (ft_checkinlist(s1[ends1], set) == 1)
		ends1--;
	return (ft_substr(s1, start, (ends1 - start + 1)));
}

int	ft_checkinlist(char s, char const *set)
{
	size_t	j;

	j = 0;
	while (set[j] != '\0')
	{
		if (set[j] == s)
			return (1);
		j++;
	}
	return (0);
}

/*int	main(void)
{
	char	s1[] = "WaaaaaaabcccHellobbbccb";
	char	set[] = "abc";
	printf("the original string is: %s\n", s1);
	printf("the trimmed sting is: %s\n", ft_strtrim(s1, set));
	return (0);
}*/
