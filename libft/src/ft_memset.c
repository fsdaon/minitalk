/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjuszko <kjuszko@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:25:41 by kjuszko           #+#    #+#             */
/*   Updated: 2024/09/24 15:17:26 by kjuszko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * The  memset()  function  fills  the  first  n  bytes of the memory area
 * pointed to by s with the constant byte c.
 *
 * @param s buffer to write to
 * @param c data to fill the buffer with
 * @param n amount of bytes to fill
 * @return stuff
 */

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*tmp;

	tmp = s;
	while (n--)
		*tmp++ = (unsigned char)c;
	return (s);
}
