/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemyden <ydemyden@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:38:55 by ydemyden          #+#    #+#             */
/*   Updated: 2024/10/08 17:25:14 by ydemyden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char(char c, int *l)
{
	write (1, &c, 1);
	(*l)++;
}

void	print_str(char *s, int *l)
{
	if (!s)
	{
		print_str("(null)", l);
		return ;
	}
	while (*s)
		print_char(*s++, l);
}

void	print_ptr(size_t ptr, int *l)
{
	int		i;
	char	*hexa;
	char	str[17];

	hexa = "0123456789abcdef";
	if (!ptr)
	{
		print_str("(nil)", l);
		return ;
	}
	print_str("0x", l);
	i = 0;
	while (ptr)
	{
		str[i] = hexa[ptr % 16];
		ptr = ptr / 16;
		i++;
	}
	while (i > 0)
	{
		print_char(str[i - 1], l);
		i--;
	}
}

void	format_check(char x, va_list *args, int *l)
{
	if (x == 'c')
		print_char(va_arg(*args, int), l);
	else if (x == 's')
		print_str(va_arg(*args, char *), l);
	else if (x == 'p')
		print_ptr((size_t)va_arg(*args, void *), l);
	else if (x == 'd' || x == 'i')
		print_deci(va_arg(*args, int), l);
	else if (x == 'u')
		print_unsigned_deci(va_arg(*args, unsigned int), l);
	else if (x == 'x')
		print_hexadeci(va_arg(*args, unsigned int), l, 'x');
	else if (x == 'X')
		print_hexadeci(va_arg(*args, unsigned int), l, 'X');
	else if (x == '%')
		print_char('%', l);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		l;
	va_list	args;

	i = 0;
	l = 0;
	va_start(args, str);
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			format_check(str[i], &args, &l);
		}
		else
		{
			print_char(str[i], &l);
		}
		i++;
	}
	va_end(args);
	return (l);
}

// int	main(void)
// {
// 	ft_printf(NULL);
// // 	ft_printf("%c\n", 'b');
// // 	ft_printf("%s\n", "jdk");

// // 	int z = -100;
// // 	ft_printf("%p\n", &z);
// // 	ft_printf("%d\n", z);
// // 	ft_printf("%i\n", z);
// // 	ft_printf("%u\n", z);
// // 	ft_printf("%x\n", z);
// // 	ft_printf("%X\n", z);
// // 	ft_printf("%%");
// // 	return (0);
// }
// int	main(void)
// {
// 	int	i;

// 	i = 0;
// // 	// i = ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%
// // %X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%%%%c%%%s%%%d%%%i%%%u%%%x%%%X%
// // %%% %c%%", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,
// // -42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
// // 	i = ft_printf(" %% ");
// // 	ft_printf("%d", i);
// 	// i = printf("ORIGINAL : NULL %s NULL\n", NULL);
// 	// printf("%d\n", i);
// 	i = ft_printf("FT : NULL %s NULL \n", NULL);
// 	ft_printf("%d\n", i);
// 	return (0);
// }