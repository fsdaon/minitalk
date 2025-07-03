/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjuszko <kjuszko@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 15:08:05 by kjuszko           #+#    #+#             */
/*   Updated: 2025/06/25 15:14:31 by kjuszko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "../libft/libft.h"


static void handle_signal(int signum)
{
	static unsigned char c = 0;
	static int bits = 0;

	c = c << 1;
	if (signum == SIGUSR2)
		c = c | 1;
	bits++;

	if (bits == 8)
	{
		if (c == '\0')
			write(1, "\n", 1);
		else
			write(1, &c, 1);
		bits = 0;
		c = 0;
	}
}

int main(void)
{
	struct sigaction sa;

	ft_printf("PID: %d\n", getpid());

	sa.sa_handler = handle_signal;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	while (1)
		pause();

	return 0;
}
