/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjuszko <kjuszko@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 18:07:49 by kjuszko           #+#    #+#             */
/*   Updated: 2024/09/10 14:58:32 by kjuszko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*z1;
	unsigned char	*z2;

	i = 0;
	z1 = (unsigned char *)s1;
	z2 = (unsigned char *)s2;
	while (i < n)
	{
		if (z1[i] != z2[i])
			return (z1[i] - z2[i]);
		i++;
	}
	return (0);
}
/*
int	main(void)
{
	char s1[] = "abcdefg";
	char s2[] = "abcdefg";

	printf("Diff: %d", ft_memcmp(s1, s2, 10));
} */
