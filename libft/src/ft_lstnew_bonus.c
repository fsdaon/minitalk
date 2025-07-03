/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjuszko <kjuszko@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:04:13 by kjuszko           #+#    #+#             */
/*   Updated: 2024/09/20 16:40:20 by kjuszko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

/* int	main(void)
{
	char *content = "le epic string";
	t_list *node = ft_lstnew(content);

	if (node)
	{
		printf("Node content: %s\n", (char *)node->content);
		free(node);
	}
	else
	{
		printf("Memory allocation failed\n");
	}

	return (0);
} */
