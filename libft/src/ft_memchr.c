/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjuszko <kjuszko@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 18:44:08 by kjuszko           #+#    #+#             */
/*   Updated: 2024/09/10 14:59:12 by kjuszko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*str;

	i = 0;
	str = s;
	while (i < n)
	{
		if (str[i] == (unsigned char)c)
			return ((void *)(str + i));
		i++;
	}
	return (NULL);
}
/* DESCRIPTION
       The  memchr()  function  scans  the  initial n bytes of the memory area
       pointed to by s for the first instance of c.  Both c and the  bytes  of
       the memory area pointed to by s are interpreted as unsigned char.

       The  memchr()  and memrchr() functions return a pointer to the matching
       byte or NULL if the character does not occur in the given memory area.
 */

/* int main()
{
	char str[] = "abcdefgf";

	char *res = ft_memchr(str, 'z', 8);
	printf("character found: %s\n", res ? res : "nope");
} */
