/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjuszko <kjuszko@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 15:19:52 by kjuszko           #+#    #+#             */
/*   Updated: 2024/09/24 15:25:19 by kjuszko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}
/*
char	*ft_strchr(const char *s, int c)
{
	if (*s == c)
		return ((char *)s);
	if (*s == '\0')
		return (NULL);
	return (ft_strchr(s + 1, c));
} */
/*
int	main(void)
{
	const char str[] = "find the letter L\n";
	printf("%s", str);
	printf("%s", ft_strchr(str, '\0'));
	return (0);
} */
