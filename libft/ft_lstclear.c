/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maggie <maggie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 12:32:06 by mvalerio          #+#    #+#             */
/*   Updated: 2023/08/11 16:16:43 by maggie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*save;

	if ((*lst) == NULL)
		return ;
	while (*lst)
	{
		save = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = save;
	}
	lst = NULL;
}
