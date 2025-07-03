/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjuszko <kjuszko@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 13:49:51 by kjuszko           #+#    #+#             */
/*   Updated: 2024/09/24 15:29:52 by kjuszko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	slen;

	slen = ft_strlen(src);
	if (size != 0)
	{
		while (*src && size-- > 1)
			*dst++ = *src++;
		*dst = '\0';
	}
	return (slen);
}

/* int	main(void)
{
	const char s[10] = "abcdef";
	char d[4];
	printf("%s\n", s);
	printf("String it tried to create len: %zu\n", strlcpy(d, s, sizeof(d)));
	printf("%s\n", s);

} */
