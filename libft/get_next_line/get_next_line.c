/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 20:29:47 by maggie            #+#    #+#             */
/*   Updated: 2024/05/01 19:02:48 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char		buffer[BUFFER_SIZE + 1];
	static size_t	i = 0;
	char			*line;

	line = 0;
	if (read(fd, 0, 0) < 0)
	{
		ft_empty_buffer(buffer, &i);
		return (NULL);
	}
	while (buffer[i] || read(fd, buffer, BUFFER_SIZE) > 0)
	{
		line = ft_strjoin_nl(line, &(buffer[i]), &i);
		if (i > 0)
		{
			if (!(buffer[i]))
				ft_empty_buffer(buffer, &i);
			return (line);
		}
		ft_empty_buffer(buffer, &i);
	}
	return (line);
}

/* #include <fcntl.h>
#include<stdio.h>

int	main()
{
	int		fd = open("read_error.txt", O_RDONLY);
	char	*line = NULL;
	while ((line = get_next_line(fd)))
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}  */
