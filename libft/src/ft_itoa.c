/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjuszko <kjuszko@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 14:19:44 by kjuszko           #+#    #+#             */
/*   Updated: 2024/09/24 14:09:33 by kjuszko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	itoalen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		len;

	nb = n;
	len = itoalen(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	else if (nb == 0)
		str[0] = '0';
	while (nb > 0)
	{
		str[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}

/* void	run_test(int n, const char *expected)
{
	char	*result;

	result = ft_itoa(n);
	if (strcmp(result, expected) == 0)
	{
		printf("Test passed for input %d: %s\n", n, result);
	}
	else
	{
		printf("Test failed for input %d: expected %s, got %s\n", n, expected,
				result);
	}
	free(result);
}

int	main(void)
{
	// Test cases
	run_test(0, "0");
	run_test(123, "123");
	run_test(-123, "-123");
	run_test(2147483647, "2147483647");
	run_test(-2147483648, "-2147483648");
	return (0);
} */
