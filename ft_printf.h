/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemyden <ydemyden@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:37:31 by ydemyden          #+#    #+#             */
/*   Updated: 2024/10/05 18:21:00 by ydemyden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
// # include <stdarg.h>

void	printchar(char c, int *l);
void	printtstr(char *s, int *l);
void	printptr(size_t ptr, int *l);
void	printdeci(int nmb, int *l);
void	print_unsigned_deci(unsigned int n, int *l);
int		ft_printf(const char *str, ...);

#endif