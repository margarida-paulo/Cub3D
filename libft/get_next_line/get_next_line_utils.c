/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:16:00 by mvalerio          #+#    #+#             */
/*   Updated: 2023/09/14 10:41:46 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_empty_buffer(char *buffer, size_t *i)
{
	size_t	a;

	a = 0;
	while (a <= BUFFER_SIZE && buffer)
		buffer[a++] = 0;
	*i = 0;
}

char	*ft_strjoin_nl(char *line, char *buffer, size_t *i)
{
	char	*final;
	size_t	a;
	size_t	b;

	a = 0;
	b = 0;
	final = malloc(sizeof(char) * ft_strlen(line) + ft_strlen(buffer) + 1);
	if (!final)
		return (NULL);
	while (line && line[a])
		final[b++] = line[a++];
	a = 0;
	while (buffer && buffer[a] && buffer[a] != '\n')
		final[b++] = buffer[a++];
	if (buffer && buffer[a] == '\n')
	{
		final[b++] = '\n';
		*i += a + 1;
	}
	else
		*i = 0;
	final[b] = '\0';
	if (line)
		free (line);
	return (final);
}
