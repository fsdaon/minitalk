/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjuszko <kjuszko@student.42vienna.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:30:19 by kjuszko           #+#    #+#             */
/*   Updated: 2024/10/23 14:36:45 by kjuszko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static int	pperc(va_list args)
{
	(void)args;
	write(1, "%", 1);
	return (1);
}

static int	detect(char **format, va_list args)
{
	int	ret;

	ret = 0;
	if (**format == 'c')
		ret += pchar(args);
	if (**format == 's')
		ret += pstr(args);
	if (**format == 'p')
		ret += pptr(args);
	if (**format == 'i' || **format == 'd')
		ret += pint(args);
	if (**format == 'u')
		ret += puint(args);
	if (**format == 'x')
		ret += phex(args);
	if (**format == 'X')
		ret += phexb(args);
	if (**format == '%')
		ret += pperc(args);
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;

	ret = 0;
	va_start(args, format);
	if (!format)
		return (-1);
	while (*format)
	{
		if (*format == '%' && *(format + 1))
		{
			format++;
			ret += detect((char **)&format, args);
		}
		else
		{
			write(1, format, 1);
			ret++;
		}
		format++;
	}
	va_end(args);
	return (ret);
}

/* #include <limits.h>
#include <stdio.h>

int	main(void)
{
	char	*ptr;

	ptr = NULL;
	printf("Original printf: Return: %d\n", printf(NULL));
	ft_printf("My ft_printf   : Return: %d\n", ft_printf(NULL));
	printf("==================================================\n");

	printf("Original printf: Return: %d\n", printf(""));
	ft_printf("My ft_printf   : Return: %d\n", ft_printf(""));
	printf("==================================================\n");

	printf("Original printf: Return: %d\n", printf("Hello, World!\n"));
	ft_printf("My ft_printf   : Return: %d\n", ft_printf("Hello, World!\n"));
	printf("==================================================\n");

	printf("Original printf: Return: %d\n", printf("%d\n", 123));
	ft_printf("My ft_printf   : Return: %d\n", ft_printf("%d\n", 123));
	printf("==================================================\n");

	printf("Original printf: Return: %d\n", printf("%d\n", -456));
	ft_printf("My ft_printf   : Return: %d\n", ft_printf("%d\n", -456));
	printf("==================================================\n");

	printf("Original printf: Return: %d\n", printf("%c\n", 'A'));
	ft_printf("My ft_printf   : Return: %d\n", ft_printf("%c\n", 'A'));
	printf("==================================================\n");

	printf("Original printf: Return: %d\n", printf("%s\n", "Test string"));
	ft_printf("My ft_printf   : Return: %d\n", ft_printf("%s\n", "Test string"));
	printf("==================================================\n");

	int x = 789;
	printf("Original printf: Return: %d\n", printf("%p\n", (void*)&x));
	ft_printf("My ft_printf   : Return: %d\n", ft_printf("%p\n", (void*)&x));
	printf("==================================================\n");

	printf("Original printf: Return: %d\n", printf("%u\n", 987));
	ft_printf("My ft_printf   : Return: %d\n", ft_printf("%u\n", 987));
	printf("==================================================\n");

	printf("Original printf: Return: %d\n", printf("%x\n", 654));
	ft_printf("My ft_printf   : Return: %d\n", ft_printf("%x\n", 654));
	printf("==================================================\n");

	printf("Original printf: Return: %d\n", printf("%X\n", -321));
	ft_printf("My ft_printf   : Return: %d\n", ft_printf("%X\n", -321));
	printf("==================================================\n");

	printf("Original printf: Return: %d\n", printf("%%\n"));
	ft_printf("My ft_printf   : Return: %d\n", ft_printf("%%\n"));
	printf("==================================================\n");

	printf("Original printf: Return: %d\n", printf("%d\n", 2147483647));
	ft_printf("My ft_printf   : Return: %d\n", ft_printf("%d\n", 2147483647));
	printf("==================================================\n");

	printf("Original printf: Return: %d\n", printf("%u\n", 4294967295U));
	ft_printf("My ft_printf   : Return: %d\n", ft_printf("%u\n", 4294967295U));
	printf("==================================================\n");

	printf("Original printf: Return: %d\n", printf("%d\n", 0));
	ft_printf("My ft_printf   : Return: %d\n", ft_printf("%d\n", 0));
	printf("==================================================\n");

	printf("Original printf: Return: %d\n",
	printf("Int: %d, Char: %c, String: %s\n", 123, 'A', "Test"));
	ft_printf("My ft_printf   : Return: %d\n",
	ft_printf("Int: %d, Char: %c, String: %s\n", 123, 'A', "Test"));
	printf("==================================================\n");

	printf("Original printf: Return: %d\n", printf("%%\n"));
	ft_printf("My ft_printf   : Return: %d\n", ft_printf("%%\n"));
	printf("==================================================\n");

	printf("Original printf: Return: %d\n", printf("%%%%\n"));
	ft_printf("My ft_printf   : Return: %d\n", ft_printf("%%%%\n"));
	printf("==================================================\n");

	printf("Original printf: Return: %d\n", printf("%d %d %d\n", 1, 2, 3));
	ft_printf("My ft_printf   : Return: %d\n", ft_printf("%d %d %d\n", 1, 2, 3));
	printf("==================================================\n");

	printf("Original printf: Return: %d\n",
	printf("%c %c %c\n", 'A', 'B', 'C'));
	ft_printf("My ft_printf   : Return: %d\n",
	ft_printf("%c %c %c\n", 'A', 'B', 'C'));
	printf("==================================================\n");

	printf("Original printf: Return: %d\n",
	printf("%s %s %s\n", "one", "two", "three"));
	ft_printf("My ft_printf   : Return: %d\n",
	ft_printf("%s %s %s\n", "one", "two", "three"));
	printf("==================================================\n");

	printf("Original printf: Return: %d\n",
	printf("Int: %d, Char: %c, String: %s, Hex: %x\n", 42, 'A', "Test", 255));
	ft_printf("My ft_printf   : Return: %d\n",
	ft_printf("Int: %d, Char: %c, String: %s, Hex: %x\n", 42, 'A', "Test", 255));
	printf("==================================================\n");

	printf("Original printf: Return: %d\n", printf("%d\n", INT_MIN));
	ft_printf("My ft_printf   : Return: %d\n", ft_printf("%d\n", INT_MIN));
	printf("==================================================\n");

 	// printf("Original printf: Return: %d\n", printf("%s\n", NULL));
	// ft_printf("My ft_printf   : Return: %d\n", ft_printf("%s\n", NULL));
	// printf("==================================================\n");

	return 0;
} */
