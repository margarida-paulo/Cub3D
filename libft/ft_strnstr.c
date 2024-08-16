/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:36:49 by plashkar          #+#    #+#             */
/*   Updated: 2023/04/20 18:52:30 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i] != '\0' && len > 0)
	{
		if (big[i] == little[0] && len >= ft_strlen(little))
		{
			k = i;
			j = 0;
			while (big[k] == little[j] && little[j] != '\0' && big[k] != '\0')
			{
				k++;
				j++;
			}
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		i++;
		len--;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <string.h>

int main(void)
{
	char	big[] = "We apologize again for the fault in the subtitles. Those
	responsible for sacking the people who have just been sacked have been sacked.";
	char	little[] = "Those responsible for sacking the people";
	printf("OG ft: %s\n", strnstr(big, little, 10));
	printf("my ft: %s\n", ft_strnstr(big, little, 10));
	return(0);
}*/
