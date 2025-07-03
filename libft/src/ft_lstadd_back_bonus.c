/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjuszko <kjuszko@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 17:45:43 by kjuszko           #+#    #+#             */
/*   Updated: 2024/09/24 14:16:07 by kjuszko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Adds the node ’new’ at the end of the list.
 *
 * @param lst pointer to first node of list.
 * @param new node to add at end of list.
 */

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*back;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		back = ft_lstlast(*lst);
		back->next = new;
	}
}
