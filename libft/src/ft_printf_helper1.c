/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helper1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjuszko <kjuszko@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 17:45:15 by kjuszko           #+#    #+#             */
/*   Updated: 2024/10/23 13:29:12 by kjuszko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	pchar(va_list args)
{
	char	c;

	c = (char)va_arg(args, int);
	write(1, &c, 1);
	return (1);
}

int	pstr(va_list args)
{
	char	*str;
	int		i;

	i = 0;
	str = va_arg(args, char *);
	if (!str)
		str = "(null)";
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

static void	putnbr_u(unsigned int n)
{
	char	c;

	if (n >= 10)
		putnbr_u(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

int	puint(va_list args)
{
	unsigned int	n;
	int				i;

	n = va_arg(args, unsigned int);
	i = 0;
	putnbr_u(n);
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	pint(va_list args)
{
	int	i;
	int	n;

	i = 0;
	n = va_arg(args, int);
	ft_putnbr_fd(n, 1);
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}
