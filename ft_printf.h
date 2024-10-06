/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemyden <ydemyden@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:37:31 by ydemyden          #+#    #+#             */
/*   Updated: 2024/10/06 18:15:13 by ydemyden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

void	print_char(char c, int *l);
void	print_str(char *s, int *l);
void	print_ptr(size_t ptr, int *l);
void	print_deci(long nmb, int *l);
void	print_unsigned_deci(unsigned long n, int *l);
void	print_hexadeci(unsigned int n, int *l, char z);
int		ft_printf(const char *str, ...);

#endif