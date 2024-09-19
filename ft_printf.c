/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemyden <ydemyden@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:38:55 by ydemyden          #+#    #+#             */
/*   Updated: 2024/09/19 17:54:14 by ydemyden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	format_check(char s, va_list *args, int *l)
{
	if (s == 'c')
		putchar(va_arg(*args, int), l);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	int	l;
	va_list	args;

	i = 0;
	l = 0;
	va_start(args, count);
	while (str[i])
	{
		if (str[i] == '%'; i++)
		{
			format_check();
		}
	}
	va_end(args);
	return(l);
}
