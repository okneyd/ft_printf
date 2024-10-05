/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nmb_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemyden <ydemyden@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 18:14:07 by ydemyden          #+#    #+#             */
/*   Updated: 2024/10/05 18:38:36 by ydemyden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printdeci(int nmb, int *l)
{
	if (nmb < 0)
	{
		printchar('-', l);
		nmb = -nmb;
		printdeci(nmb, l);
	}
	else if (nmb > 9)
	{
		printdeci(nmb / 10, l);
		printdeci(nmb % 10, l);
	}
	else
		printchar(nmb + '0', l);
}

void	print_unsigned_deci(unsigned int n, int *l)
{
	if (n >= 10)
		print_unsigned_deci(n / 10, l);
	printchar(n % 10 + '0', l);
}
