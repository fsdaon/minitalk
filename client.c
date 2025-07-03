/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjuszko <kjuszko@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 15:08:09 by kjuszko           #+#    #+#             */
/*   Updated: 2025/06/25 13:02:37 by kjuszko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <signal.h>

static void	char_to_bit(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c & (1 << i))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		i--;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid <= 0)
		{
			ft_printf("PID invalid.\n");
			return (1);
		}
	}
	else
	{
		ft_printf("Use: %s <PID> <Message>\n", av[0]);
		return (1);
	}
	i = 0;
	while (av[2][i])
	{
		char_to_bit(pid, av[2][i]);
		i++;
	}
	char_to_bit(pid, '\0');
	return (0);
}
