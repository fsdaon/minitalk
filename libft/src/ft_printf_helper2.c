/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjuszko <kjuszko@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:51:21 by kjuszko           #+#    #+#             */
/*   Updated: 2024/10/23 13:34:49 by kjuszko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static void	putnbr_hex(uintptr_t hex)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (hex >= 16)
		putnbr_hex(hex / 16);
	write(1, &hexa[hex % 16], 1);
}

static void	putnbr_hexb(uintptr_t hex)
{
	char	*hexa;

	hexa = "0123456789ABCDEF";
	if (hex >= 16)
		putnbr_hexb(hex / 16);
	write(1, &hexa[hex % 16], 1);
}

int	pptr(va_list args)
{
	int			i;
	void		*ptr;
	uintptr_t	hex;

	i = 2;
	ptr = va_arg(args, void *);
	if (!ptr)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	hex = (uintptr_t)ptr;
	write(1, "0x", 2);
	putnbr_hex(hex);
	while (hex)
	{
		hex /= 16;
		i++;
	}
	return (i);
}

int	phex(va_list args)
{
	int				i;
	unsigned int	n;

	i = 0;
	n = va_arg(args, unsigned int);
	putnbr_hex(n);
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}

int	phexb(va_list args)
{
	int				i;
	unsigned int	n;

	i = 0;
	n = va_arg(args, unsigned int);
	putnbr_hexb(n);
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 16;
		i++;
	}
	return (i);
}
