/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plashkar <plashkar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 15:57:22 by plashkar          #+#    #+#             */
/*   Updated: 2023/05/02 15:19:53 by plashkar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);
	node->next = NULL;
	node->content = content;
	return (node);
}

/*int	main(void)
{
	int		*data;
	t_list	*node;

	data = malloc(sizeof(*data));
	if (!data)
		return (0);
	*data = 69;
	node = ft_lstnew(data);
	printf("The content in node is = %d\n", *(int *)(node -> content));
	free (node);
	free (data);
	return (0);
}*/
