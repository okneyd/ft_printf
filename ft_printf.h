/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ydemyden <ydemyden@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:37:31 by ydemyden          #+#    #+#             */
/*   Updated: 2024/09/28 18:23:55 by ydemyden         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
// # include <stdarg.h>

void	ft_putchar(char c, int *l);
void	ft_putstr(char *s, int *l);
int		ft_printf(const char *str, ...);

#endif