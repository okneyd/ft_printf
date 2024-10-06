/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmb_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemyden <ydemyden@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:14:07 by ydemyden          #+#    #+#             */
/*   Updated: 2024/10/06 18:14:48 by ydemyden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_deci(long nmb, int *l)
{
	if (nmb < 0)
	{
		print_char('-', l);
		nmb = -nmb;
		print_deci(nmb, l);
	}
	else if (nmb > 9)
	{
		print_deci(nmb / 10, l);
		print_deci(nmb % 10, l);
	}
	else
		print_char(nmb + '0', l);
}

void	print_unsigned_deci(unsigned long n, int *l)
{
	if (n >= 10)
		print_unsigned_deci(n / 10, l);
	print_char(n % 10 + '0', l);
}

void	print_hexadeci(unsigned int n, int *l, char h)
{
	int		i;
	char	*hexa;
	char	str[17];

	if (!n)
	{
		print_char('0', l);
		return ;
	}
	if (h == 'x')
		hexa = "0123456789abcdef";
	if (h == 'X')
		hexa = "0123456789ABCDEF";
	i = 0;
	while (n)
	{
		str[i] = hexa[n % 16];
		n = n / 16;
		i++;
	}
	while (i > 0)
	{
		print_char(str[i - 1], l);
		i--;
	}
}
