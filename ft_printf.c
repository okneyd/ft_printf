/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemyden <ydemyden@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:38:55 by ydemyden          #+#    #+#             */
/*   Updated: 2024/10/05 18:38:20 by ydemyden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printchar(char c, int *l)
{
	write (1, &c, 1);
	(*l)++;
}

void	printstr(char *s, int *l)
{
	while (*s)
		printchar(*s++, l);
}

void	printptr(size_t ptr, int *l)
{
	int		i;
	char	*hexa;
	char	str[17];

	i = 0;
	hexa = "0123456789abcdef";
	if (ptr == 0)
	{
		printstr("NULL", l);
		return ;
	}
	printstr("0x", l);
	while (ptr)
	{
		str[i] = hexa[ptr % 16];
		ptr = ptr / 16;
		i++;
	}
	while (i > 0)
	{
		printchar(str[i - 1], l);
		i--;
	}
}

void	format_check(char x, va_list *args, int *l, int *i)
{
	if (x == 'c')
		printchar(va_arg(*args, int), l);
	else if (x == 's')
		printstr(va_arg(*args, char *), l);
	else if (x == 'p')
		printptr(va_arg(*args, size_t), l);
	else if (x == 'd' || x == 'i')
		printdeci(va_arg(*args, int), l);
	else if (x == 'u')
		print_unsigned_deci(va_arg(*args, unsigned int), l);
	// else if (x == 'x')
	// else if (x == 'X')
	// else if (x == '%')
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		l;
	va_list	args;

	i = 0;
	l = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			format_check(str[i], &args, &l, &i);
			i++;
		}
		else
		{
			printchar(str[i], &l);
		}
	}
	va_end(args);
	return (l);
}

// int	main(void)
// {
// 	// ft_printf("%c", 'b');
// 	// ft_printf("%s", "\njdk\n");

// 	int z = -89656;
// 	// ft_printf("%p", &z);
// 	// ft_printf("%d", z);
// 	// ft_printf("%i", z);
// 	// ft_printf("%u", z);
// 	return (0);
// }