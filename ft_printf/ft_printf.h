/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglinski <aglinski@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:00:25 by aglinski          #+#    #+#             */
/*   Updated: 2024/04/12 18:00:26 by aglinski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stddef.h> /* para va_start, va_arg, va_copy, va_end
(standart arguments) */

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbr(int n);
int		ft_putinbr(unsigned int n);
int		ft_putnbr_base(unsigned long n, char *base, int res);
int		ft_hex_pointer(unsigned long point);
int		ft_print_format(char format, va_list arg);
int		ft_format(const char *format, va_list arg, int *i);
int		ft_printf(const char *format, ...);

#endif
