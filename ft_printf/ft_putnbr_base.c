/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aglinski <aglinski@student.42madrid.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 18:01:39 by aglinski          #+#    #+#             */
/*   Updated: 2024/04/12 18:01:42 by aglinski         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned long n, char *base, int res)
{
	unsigned long	len_base;

	len_base = 0;
	while (base[len_base])
		len_base++;
	if (n < len_base)
	{
		if (ft_putchar(base[n]) == -1)
			return (-1);
		return (res + 1);
	}
	else
	{
		res = ft_putnbr_base(n / len_base, base, res);
		if (res == -1)
			return (-1);
		if (ft_putchar(base[n % len_base]) == -1)
			return (-1);
		return (res + 1);
	}
}

/* ft_putnbr_base se deiseñada para imprimir un numero en una base
1. res + 1 es para tener en cuenta el nuevo caracter que se va 
a imprimir en la llamada actual
2. res = ft_putnbr_base(n / len_base, res, base) - se uiliza
para llevar un conteo acumulativo del numero de caracteres
impresos haste el momento, esto nos permite mantener un seguimiento
precioso del numero total de caracteres impresos
*/