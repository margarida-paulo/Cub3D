/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:20:55 by plashkar          #+#    #+#             */
/*   Updated: 2023/04/24 17:24:14 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	write (fd, "\n", 1);
}

/*int main(void)
{
	int fd = STDOUT_FILENO; // Standard output file descriptor

	char s1[] = "Hello darkness my old friend";
	char s2[] = "Ive come to talk with you again";
	char s3[] = "Because a vision softly creeping";
	// Test the function with a few different characters
		ft_putendl_fd(s1, fd);

		ft_putendl_fd(s2, fd);
		ft_putendl_fd(s3, fd);
	return (0);
}*/
