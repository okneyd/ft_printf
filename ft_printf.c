/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemyden <ydemyden@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:38:55 by ydemyden          #+#    #+#             */
/*   Updated: 2024/09/25 19:33:30 by ydemyden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *l)
{
	write (1, &c, 1);
	(*l)++;
}

void	format_check(char s, va_list *args, int *l, int *i)
{
	if (s == 'c')
		ft_putchar((char)va_arg(*args, int), l);
}

int	ft_printf(const char *str, ...)
{
	int	i;
	int	l;
	va_list	args;

	i = 0;
	l = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			format_check(str[i],&args, &l, &i);
			i++;
		}
		else
		{
			ft_putchar(str[i], &l);
		}
	}
	va_end(args);
	return(l);
}

int	main(void)
{
	ft_printf("%c", 'a');
	return (0);
}