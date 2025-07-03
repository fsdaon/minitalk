/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjuszko <kjuszko@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 16:16:01 by kjuszko           #+#    #+#             */
/*   Updated: 2024/09/24 15:12:35 by kjuszko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (!dest && !src)
		return (NULL);
	while (n--)
		*d++ = *s++;
	return (dest);
}
/* int main()
{
 	char s[10] = "abcdefg";
	char d[10];
	printf("%s", (char *)ft_memcpy((void *)(NULL), (void *)(NULL), 3));
} */
