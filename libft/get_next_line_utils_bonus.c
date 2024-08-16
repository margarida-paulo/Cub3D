/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 21:19:30 by plashkar          #+#    #+#             */
/*   Updated: 2023/09/07 18:21:32 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//creates a new_line and adds what was previously stored in line.
//then it adds what was in the buffer until a \n appears.

char	*ft_strjoin_nl(char *line, char *buffer)
{
	char	*new_line;
	int		cnt1;
	int		cnt2;

	cnt1 = 0;
	cnt2 = 0;
	if (buffer[0] == 0)
		return (0);
	new_line = malloc(sizeof(char) * (ft_strlen(line) + ft_strlen(buffer) + 1));
	if (!new_line)
		return (NULL);
	while (line && line[cnt1])
	{
		new_line[cnt1] = line[cnt1];
		cnt1++;
	}
	while (buffer && buffer[cnt2] && buffer[cnt2] != '\n')
		new_line[cnt1++] = buffer[cnt2++];
	if (buffer[cnt2] == '\n')
		new_line[cnt1++] = '\n';
	new_line[cnt1] = '\0';
	if (line)
		free (line);
	return (new_line);
}

//checks for a \n in the buffer, if so sets check to true.
//after that it moves everything that is after \n to the start of the buffer
//then it sets the remaining memory as zeros

int	ft_is_new_line(char *buffer)
{
	size_t	i;
	size_t	j;
	int		check;

	i = 0;
	j = 0;
	check = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
		{
			check = 1;
			i++;
			break ;
		}
		i++;
	}
	while (buffer[i])
		buffer[j++] = buffer[i++];
	while (j < i)
		buffer[j++] = 0;
	return (check);
}
