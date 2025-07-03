/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjuszko <kjuszko@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 14:53:48 by kjuszko           #+#    #+#             */
/*   Updated: 2024/12/18 15:13:14 by kjuszko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * iterates through list applying f to each node, makes new list, deletes
 * @param lst address of a pointer to a node.
 * @param f   address of function used to iterate on the list.
 * @param del address of function used to delete the content of a node if needed.
 * @return    new list or NULL if alloc fails.
 */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*node;
	void	*replace;

	list = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		replace = f(lst->content);
		node = ft_lstnew(replace);
		if (!node)
		{
			del(replace);
			ft_lstclear(&list, del);
			return (NULL);
		}
		ft_lstadd_back(&list, node);
		lst = lst->next;
	}
	return (list);
}
