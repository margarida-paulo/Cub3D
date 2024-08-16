/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:57:36 by plashkar          #+#    #+#             */
/*   Updated: 2023/04/24 17:20:08 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write (fd, s, 1);
		s++;
	}
}

/*int main(void)
{
	int fd = STDOUT_FILENO; // Standard output file descriptor

	char s1[] = "Hello darkness my old friend";
	char s2[] = "Ive come to talk with you again";
	char s3[] = "Because a vision softly creeping";
	// Test the function with a few different characters
		ft_putstr_fd(s1, fd);
	write (1, "\n", 1);
		ft_putstr_fd(s2, fd);
	write (1, "\n", 1);
		ft_putstr_fd(s3, fd);
	write (1, "\n", 1);
	return (0);
}*/
