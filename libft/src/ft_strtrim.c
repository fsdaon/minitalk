/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjuszko <kjuszko@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 15:59:47 by kjuszko           #+#    #+#             */
/*   Updated: 2024/09/14 14:35:58 by kjuszko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	b;
	size_t	e;

	b = 0;
	e = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (s1[b] && ft_strchr(set, s1[b]))
		b++;
	while (ft_strrchr(set, s1[e - 1]) && e > b)
		e--;
	str = malloc(e - b + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s1[b], e - b + 1);
	return (str);
}
