/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjuszko <kjuszko@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 14:39:31 by kjuszko           #+#    #+#             */
/*   Updated: 2024/09/24 15:22:22 by kjuszko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer. */

static int	count(char const *s, char c)
{
	int	t;
	int	i;

	t = 0;
	i = 0;
	while (*s)
	{
		if (*s == c)
			t = 0;
		else if (!t && (*s != c))
		{
			t = 1;
			i++;
		}
		s++;
	}
	return (i);
}

static void	splitfree(int r, char **strs)
{
	while (r-- > 0)
		free(strs[r]);
	free(strs);
}

static int	splithelper(char const *s, char c, char **strs, int i)
{
	int	r;
	int	b;

	r = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		b = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > b)
		{
			strs[r] = ft_substr(s, b, i - b);
			if (!strs[r])
			{
				splitfree(r, strs);
				return (0);
			}
			r++;
		}
	}
	strs[r] = NULL;
	return (42);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;

	i = 0;
	strs = malloc((count(s, c) + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	if (!splithelper(s, c, strs, i))
		return (NULL);
	return (strs);
}
