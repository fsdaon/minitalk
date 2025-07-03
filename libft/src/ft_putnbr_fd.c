/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjuszko <kjuszko@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 20:34:43 by kjuszko           #+#    #+#             */
/*   Updated: 2024/09/24 15:19:26 by kjuszko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr_fd(nb / 10, fd);
	}
	ft_putchar_fd((nb % 10) + '0', fd);
}

/* #include <fcntl.h>

int	main(void)
{
	int	fd;

	// Open a file for writing
	fd = open("test_output.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}

	ft_putnbr_fd(42, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(-42, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(0, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(123456789, fd);
	ft_putchar_fd('\n', fd);
	ft_putnbr_fd(-123456789, fd);
	ft_putchar_fd('\n', fd);
	// Close the file
	close(fd);
	return (0);
} */
