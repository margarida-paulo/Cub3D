/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 18:26:23 by plashkar          #+#    #+#             */
/*   Updated: 2023/10/03 15:56:50 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*strjoined;

	strjoined = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!strjoined)
		return (NULL);
	ft_strlcpy(strjoined, s1, (ft_strlen(s1) + 1));
	ft_strlcat(strjoined, s2, ((ft_strlen(s2) + ft_strlen(s1)) + 1));
	return (strjoined);
}

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	int		len_s1;
// 	int		len_s2;
// 	char	*s3;
// 	int		i;

// 	if (s2 == NULL)
// 		return (NULL);
// 	i = 0;
// 	len_s1 = ft_strlen(s1);
// 	len_s2 = ft_strlen(s2);
// 	s3 = (char *)malloc(len_s1 + len_s2 + 1);
// 	if (s3 == NULL)
// 		return (NULL);
// 	while (i < len_s1 || i < len_s2)
// 	{
// 		if (i < len_s1)
// 			s3[i] = s1[i];
// 		if (i < len_s2)
// 			s3[i + len_s1] = s2[i];
// 		i++;
// 	}
// 	s3[len_s1 + len_s2] = '\0';
// 	return (s3);
// }

/*int	main(void)
{
	char s1[] = "If you want to join the Peoples Front of Judea, ";
	char s2[] = "you have to really hate the Romans.";
	printf("%s", ft_strjoin(s1, s2));
	return(0);
}*/
